// NUMBER OF PATHS IN A MATRIX

#include <bits/stdc++.h>
using namespace std;
int m, n;
int path_matrix(int i, int j)
{
    if(i>=m || j>=n)  return 0;
    if(i==m-1 && j==n-1)  return 1;
    return path_matrix(i+1, j) + path_matrix(i, j+1);
}
int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    cin>>m>>n;
	    cout<<path_matrix(0,0)<<endl;
	}
	return 0;
}
