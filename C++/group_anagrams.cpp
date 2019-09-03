// Group Anagrams Together

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

string sorted(string s)
{
    for(int i=0; i<s.size()-1; i++)
    {
        for(int j=0; j<s.size()-i-1; j++)
        {
            if(s[j] > s[j+1])
            {
                char t = s[j];
                s[j] = s[j+1];
                s[j+1] = t;
            }
        }
    }
    return s;
}

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    string a[n];
	    map<string, int> m;
	    map<string, int> :: iterator it;
	    for(int i=0; i<n; i++)  
	    {
	        cin>>a[i];
	        a[i] = sorted(a[i]);
	        
	        if(m.find(a[i]) == m.end())  m[a[i]] = 1;
	        else  m[a[i]]++;
	    }
	    vector<pair<int, string>> v;
	    for(it=m.begin(); it!=m.end(); it++)
	    {
	        v.push_back(make_pair(it->second, it->first));
	    }
	    sort(v.begin(), v.end());
	    for(int i=0; i<v.size(); i++)  
	        cout<<v[i].first<<" ";
	    cout<<endl;
	}
	return 0;
}