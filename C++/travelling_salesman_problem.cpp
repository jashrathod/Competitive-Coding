// Travelling Salesman Problem

#include<bits/stdc++.h>
using namespace std;

int tsp(int mask, int pos, int dist[12][12], int n)
{   int visited_all = (1<<n)-1;
    if(mask == visited_all)  return dist[pos][0];
    
    int ans=INT_MAX;
    for(int city=0; city<n; city++)
    {
        if((mask&(1<<city))==0)
        {
            int newans = dist[pos][city]+tsp(mask|(1<<city),city,dist,n);
            ans = min(ans, newans);
        }
    }
    return ans;
}
int main()
 {
	int t;
	cin>>t;
	while(t--)
	{  
	    int n,i,j,x;
	    cin>>n;
	    int v[12][12];
	    for(i=0; i<n; i++)
	    {
	        for(j=0; j<n; j++)
	        {
	            cin>>v[i][j];
	        }
	    }
	    cout<<tsp(1,0,v,n)<<endl;
	}
	return 0;
}