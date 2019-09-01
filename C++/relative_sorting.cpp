// RELATIVE SORTING

#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int t, m, n;
	cin>>t;
	while(t--)
	{
	    cin>>m>>n;
	    int a[m], b[n];
	    map<int, int> u;
	    for(int i=0; i<m; i++)  
	    {
	        cin>>a[i];
	        if(u.find(a[i]) == u.end())  u.insert(make_pair(a[i], 1));
	        else  u[a[i]]++;
	    }
	    for(int i=0; i<n; i++)  
	    {
	        cin>>b[i];
	        if(u.find(b[i]) != u.end())
	        {
	            for(int j=0; j<u[b[i]]; j++)  
	                cout<<b[i]<<" ";
	            u.erase(b[i]);
	        }
	    }
	    map<int, int> :: iterator it;
	    for(it=u.begin(); it!=u.end(); it++)
	    {
	        for(int i=0; i<(*it).second; i++)
	        {
	            cout<<(*it).first<<" ";
	        }
	    }
	    cout<<endl;
	}
	return 0;
}
