// Second most repeated string in a sequence

#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n, c=0;
	    cin>>n;
	    string a[n];
	    map<string, int> m;
	    for(int i=0; i<n; i++)  
	    {
	        cin>>a[i];
	        if(m.find(a[i]) == m.end())  
	        {
	            m[a[i]] = 1;
	            c++;
	        }
	        else  m[a[i]]++;
	    }
	    map<string, int>:: iterator it, it1=m.begin(), it2;
	    int mx1=m.begin()->second, mx2=0;
	    for(it=m.begin(); it!=m.end(); it++)
	    {
	        if(it->second > mx1)
	        {
	            mx2 = mx1;
	            it2 = it1;
	            mx1 = it->second;
	            it1 = it;
	        }
	        else if(it->second > mx2 && it->second < mx1)
	        {
	            mx2 = it->second;
	            it2 = it;
	        }
	    }
	    cout<<it2->first<<endl;
	}
	return 0;
}