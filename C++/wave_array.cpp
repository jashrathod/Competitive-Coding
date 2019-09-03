// Wave Array

#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0; i<n; i++)
	    {
	        cin>>a[i];
	    }
	    for(int i=0; i<n; i+=2)
	    {
	        if(i+1 < n)
	        {
	            int t = a[i];
	            a[i] = a[i+1];
	            a[i+1] = t;
	        }
	    }
	    for(int i=0; i<n; i++)
	    {
	        cout<<a[i]<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}