// Bipartite Graph

#include <bits/stdc++.h>
using namespace std;
const int MAX = 100;
bool isBipartite(int G[][MAX],int V);
int main()
{
    int t;
	cin>>t;
	int g[MAX][MAX];
	while(t--)
	{
		memset(g,0,sizeof (g));
		int n;
		cin>>n;
	
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cin>>g[i][j];
			}
		}
		
		cout<<isBipartite(g,n)<<endl;
	}
	return 0;
}


bool colorGraph(int G[][MAX],int color[],int pos, int c, int V)
{
    if(color[pos] != -1 && color[pos] != c) 
        return false; 
          
    color[pos] = c; 
    bool ans = true; 
    for(int i=0; i<V; i++)
    { 
        if(G[pos][i])
        { 
            if(color[i] == -1) 
                ans &= colorGraph(G, color, i, 1-c, V); 
                  
            if(color[i] != -1 && color[i] != 1-c) 
                return false; 
        } 
        if (!ans) 
            return false; 
    } 
      
    return true; 
}

bool isBipartite(int G[][MAX], int V)
{
    int color[V]; 
    for(int i=0;i<V;i++) 
        color[i] = -1; 
    
    for(int i=0; i<V; i++) 
    {
        if(G[i][i] != 0)
            return false;
    }
    
    int pos = 0; 
    return colorGraph(G, color, pos, 1, V); 
}