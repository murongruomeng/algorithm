#include <stdlib.h>
#include "list.h"

list*
list_create()
{
    struct list *list;
    if ((list = malloc(sizeof(struct list))) == NULL)
        return NULL;

    list->head = list->tail = NULL;
    list->len = 0;
    list->dup = NULL;
    list->match = NULL;
    list->free = NULL;
    return list;
}

void
list_release(list *list) 
{
    list_empty(list);
    free(list);
}

void
list_empty(list *list)
{
    unsigned long len;
    list_node *current, *next;
    current = list->head;
    len = list->len;
    while(len--) {
        next = current->next;
        if (list->free)
            list->free(current->data);
        free(current);
        current = next;
    }

    list->head = list->tail = NULL;
    list->len = 0;
}

list*
list_add_node_head(list *list, void *data)
{
    list_node *node;
    if ((node = malloc(sizeof(struct list_node))) == NULL)
        return NULL;
    node->data = data;
    if (list->len == 0) {
        list->head = list->tail = node;
        node->prev = node->next = NULL;
    } else {
        list->head->prev = node;
        node->next = list->head;
        node->prev = NULL;
        list->head = node;
    }

    list->len ++;
    return list;
}

list*
list_add_node_tail(list *list, void *data)
{
    list_node *node;
    if ((node = malloc(sizeof(struct list_node))) == NULL)
        return NULL;
    node->data = data;
    if (list->len == 0) {
        list->head = list->tail = node;
        node->prev = node->next = NULL;
    } else {
        node->next = NULL;
        node->prev = list->tail;
        list->tail->next = node;
        list->tail = node;
    }

    list->len ++;
    return list;
}

list*
list_insert_node(list *list, list_node *old_node, void *data, int after)
{
    list_node *node;
    if ((node = malloc(sizeof(struct list_node))) == NULL)
        return NULL;
    node->data = data;
    if (after) {
        node->prev = old_node;
        node->next = old_node->next;
        if (list->tail == old_node) {
            list->tail = node;
        } 
    } else {
        node->next = old_node;
        node->prev = old_node->prev;
        if (list->head == old_node) {
            list->head = node;
        }
    }

    if (node->prev != NULL) {
        node->prev->next = node;
    }

    if (node->next != NULL) {
        node->next->prev = node;
    }

    list->len++;
    return list;
}

void 
list_del_node(list *list, list_node *node)
{
    if (node->prev)
        node->prev->next = node->next;
    else 
        list->head = node->next;
    
    if (node->next)
        node->next->prev = node->prev;
    else
        list->tail = node->prev;

    if (list->free)
        list->free(node->data);
    free(node);
    list->len--;
}



list_iterator*
list_get_iterator(list *list, int direction)
{
    list_iterator *iter;
    if ((iter = malloc(sizeof(struct list_iterator))) == NULL)
        return NULL;
    
    if (direction == AL_START_HEAD)
        iter->next = list->head;
    else 
        iter->next = list->tail;

    iter->direction = direction;
    return iter;
}

list_node *
list_next(list_iterator *iter)
{
    list_node *current = iter->next;
    if (current != NULL) {
        if (iter->direction == AL_START_HEAD)
            iter->next = current->next;
        else
            iter->next = current->prev;
    }

    return current;
}


list_node*
list_search_key(list *list, void *key)
{
    list_iterator iter;
    list_node *node;

    list_rewind(list, &iter);
    while((node = list_next(&iter)) != NULL) {
        if (list->match) {
            if (list->match(node->data, key)) {
                return node;
            }
        } else {
            if (key == node->data) {
                return node;
            }
        }
    }

    return NULL;
}


void 
list_rewind(list *list, list_iterator *iter)
{
    iter->next = list->head;
    iter->direction = AL_START_HEAD;
}
void 
list_rewind_tail(list *list, list_iterator *iter)
{
    iter->next = list->tail;
    iter->direction = AL_START_TAIL;
}
