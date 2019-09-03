// BFS of a Graph

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
        vector<int> adj[N];
        bool vis[N];
        for(int i=0;i<E;i++)
        {
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
        }
        
        bfs(0, adj, vis);
        cout<<endl;
    }
}

void bfs(int s, vector<int> adj[], bool vis[])
{
    queue<int> q;
    q.push(s);
    vis[s] = true;
    while(!q.empty())
    {
        for(int i=0; i<adj[q.front()].size(); i++)
        {
            if(vis[adj[q.front()][i]] == false)
            {
                q.push(adj[q.front()][i]);
                vis[adj[q.front()][i]] = true;
            }
        }
        cout<<q.front()<<" ";
        q.pop();
    }
}