// Unit Area of largest region of 1's

#include<bits/stdc++.h>
using namespace std;
#define SIZE 100

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        cin>>n>>m;
        
        int g[SIZE][SIZE];
        bool vis[SIZE][SIZE];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                cin>>g[i][j];
        }
        
        memset(vis, 0, sizeof(vis));
        
        cout << findAreaUtil(n, m, g, vis) << endl;
      
    }
      
	return 0;
}

int max1(int a, int b)  {  return (a>b) ? a : b;  }

int max(int a, int b, int c, int d, int e, int f, int g, int h)
{
    return max1(max1(max1(a, b), max1(c, d)), max1(max1(e, f), max1(g, h)));
}

int dfs(int n, int m, int i, int j, int g[SIZE][SIZE], bool vis[SIZE][SIZE])
{
    if(i<0 || j<0 || i==n || j==m || !g[i][j] || vis[i][j])  return 0;
    vis[i][j] = true;
    return 1 + dfs(n, m, i-1, j-1, g, vis) + dfs(n, m, i-1, j, g, vis) + 
               dfs(n, m, i-1, j+1, g, vis) + dfs(n, m, i, j-1, g, vis) + 
               dfs(n, m, i, j+1, g, vis) + dfs(n, m, i+1, j-1, g, vis) + 
               dfs(n, m, i+1, j, g, vis) + dfs(n, m, i+1, j+1, g, vis);
}

int findAreaUtil(int n, int m, int g[SIZE][SIZE], bool vis[SIZE][SIZE])
{
    int s=0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(g[i][j] && !vis[i][j])
            {
                int x = dfs(n, m, i, j, g, vis);
                if(x > s)  s = x;
            }
        }
    }
    return s;
}