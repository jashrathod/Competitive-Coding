// Minimum number of flips

#include <bits/stdc++.h>
using namespace std;

int min(int a, int b)
{
    return (a<b) ? a : b;
}

int flips(string s)
{
    int c=0;
    for(int i=0; i<s.size(); i++)
    {
        if(i%2 != s[i] - 48)  
        {
            c++;
        }
    }
    return min(s.size()-c, c);
}

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    string s;
	    cin>>s;
	    cout<<flips(s)<<endl;
	}
	return 0;
}