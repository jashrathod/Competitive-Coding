// X Total Shapes

#include <iostream>
using namespace std;

void shapes(char a[50][50], bool vis[50][50], int m, int n, int i, int j)
{
    if(i<0 || j<0 || i==m || j==n || vis[i][j] || a[i][j]=='O')  return;
    vis[i][j] = true;
    shapes(a, vis, m, n, i+1, j);
    shapes(a, vis, m, n, i-1, j);
    shapes(a, vis, m, n, i, j+1);
    shapes(a, vis, m, n, i, j-1);
}

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    int m, n;
	    cin>>m>>n;
	    char a[50][50];
	    bool vis[50][50];
	    for(int i=0; i<m; i++)
	    {
	        string s;
	        cin>>s;
	        for(int j=0; j<n; j++)
	        {
	            a[i][j] = s[j];
	            vis[i][j] = false;
	        }
	    }
	    int c=0;
	    for(int i=0; i<m; i++)
	    {
	        for(int j=0; j<n; j++)
	        {
	            if(!vis[i][j] && a[i][j] == 'X')
	            {
	                shapes(a, vis, m, n, i, j);
	                c++;
	            }
	        }
	    }
	    cout<<c<<endl;
	}
	return 0;
}