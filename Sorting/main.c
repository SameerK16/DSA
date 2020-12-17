#include <stdio.h>
#include <stdlib.h>
#include "sort_methods.c"

void check_QuickSort()
{
    int A[] = {1, 4, 2, 7, 3, 9, 5, 65535}, n = 7, i;
    QuickSort(A, 0, n);

    for(i=0; i<n; i++)
        printf("%d ", A[i]);
    printf("\n");
}

void check_BubbleSort()
{
    printf("Bubble Sort:\t");
    // int A[] = {1, 4, 2, 7, 3, 9, 5}, n = 7, i;
    int A[] = {1, 2, 3, 5}, n = 4, i;
    BubbleSort(A, n);

    for(i=0; i<n; i++)
        printf("%d ", A[i]);
    printf("\n");
}

void check_InsertionSort()
{
    printf("Insertion Sort:\t");
    int A[] = {1, 4, 2, 7, 3, 9, 5}, n = 7, i;
    InsertionSort(A, n);

    for(i=0; i<n; i++)
        printf("%d ", A[i]);
    printf("\n");
}

void check_SelectionSort()
{
    printf("Selection Sort:\t");
    int A[] = {1, 4, 2, 7, 3, 9, 5}, n = 7, i;
    SelectionSort(A, n);

    for(i=0; i<n; i++)
        printf("%d ", A[i]);
    printf("\n");
}

void check_IMergeSort()
{
    printf("Merge Sort:\t");
    int A[] = {1, 4, 2, 7, 3, 9, 5}, n = 7, i;
    RMergeSort(A, 0, n);

    for(i=0; i<n; i++)
        printf("%d ", A[i]);
    printf("\n");
}


void check_CountSort()
{
    printf("Count Sort:\t");
    int A[] = {4, 2, 7, 3, 9, 5, 1}, n = 7, i;
    CountSort(A, n);

    for(i=0; i<n; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int main()
{
    check_CountSort();
    return 0;
}
