// Odd to Even

#include <iostream>
using namespace std;

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    string s, s1;
	    cin>>s;
	    s1 = s;
	    char b;
	    for(int i=0; i<s.size(); i++)
	    {
	        if((s[i]-48)%2 == 0 && s[i] < s[s.size()-1]) 
	        {
	            char a = s[i];
	            s[i] = s[s.size()-1];
	            s[s.size()-1] = a;
	            break;
	        }
	    }
	    if(s1 == s)
	    {
	        for(int i=s.size()-2; i>=0; i--)
    	    {
    	        if((s[i]-48)%2 == 0) 
    	        {
    	            char a = s[i];
    	            s[i] = s[s.size()-1];
    	            s[s.size()-1] = a;
    	            break;
    	        }
    	    }
	    }
	    cout<<s<<endl;
	}
	return 0;
}