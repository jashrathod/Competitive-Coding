// Path in Matrix

#include <iostream>
using namespace std;

int max(int a, int b, int c)
{
    if(a>=b && a>=c)  return a;
    else if(b>=a && b>=c)  return b;
    else  return c;
}

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
	    for(int i=0; i<n; i++)
	    {
	        b[0][i] = a[0][i];
	    }
	    for(int i=1; i<n; i++)
	    {
	        for(int j=0; j<n; j++)
	        {
	            if(j>0 && j<n-1) 
	            {
	                b[i][j] = a[i][j] + max(b[i-1][j-1], b[i-1][j], b[i-1][j+1]);
	            }
	            else if(j == 0)
	            {
	                b[i][j] = a[i][j] + max(b[i-1][j], b[i-1][j+1], -1);
	            }
	            else
	            {
	                b[i][j] = a[i][j] + max(b[i-1][j-1], b[i-1][j], -1);
	            }
	        }
	    }
	    int mx = -1;
	    for(int i=0; i<n; i++)
	    {
	        if(mx < b[n-1][i])  mx = b[n-1][i];
	    }
	    cout<<mx<<endl;
	}
	return 0;
}