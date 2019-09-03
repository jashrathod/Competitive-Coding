// Largest square formed in a matrix

#include <iostream>
using namespace std;

int min(int a, int b, int c)
{
    if(a<=b && a<=c)  return a;
    else if(b<=a && b<=c)  return b;
    else  return c;
}

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    int m, n;
	    cin>>m>>n;
	    int a[m][n];
	    for(int i=0; i<m; i++)
	    {
	        for(int j=0; j<n; j++)
	        {
	            cin>>a[i][j];
	        }
	    }
	    int b[m][n], mx = -1;
	    for(int i=0; i<m; i++)  b[i][0] = a[i][0];
	    for(int j=0; j<n; j++)  b[0][j] = a[0][j];
	    for(int i=1; i<m; i++)
	    {
	        for(int j=1; j<n; j++)
	        {
	            if(a[i][j] == 1)
	                b[i][j] = 1 + min(b[i-1][j], b[i-1][j-1], b[i][j-1]);
	            else
	                b[i][j] = 0;
	        }
	    }
	    for(int i=0; i<m; i++)
	    {
	        for(int j=0; j<n; j++)
	        {
	            if(b[i][j] > mx)  mx = b[i][j];
	        }
	    }
	    cout<<mx<<endl;
	}
	return 0;
}