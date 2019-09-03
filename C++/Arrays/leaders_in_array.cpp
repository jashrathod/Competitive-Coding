// Leaders in an array

#include <iostream>
using namespace std;

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int a[n], b[n];
	    for(int i=0; i<n; i++)  cin>>a[i];
	    b[n-1] = a[n-1];
	    for(int i=n-2; i>=0; i--)
	    {
	        if(a[i] >= b[i+1])
	        {
	            b[i] = a[i];
	        }
	        else
	        {
	            b[i] = b[i+1];
	        }
	    }
	    for(int i=0; i<n-1; i++)
	    {
	        if(b[i] == a[i])  cout<<a[i]<<" ";
	    }
	    cout<<b[n-1]<<endl;
	}
	return 0;
}