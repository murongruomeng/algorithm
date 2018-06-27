
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

void 
get_random_int_array(int a[], int len)
{
    srand(time(NULL));
    int i=0;
    for (;i<len;i++) {
        a[i] = rand()%100;
    }
}

void
print_array(int a[], int len)
{
    int i = 0;
    for(;i<len;i++) {
        printf("%d ", a[i]);
    }

    printf("\n");
}