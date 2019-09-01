// Minimum Distinct IDs

#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n, m, count=0;
	    cin>>n;
	    int a[n];
	    for(int i=0; i<n; i++)  cin>>a[i];
	    cin>>m;
	    map<int, int> mp;
	    vector<pair<int, int>> v;
	    
	    for(int i=0; i<n; i++)
	    {
	        if(mp.find(a[i]) == mp.end())  mp[a[i]] = 1;
	        else  mp[a[i]]++;
	    }
	    
	    map<int, int>::iterator it = mp.begin();
	    for(it=mp.begin(); it!=mp.end(); it++)
	        v.push_back(make_pair(it->second, it->first));
	       
	    sort(v.begin(), v.end()); 
        int s = v.size();
        
	    for(int i=0; i<s; i++)
	    {
	        if(v[i].first > m)
	        {
	            v[i].first = v[i].first - m;
	            m=0;
	            break;
	        }
	        else
	        {
	            m = m - v[i].first;
	            v[i].first = 0;
	        }
	    }
	    for(int i=0; i<s; i++)
	    {
	        if(v[i].first != 0)  count++;
	    }
	    cout<<count<<endl;
	}
	return 0;
}