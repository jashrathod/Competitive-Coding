// Activity Selection 

#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int a[n], b[n];
	    
	    for(int i=0; i<n; i++)
	        cin>>a[i];
	    for(int i=0; i<n; i++)
	        cin>>b[i];
	        
	    for(int i=0; i<n-1; i++)
	    {
	        for(int j=i+1; j<n; j++)
	        {
	            if(b[j] < b[i])
	            {
	                swap(&b[j], &b[i]);
	                swap(&a[j], &a[i]);
	            }
	        }
	    }
	    
	    int i=1, count=1, l=0;
	    while(i < n)
	    {
	        if(a[i]>=b[l])
	        {
	            count++;
	            l=i;
	        }
	        i++;
	    }
	    cout<<count<<endl;
	}
	return 0;
}
