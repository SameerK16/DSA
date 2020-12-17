#include<stdio.h>
#include<stdlib.h>
#include "sort.h"

int swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int A[], int l, int h)
{
    int i = 1, j = h, pivot = A[l];

    do
    {
        do{i++;}    while(A[i]<=pivot);
        do{j--;}    while(A[j]>pivot);

        if(i<j)
            swap(&A[i], &A[j]);
    }while(i<j);

    swap(&A[l], &A[j]);
    return j;
}

void QuickSort(int A[], int l , int h)
{
    int j;
    if(l<h)
    {
        j = partition(A, l, h);
        QuickSort(A, l, j);
        QuickSort(A, j+1, h);
    }
}


void BubbleSort(int A[], int n)
{
    int i, j, flag = 0; // flag is to check whether array is already sorted or not, if already sorted then
                        // after 1st pass it will terminate the sorting... stable

    for(i=0; i<n-1; i++)
    {
        for(j=0; j<n-i-1; j++)
        {
            if(A[j] > A[j+1])
            {
                swap(&A[j], &A[j+1]);
                flag = 1;
            }
        }
        if(flag == 0)
            break;
    }
}


void InsertionSort(int A[], int n)
{
    int i, j, x;
    for(i=1; i<n; i++)
    {
        j = i-1;
        x = A[i];
        while(j>0 && A[j] > x)
        {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = x;
    }
}


void SelectionSort(int A[], int n)
{
    int i, j, k;
    for(i=0; i<n; i++)
    {
        for(j=k=i; j<n; j++)
        {
            if(A[j] < A[k])         // if you reverse this condition then it will sort the elements in the descending
                k = j;
        }
        swap(&A[i], &A[k]);
    }
}


void merge2(int A[], int m, int B[], int n)
{
    int i, j, k;
    int C[m+n];

    i = j = k = 0;

    while(i<m && j<n)
    {
        if(A[i] < B[j])
            C[k++] = A[i++];
        else
            C[k++] = B[j++];
    }

    for(; i<m; i++)
        C[k++] = A[i];
    for(; j<n; j++)
        C[k++] = B[j];
}

void merge(int A[], int l, int mid, int h)
{
    int i = l, j = mid+1, k = h;
    int B[100];

    while(i<=mid && j<=h)
    {
        if(A[i]<A[j])
            B[k++] = A[i++];
        else
            B[k++] = A[j++];
    }

    for(; i<=mid; i++)
        B[k++] = A[i];
    for(; j<=h; j++)
        B[k++] = A[j];

    for(i=l;i<=h;i++)
        A[i]=B[i];
}

void IterMergeSort(int A[], int n)
{
    // Iterative Merge Sort
    int p, l, h, mid, i;
    for(p=2; p<=n; p=p*2)
    {
        for(i=0; i+p-1<n; i++)
        {
            l = i;
            h = p + i -1;
            mid = (l+h)/2;
            merge(A, l, mid, h);
        }
        if(n-i>p/2)
        {
            l = i;
            h = i+p-1;
            mid = (l+h)/2;
            merge(A, l, mid, n-1);
        }
        if(p/2<n)
            merge(A,0,(p/2)-1,n-1);
    }
}


void RMergeSort(int A[], int l, int h)
{
    // Recursive Merge Sort
    int mid;
    if(l<h)
    {
        mid=(l+h)/2;
        RMergeSort(A,l,mid);
        RMergeSort(A,mid+1,h);
        merge(A,l,mid,h);
    }
}

int FindMax(int A[], int n)
{
    int max;
    max = A[0];
    for(int i=1; i<n; i++)
        max = (A[i] > max) ? A[i] : max;
    return max;
}


void CountSort(int A[], int n)
{
    int i, j, max, *C;

    max = FindMax(A, n);

    C = (int *)malloc((max+1)*sizeof(int));

    for(i=0; i<max+1; i++)
        C[i] = 0;

    for(int i=0; i<n; i++)
        C[A[i]]++;

    i = j = 0;
    while(j<max+1)
    {
        if(C[j]>0)
        {
            A[i++] = j;
            C[j]--;
        }
        else
            j++;
    }
}
