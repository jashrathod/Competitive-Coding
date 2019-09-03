// Detect cycle in an undirected graph

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int V, E;
        cin>>V>>E;
        
        vector<int> adj[V];
        
        int u, v;
        for(int i=0;i<E;i++)
        {
            cin>>u>>v;
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        cout << isCyclic(adj, V)<<endl;
    }
}

bool dfs(int i, vector<int> arr[], int parent[], bool vis[])
{
    vis[i] = true;
    for(int j=0; j<arr[i].size(); j++)
    {
        if(i == arr[i][j])  
            return true;
        
        if(vis[arr[i][j]] && parent[i] != arr[i][j])
            return true;
        
        if(!vis[arr[i][j]])
        {
            parent[arr[i][j]] = i;
            if(dfs(arr[i][j], arr, parent, vis))  
                return true;
        }
    }
    return false;

}


bool isCyclic(vector<int> adj[], int n)
{
    int parent[n];
    for(int i=0; i<n; i++)  parent[i] = -1;
    
    bool vis[n] = { false };
  
    for(int i=0; i<n; i++)
    {
        if(!vis[i] && dfs(i, adj, parent, vis))  
            return true;
    }
    
    return false;
}