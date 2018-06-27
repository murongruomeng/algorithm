#include <stdio.h>
#include "sort.h"
#include "utils.h"

void 
insertion_sort(int a[], int p, int q)
{
    int i,key,j;
    if(p > q)
        return;
    
    for (i = p + 1; i <= q; i++) {
        key = a[i];
        j = i-1;
        while(j >= p && a[j] >= key) {
            a[j+1] = a[j];
            j--;
        }

        a[j+1] = key;
    } 
}

static void
merge(int a[], int p, int q, int r)
{
    if(p >= r)
        return;
    
    int llen = q - p + 1;
    int rlen = r - q;
    int la[llen];
    int ra[rlen];
    int i,j,k;
    for(i=0;i<llen;i++) {
        la[i] = a[p + i];
    }

    for(j=0;j<rlen;j++) {
        ra[j] = a[q + j + 1];
    }

    i=0;
    j=0;
    for(k=p; k<=r; k++) {
        if (i<llen && j<rlen && la[i] > ra[j]) {
            a[k] = ra[j];
            j++;
        } else if(i<llen) {
            a[k] = la[i];
            i++;
        }
    }

}

void 
merge_sort(int a[], int p, int q)
{
   if (p >= q)
        return;
    int r = (p + q) / 2;
    merge_sort(a,p,r);
    merge_sort(a,r+1,q);
    merge(a, p,r,q);
}