// DFS of a Graph

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N, E;
        cin>>N>>E;
        
        vector<int> g[N];
        bool vis[N];
        
        memset(vis, false, sizeof(vis));
        
        for(int i=0;i<E;i++)
        {
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(0,g,vis);
        
        cout<<endl;
    }
}

void dfs(int s, vector<int> g[], bool vis[])
{
    if(vis[s] == true)  return;
    vis[s] = true;
    cout<<s<<" ";
    for(int i=0; i<g[s].size(); i++)
    {
        dfs(g[s][i], g, vis);
    }
}
