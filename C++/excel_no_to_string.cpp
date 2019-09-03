// Excel Sheet (Number to String)

#include <iostream>
#include <string.h>
using namespace std;

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    string s = "";
	    while(n)
	    {
	        if(n%26 == 0)  
	        {
	            s = "Z" + s;
	            n--;
	        }
	        else
	        {
	            s = char(n % 26 + 'A' - 1) + s;
	        }
	        n = n/26;
	    }
	    cout<<s<<endl;
	}
	return 0;
}