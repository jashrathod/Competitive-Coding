// Search in a Matrix 

// Recursive 

#include <iostream>
using namespace std;

int mat(int a[30][30], int n, int m, int i, int j, int v)
{
    if(i>n || j>m || i<0 || j<0)  return 0;
    else if(a[i][j] == v)  return 1;
    else if(i == n-1)  return mat(a, n, m, i, j+1, v);
    else if(j == m-1)  return mat(a, n, m, i+1, j, v);
    return (mat(a, n, m, i+1, j, v) | mat(a, n, m, i, j+1, v));
}

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n, m, v;
	    cin>>n>>m;
	    int a[30][30];
	    for(int i=0; i<n; i++)
	    {
	        for(int j=0; j<m; j++)
	        {
	            cin>>a[i][j];
	        }
	    }
	    cin>>v;
	    cout<<mat(a, n, m, 0, 0, v)<<endl;
	}
	return 0;
}

// Efficient

#include <iostream>
using namespace std;

int mat(int a[30][30], int n, int m, int i, int j, int v)
{
    while(i<n && j<m && i>=0 && j>=0)
    {
        if(v < a[i][j])  j--;
        else if(v > a[i][j])  i++;
        else if(v == a[i][j])  return 1;
    }
    return 0;
}

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n, m, v;
	    cin>>n>>m;
	    int a[30][30];
	    for(int i=0; i<n; i++)
	    {
	        for(int j=0; j<m; j++)
	        {
	            cin>>a[i][j];
	        }
	    }
	    cin>>v;
	    cout<<mat(a, n, m, 0, m-1, v)<<endl;
	}
	return 0;
}