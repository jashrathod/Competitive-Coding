// Sum of dependencies in a graph

#include <iostream>
#include <vector>
using namespace std;

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n, e;
	    cin>>n>>e;
	    vector<int> a[n];
	    for(int i=0; i<e; i++)
	    {
	        int u, v;
	        cin>>u>>v;
	        a[u].push_back(v);
	    }
	    int sum = 0;
	    for(int i=0; i<n; i++)
	    {
	        sum += a[i].size();
	    }
	    cout<<sum<<endl;
	}
	return 0;
}