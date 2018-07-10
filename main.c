#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "sort.h"
#include "utils.h"
#include "heap.h"

static int match(void *ptr1, void *ptr2);

void print_array(int[], int);

int
main(int argc, char **argv)
{

    // list *list = list_create();
    // int a = 5;
    // int b = 4;
    // int c = 3;
    // int d = 2; 
    // int e = 1;
    // int f = 0;

    // int j = 10;
    // list_add_node_tail(list, &a);
    // list_add_node_tail(list, &b);
    // list_add_node_tail(list, &c);
    // list_add_node_tail(list, &d);
    // list_add_node_tail(list, &e);
    // list_add_node_tail(list, &f);

    // list_set_match_method(list, match);

    // list_node *node = list_search_key(list, &f);
    // list_insert_node(list, node, &j, 1);
    // list_del_node(list, node);

    // printf("%ld\n", list_length(list));
    // list_iterator *iter = list_get_iterator(list, AL_START_HEAD);
    // list_node *current;
    // while ((current = list_next(iter))) 
    //     printf("%d ", *((int *)current->data));

    // printf("\n");
//    int RANGE_MAX = 100;
//
//    int len = 21;
//    int a[len];
//    get_random_int_array(a, len, RANGE_MAX);
//     printf("Before sort: ");
//    print_array(a, len);
//    merge_sort(a,0,len-1);
//    printf("After  sort: ");
//    print_array(a, len);

//    int a[] = {16, 4, 10, 14, 7, 9, 3, 2, 8, 1};
    int a[] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};

    int len = 10;
    printf("Before sort: ");
    print_array(a, len);
    heap_sort(a, 10);
    printf("After  sort: ");
    print_array(a, len);
    return EXIT_SUCCESS;
}

int
match(void *ptr1, void *ptr2)
{
    if(*((int*)ptr1) == *((int*)ptr2))
        return 1;
    return 0;
}
