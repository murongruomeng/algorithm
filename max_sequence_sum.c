#include <stdlib.h>
#include <stdio.h>

int max_sub_sequence_sum1(const int[], int);
int max_sub_sequence_sum2(const int[], int);
int max_sub_sequence_sum3(const int[], int);
static int max_sub_sum(const int[], int, int);
static int max_sub_mid(const int[], int, int, int);

int
main(int argc,char **argv)
{
    
   int a[] = {4, -3, 5, -2, -1, 2, 6, -2};
    // int a[] = {1, 2, -10, 4, 5};
   int m = max_sub_sequence_sum3(a, 8);
   printf("max sequence sum is: %d\n", m);
   return EXIT_SUCCESS; 
}

int
max_sub_sequence_sum1(const int a[], int n)
{
    int i, j, sum =0, temp;
    for(i=0; i<n; i++) {
        temp = a[i];
        for(j=i+1; j<n; j++) {
            temp += a[j];
            if (temp > sum) {
                sum = temp;
            }
        }
    }
    return sum;
}

int
max_sub_sequence_sum2(const int a[], int n)
{
    return max_sub_sum(a, 0, n-1);
}

static int
max_sub_sum(const int a[], int left, int right)
{
    int left_sum, middle_sum, right_sum;
    int middle;
    if (left == right) {
        return a[left];
    }
    
    middle = (left + right)/2;
    left_sum = max_sub_sum(a, left, middle);
    right_sum = max_sub_sum(a, middle + 1, right);
    middle_sum = max_sub_mid(a, left, middle, right);
    if (left_sum >= right_sum && left_sum >= middle_sum)
        return left_sum;
    if (right_sum >= left_sum && right_sum >= middle_sum)
        return right_sum;    
    return middle_sum;
}

static int 
max_sub_mid(const int a[], int left, int middle ,int right)
{
    int left_max_sum=0, right_max_sum=0, temp = 0;
    int i, j;

    if (middle == right)
        return a[middle];

    for (i=middle;i>=left;i--) {
        temp += a[i];
        if(temp >= left_max_sum) 
            left_max_sum = temp;
    }

    temp = 0;
    for (i=middle+1;i<=right;i++) {
        temp += a[i];
        if(temp >= right_max_sum)
            right_max_sum = temp;
    }

    return left_max_sum + right_max_sum;
}

int
max_sub_sequence_sum3(const int a[], int n)
{
    int max_sum=0, current_sum=0, i = 0;
    for (;i<n;i++) {
        current_sum += a[i];
        if (current_sum >= max_sum){
            max_sum = current_sum ;
        } else if(current_sum < 0) {
            current_sum = 0;
        }
    }

    return max_sum;
}