// Detect cycle in a directed graph

#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int v, e;
	    cin >> v >> e;
	    
	    vector<int> adj[v];
	    
	    for(int i =0;i<e;i++){
	        int u, v;
	        cin >> u >> v;
	        adj[u].push_back(v);
	    }
	    
	    cout << isCyclic(v, adj) << endl;
	    
	}
	
	return 0;
}

bool fn(vector<int> adj[], int i, bool vis[], bool temp[])
{
    vis[i] = true;
    temp[i] = true;
    for(int j=0; j<adj[i].size(); j++)
    {
        if(!vis[adj[i][j]] && fn(adj, adj[i][j], vis, temp))
            return true;
        else if (temp[adj[i][j]]) 
            return true; 
    }
    temp[i] = false;
    return false;
}

bool isCyclic(int V, vector<int> adj[])
{
    bool vis[V] = { false };
    bool temp[V] = { false };
    
    for(int i=0; i<V; i++)
    {
        if(fn(adj, i, vis, temp))  
            return true;
    }
    return false;
}