// Mergesort

#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int l, int m, int r)
{
    int left[m-l+1], right[r-m];
    for(int i=0; i<m-l+1; i++)  left[i] = arr[l+i];
    for(int i=0; i<r-m; i++)  right[i] = arr[m+i+1];
    int k=l, i=0, j=0;
    while(i < m-l+1 && j < r-m)
    {
        if(left[i] < right[j])
        {
            arr[k++] = left[i++];
        }
        else
        {
            arr[k++] = right[j++];
        }
    }
    while(j < r-m)
    {
        arr[k++] = right[j++];
    }
    while(i < m-l+1)
    {
        arr[k++] = left[i++];
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l+(r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int arr[1000],n,T,i;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d",&arr[i]);
        mergeSort(arr, 0, n-1);
        printArray(arr, n);
    }
    return 0;
}