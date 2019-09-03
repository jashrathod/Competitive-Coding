// Word Boggle 

#include <bits/stdc++.h>
using namespace std;

const int MAX = 7;

void fn(int i, int j, int k, int p, int q, string s, char m[MAX][MAX], 
        int b[MAX][MAX], vector<string> &v)
{
    if(b[i][j] == 1 || i < 0 || j < 0 || i >= p || j >= q || m[i][j] != s[k])  
    {
        return;
    }
    else if(k == s.size()-1 && b[i][j] == 0)
    {
        v.push_back(s);
        return;
    }
    else
    {
        b[i][j] = 1;
        k++; 
        fn(i-1, j-1, k, p, q, s, m, b, v);
        fn(i-1, j, k, p, q, s, m, b, v);
        fn(i-1, j+1, k, p, q, s, m, b, v);
        fn(i, j-1, k, p, q, s, m, b, v);
        fn(i, j+1, k, p, q, s, m, b, v);
        fn(i+1, j-1, k, p, q, s, m, b, v);
        fn(i+1, j, k, p, q, s, m, b, v);
        fn(i+1, j+1, k, p, q, s, m, b, v);
    }
}

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n, p, q;
	    cin>>n;
	    vector<string> r, v;
	    string x;
	    for(int i=0; i<n; i++)
	    {
	        cin>>x;
	        r.push_back(x);
	    }
	    cin>>p>>q;
	    char m[MAX][MAX];
	    for(int i=0; i<p; i++)
	    {
	        for(int j=0; j<q; j++)
    	        cin>>m[i][j];
	    } 
	    for(int z=0; z<n; z++)
	    {
	        for(int i=0; i<p; i++)
    	    {
    	        for(int j=0; j<q; j++)
    	        {
            	    int b[MAX][MAX] = { 0 };
        	        fn(i, j, 0, p, q, r[z], m, b, v);
    	        }
    	    }
	    }
	    sort(v.begin(), v.end());
	    if(v.size() != 0)
	    {
	        set<string> s;
	        for(int i=0; i<v.size(); i++)
	        {
	            if(s.find(v[i]) == s.end())  s.insert(v[i]);
	        }
	        set<string>:: iterator it;
	        for(it=s.begin(); it!=s.end(); it++)  
	            cout<<(*it)<<" ";
	    }
	    else  cout<<-1;
	    cout<<endl;
	}
	return 0;
}