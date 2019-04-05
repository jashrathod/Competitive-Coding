// MERGING TWO ARRAYS

#include<iostream>
#include<string.h>
#include<stack>
using namespace std;

int main()
{
    int n, m, c=0, d=0;

    cout<<"no. in a: ";
    cin>>n;

    cout<<"values in a: ";
    int a[n];

    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }

    cout<<"no. in b: ";
    cin>>m;

    cout<<"values in b: ";
    int b[m], merge[n+m];

    for(int i=0; i<m; i++)
    {
        cin>>b[i];
    }
    
    for(int i=0; i<n+m; i++)
    {
        if(a[c]<b[d] && a[c]!='\0')
        {
        	merge[i]=a[c];
        	c++;	
        }
        else
        {
        	merge[i]=b[d];
        	d++;
        }
    }
    
    cout<<"merged: ";
    for(int i=0; i<n+m; i++)
    {
        cout<<merge[i]<<" ";
    }
    
    return 0;
}