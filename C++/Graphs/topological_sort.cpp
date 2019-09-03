// Topological Sort

#include<bits/stdc++.h>
using namespace std;

bool check(int V, int* res, vector<int> adj[])
{
    bool flag =true;
    for(int i=0; i<V && flag;i++)
    {
        int n=adj[res[i]].size();
        for(auto j : adj[res[i]])
        {
            for(int k=i+1;k<V;k++)
            {
                if(res[k]==j )
                    n--;
            }
        }
        if(n!=0)
            flag =false;
    }
    if(flag==false)
        return 0;
    return 1;
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N,E;
        cin>>E>>N;
        int u,v;
        
        vector<int> adj[N];
        
        for(int i=0;i<E;i++)
        {
            cin>>u>>v;
            adj[u].push_back(v);
        }
    
        int *res = topoSort(N, adj);
        
        cout<<check(N, res, adj)<<endl;
       
    }
}

void topologicalSortUtil(int v, bool visited[], stack<int> &Stack, vector<int> adj[]) 
{ 
    visited[v] = true; 
    
    for (int i=0; i<adj[v].size(); i++) 
    {
        if (!visited[adj[v][i]])  
            topologicalSortUtil(adj[v][i], visited, Stack, adj); 
    }
    
    Stack.push(v); 
}

int* topoSort(int V, vector<int> adj[])
{
    stack<int> Stack; 
    bool *visited = new bool[V]; 
    
    for (int i = 0; i < V; i++) 
        visited[i] = false; 
        
    for (int i = 0; i < V; i++) 
    {
        if (visited[i] == false) 
            topologicalSortUtil(i, visited, Stack, adj); 
    }
    
    int *arr = new int[V];
    
    for(int i=0; i<V; i++)
    {
        arr[i] = Stack.top();
        Stack.pop(); 
    }
    
    return arr; 
}