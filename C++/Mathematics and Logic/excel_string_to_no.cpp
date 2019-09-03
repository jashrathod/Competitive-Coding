// Excel Sheet (String to Number)

#include <iostream>
using namespace std;

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    string s;
	    cin>>s;
	    int res = 0;
	    for(int i=0; i<s.size(); i++)
	    {
	        res = res*26 + (s[i] - 'A') + 1;
	    }
	    cout<<res<<endl;
	}
	return 0;
}