// Implementing Dijkstra's Algorithm

#include<bits/stdc++.h>
using namespace std;
void dijkstra(vector<vector<int>> , int ,int );
int main()
{
    int t;
    int V;
    cin>>t;
    while(t--){
        cin>>V;
        
        vector<vector<int>> g(V);
        
        for(int i = 0;i<V;i++){
            vector<int> temp(V);
            g[i] = temp;
        }
        
        for(int i=0;i<V;i++)
        {
      	    for(int j=0;j<V;j++)
      	    {
      		    cin>>g[i][j];
      	    }
        }
        
        int s;
        cin>>s;
        
        dijkstra(g, s, V);
        cout<<endl;
       }
        return 0;
}

int min_index(int *v, int n, bool *visited)
{   
    int min=INT_MAX;
    int min_vertex;
    for(int i=0; i<n; i++)
    {
        if(v[i]<min && visited[i]==false)
        {
            min=v[i];
            min_vertex = i;
        }
    }
    return min_vertex;
}

void dijkstra(vector<vector<int>> graph, int src, int V)
{
    bool visited[V] = { false };
    int weights[V];
    weights[src]=0;
    
    for(int i=0; i<V; i++)
    {   
        if(i != src)
            weights[i] = INT_MAX;
    }
    
    for(int i=0; i<V; i++)
    {
        int min_vertex = min_index(weights, V, visited);
        visited[min_vertex]=true;
        for(int i=0; i<V; i++)
        {
            if(graph[min_vertex][i]>=1 && visited[i]==false)
            {
                if(graph[min_vertex][i] + weights[min_vertex] < weights[i])
                {
                    weights[i] = graph[min_vertex][i] + weights[min_vertex];
                } 
            }
        }
    }
    
    for(int i=0;i<V;i++)
        cout << weights[i] << " ";
}