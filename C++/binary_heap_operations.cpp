// Binary Heap Operations

#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

void swap(int *x, int *y) 
{ 
    int temp = *x; 
    *x = *y; 
    *y = temp; 
}

struct MinHeap
{   
    int *harr; 
    int capacity;
    int heap_size;
    
    MinHeap(int c) 
    {     
       heap_size = 0;
       capacity = c;
       harr = new int[c];
    }
    
    ~MinHeap()
    {
        delete[] harr;
    }
    
    int parent(int i) 
    { 
        return (i-1)/2; 
    }
    
    int left(int i) 
    { 
        return (2*i + 1);
    }
    
    int right(int i) 
    { 
        return (2*i + 2);
    }
    
    void MinHeapify(int i)
    {
        int l = left(i);
        int r = right(i);
        int smallest = i;
        if (l < heap_size && harr[l] < harr[i])
            smallest = l;
        if (r < heap_size && harr[r] < harr[smallest])
            smallest = r;
        if (smallest != i)
        {
            swap(harr[i], harr[smallest]);
            MinHeapify(smallest);
        }
    }
    
    int extractMin()
    {
        if (heap_size <= 0) 
            return -1; 
        if (heap_size == 1) 
        { 
            heap_size--; 
            return harr[0]; 
        } 
        int root = harr[0]; 
        harr[0] = harr[heap_size-1]; 
        heap_size--; 
        MinHeapify(0); 
        return root; 
    }

    void decreaseKey(int i, int new_val)
    {
        harr[i] = new_val; 
        while (i != 0 && harr[parent(i)] > harr[i]) 
        { 
        swap(&harr[i], &harr[parent(i)]); 
        i = parent(i); 
        } 
    }
    
    void deleteKey(int i)
    {
        if(i < heap_size)
        {
            decreaseKey(i, INT_MIN); 
            extractMin();
        }
    }

    void insertKey(int k)
    {
        if (heap_size == capacity) 
        { 
            cout << -1; 
            return; 
        }
        heap_size++; 
        int i = heap_size - 1; 
        harr[i] = k; 
        while (i != 0 && harr[parent(i)] > harr[i]) 
        { 
            swap(&harr[i], &harr[parent(i)]); 
            i = parent(i); 
        }
    }
    
};

int main()
{
    int t;
    cin>>t;
    
    while(t--)
    {
        ll a;
        cin>>a;
        MinHeap h(a);
        for(ll i=0; i<a; i++)
        {
            int c;
            int  n;
            cin>>c;
            if(c==1)
            {  
                cin>>n;
                h.insertKey(n);
            }
            if(c==2)
            {  
                cin>>n;
                h.deleteKey(n);
            } 
            if(c==3)
            { 
                cout<<h.extractMin()<<" ";
            }
        
        }
        cout<<endl;
        h.harr=NULL;
    }
    return 0;
}