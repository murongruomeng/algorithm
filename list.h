#ifndef __LIST_H__
#define __LIST_H__


typedef struct list_node {
    struct list_node *prev;
    struct list_node *next;
    void *data;
} list_node;

typedef struct list_iterator {
    list_node *next;
    int direction;
} list_iterator;

typedef struct list {
    list_node *head;
    list_node *tail;
    void (*dup)(void *ptr);
    void (*free)(void *ptr);
    int (*match)(void *ptr, void *key);
    unsigned long len;
} list;

/* Functions implementd as macros */
#define list_length(l) ((l)->len)
#define list_first(l) ((l)->head)
#define list_last(l) ((l)->tail)
#define list_prev_node(n) ((n)->prev)
#define list_next_node(n) ((n)->next)
#define list_node_value(n) ((n)->data)

#define list_set_dup_method(l,m) ((l)->dup = (m))
#define list_set_free_method(l,m) ((l)->free = (m))
#define list_set_match_method(l,m) ((l)->match = (m))

#define list_get_dup_method(l) ((l)->dup)
#define list_get_free_method(l) ((l)->free)
#define list_get_match_method(l) ((l)->match)


list *list_create(void);
void list_release(list *list);
void list_empty(list *list);
list *list_add_node_head(list *list, void *data);
list *list_add_node_tail(list *list, void *valdataue);
list *list_insert_node(list *list, list_node *old_node, void *data, int after);
void list_del_node(list *list, list_node *node);

list_iterator *list_get_iterator(list *list, int direction);
list_node *list_next(list_iterator *iter);

list_node *list_search_key(list *list, void *data);

void list_rewind(list *list, list_iterator *iter);
void list_rewind_tail(list *list, list_iterator *iter);

#define AL_START_HEAD  0
#define AL_START_TAIL  1

#endif