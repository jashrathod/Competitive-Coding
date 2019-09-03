// Rotate by 90 degree

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
	    int a[n][n], b[n][n];
	    for(int i=0; i<n; i++)
	    {
	        for(int j=0; j<n; j++)
	        {
	            cin>>a[i][j];
	        }
	    }
	    int p = n-1, q=0;
	    for(int i=0 ; i<n; i++)
	    {
	        p=n-1;
	        for(int j=0; j<n; j++)
	        {
	            b[p][i] = a[i][j];
	            p--;
	        }
	    }
	    for(int i=0; i<n; i++)
	    {
	        for(int j=0; j<n; j++)
	        {
	            cout<<b[i][j]<<" ";
	        }
	    }
	    cout<<endl;
	}
	return 0;
}