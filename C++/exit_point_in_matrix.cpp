// Exit Point in a Matrix

#include <iostream>
using namespace std;

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
	            cin>>a[i][j];
	    }
	    int i=0, j=0, x=1;
	    while(i>=0 && j>=0 && i<m && j<n)
	    {
	        if(x == 1)
	        {
	            if(a[i][j] == 0)
	            {
	                j++;
	            }
	            else
	            {
	                x = 2;
	                a[i][j] = 0;
	            }
	        }
	        else if(x == 2)
	        {
	            if(a[i][j] == 0)
	            {
	                i++;
	            }
	            else
	            {
	                x = 3;
	                a[i][j] = 0;
	            }
	        }
	        else if(x == 3)
	        {
	            if(a[i][j] == 0)
	            {
	                j--;
	            }
	            else
	            {
	                x = 4;
	                a[i][j] = 0;
	            }
	        }
	        else if(x == 4)
	        {
	            if(a[i][j] == 0)
	            {
	                i--;
	            }
	            else
	            {
	                x = 1;
	                a[i][j] = 0;
	            }
	        }
	    }
	    if(i < 0)  i++;
	    else if(i >= m)  i--;
	    else if(j < 0)  j++;
	    else if(j >= n)  j--;
	    cout<<i<<" "<<j<<endl;
	}
	return 0;
}