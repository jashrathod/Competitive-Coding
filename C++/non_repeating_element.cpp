// Non-Repeating Element

#include <iostream>
#include <unordered_map>
using namespace std;

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    long long int a[n];
	    for(int i=0; i<n; i++)  cin>>a[i];
	    unordered_map<long long int, int> m;
	    int i=0;
	    for(int j=0; j<n; j++)
	    {
	        if(m.find(a[j]) == m.end())
	        {
	            m[a[j]] = 1;
	        }
	        else
	        {
	            m[a[j]]++;
	            if(a[j] == a[i])
	            {
	                while(i<=j && m[a[i]] != 1)
	                {
	                    i++;
	                }
	            }
	        }
	    }
	    if(i >= n)  cout<<0<<endl;
	    else  cout<<a[i]<<endl;
	}
	return 0;
}