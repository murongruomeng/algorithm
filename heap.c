//
// Created by amber on 18-7-9.
//
#include <stdio.h>
#include "utils.h"
#include "heap.h"

void
max_heapify(int a[], int i, int size)
{
    int li = (i<<1) + 1;
    int ri = (i<<1) + 2;

    int largest = i;
    if (li <= size-1 && a[i] < a[li]) {
        largest = li;
    }


    if (ri <= size-1 && a[largest] < a[ri]) {
        largest = ri;
    }

    if (i != largest) {
        swap(&a[i], &a[largest]);
        max_heapify(a, largest, size);
    }
}

void
build_max_heap(int a[], int size)
{

    int i, j=(size - 1) >> 1;
    for(i=j; i>=0; i--) {
        max_heapify(a, i, size);
    }
}

void
heap_sort(int a[], int size)
{
    build_max_heap(a, size);
    int i=size-1;
    int heap_size = i;
    for (; i >= 1; i--) {

        swap(&a[i], &a[0]);
        max_heapify(a, 0, heap_size);
        heap_size = i -1;
    }

}