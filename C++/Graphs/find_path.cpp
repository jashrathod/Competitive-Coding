// Find whether path exists

#include <iostream>
using namespace std;

bool path(int a[20][20], bool b[20][20], int n, int i, int j)
{
    if(i<0 || j<0 || i==n || j==n || a[i][j] == 0 || b[i][j])  return false;
    if(a[i][j] == 2)  return true;
    b[i][j] = true;
    if(path(a, b, n, i+1, j) | path(a, b, n, i, j+1) | path(a, b, n, i, j-1) | path(a, b, n, i-1, j))  
        return true;
    return false;
}

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n, p=0, q=0;
	    cin>>n;
	    int a[20][20];
	    bool b[20][20];
	    for(int i=0; i<n; i++)
	    {
	        for(int j=0; j<n; j++)
	        {
	            cin>>a[i][j];
	            b[i][j] = false;
	            if(a[i][j] == 1) 
	            {
	                p = i;
	                q = j;
	            }
	        }
	    }
	    bool ispath = path(a, b, n, p, q);
	    if(ispath)  cout<<1;
	    else  cout<<0;
	    cout<<endl;
	}
	return 0;
}