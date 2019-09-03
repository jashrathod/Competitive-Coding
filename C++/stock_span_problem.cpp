// Stock Span Problem

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
	    int a[n+1];
	    a[0] = 801;
	    for(int i=1; i<=n; i++)  cin>>a[i];
	    for(int i=1; i<=n; i++)
	    {
	        for(int j=i-1; j>=0; j--)
	        {
	            if(a[i] < a[j])
	            {
	                cout<<i-j<<" ";
	                break;
	            }
	        }
	    }
	    cout<<endl;
	}
	return 0;
}