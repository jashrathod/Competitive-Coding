// Is Binary Number Multiple of 3

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
	    int odd=0, even=0, flag=0;
	    for(int i=0; i<s.size(); i++)
	    {
	        if(flag == 0)
	        {
	            even += (s[i]-48);
	            flag = 1;
	        }
	        else
	        {
	            odd += (s[i]-48);
	            flag = 0;
	        }
	    }
	    if(abs(odd - even)%3 == 0)  cout<<1<<endl;
	    else  cout<<0<<endl;
	}
	return 0;
}