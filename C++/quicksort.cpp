// Quicksort

#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

int partition (int arr[], int low, int high)
{
    int key = arr[high], i=low, j=low-1;
    for(int i=low; i<high; i++)
    {
        if(arr[i] < key)
        {
            j++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    j++;
    int temp = arr[high];
    arr[high] = arr[j];
    arr[j] = temp;
    return j;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
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
        for(i=0;i<n;i++)  scanf("%d",&arr[i]);
        quickSort(arr, 0, n-1);
        printArray(arr, n);
    }
    return 0;
}