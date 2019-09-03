// REMOVE DUPLICATES FROM A STRING

#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
	    unordered_set<char> u;
	    queue<char> q;
	    string s;
	    getline(cin, s);
	    for(int i=0; i<s.size(); i++)
        {
            if(u.find(s[i]) == u.end())
            {
                u.insert(s[i]);
                q.push(s[i]);
            }
        }
	    while(!q.empty())
	    {
	        cout<<q.front();
	        q.pop();
	    }
	    cout<<endl;
    }
	return 0;
}
