// Anagrams

#include <iostream>
#include <string.h>
#include <map>
using namespace std;

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    int f=0;
	    string s1, s2;
	    cin>>s1>>s2;
	    if(s1.length() != s2.length())  cout<<"NO"<<endl;
	    else
	    {
	        map<char, int> m1, m2;
	        for(int i=0; i<s1.length(); i++)
	        {
	            if(m1.find(s1[i]) != m1.end())  m1[s1[i]]++;
	            else  m1[s1[i]] = 1;
	        }
	        for(int i=0; i<s2.length(); i++)
	        {
	            if(m2.find(s2[i]) != m2.end())  m2[s2[i]]++;
	            else  m2[s2[i]] = 1;
	        }
	        map<char, int>:: iterator it1, it2;
	        for(it1=m1.begin(), it2=m2.begin(); it1!=m1.end(), 
	            it2!=m2.end(); it1++, it2++)
	        {
	            if(it1->first != it2->first || it1->second != it2->second)
	            {
	                cout<<"NO"<<endl;
	                f = 1;
	                break;
	            }
	        }
	        if(f == 0)  cout<<"YES"<<endl;
	    }
	}
	return 0;
}