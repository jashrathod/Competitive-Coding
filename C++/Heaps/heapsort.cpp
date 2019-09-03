// Heapsort

#include <bits/stdc++.h>
using namespace std;

void heapify(int arr[], int n, int i)  
{
    int largest = i; 
    int l = 2*i + 1; 
    int r = 2*i + 2; 
  
    if (l < n && arr[l] > arr[largest]) 
        largest = l; 
  
    if (r < n && arr[r] > arr[largest]) 
        largest = r; 
  
    if (largest != i) 
    { 
        int t = arr[i];
        arr[i] = arr[largest];
        arr[largest] = t;
        heapify(arr, n, largest); 
    }
}

void buildHeap(int arr[], int n)  
{ 
    for(int i=1; i<n; i++)
    {
        int j=i;
        while(j > 0 && arr[(j-1)/2] < arr[j])
        {
            int t = arr[j];
            arr[j] = arr[(j-1)/2];
            arr[(j-1)/2] = t;
            j = (j-1)/2;
        }
    }
}

void heapSort(int arr[], int n)
{
    buildHeap(arr, n);
    for (int i=n-1; i>=0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
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
    int arr[1000000],n,T,i;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d",&arr[i]);
        heapSort(arr, n);
        printArray(arr, n);
    }
    return 0;
}