// Nth Catalan Number


// Doesn't work for large numbers -- C++
// Check Python code

#include <iostream>
using namespace std;

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    unsigned long long int a[n+1];
	    a[0] = 1;
	    for(int i=1; i<=n; i++)
	    {
	        unsigned long long int res = 0;
	        for(int j=1; j<=i; j++)
	        {
	            res += a[j-1]*a[i-j];
	        }
	        a[i] = res;
	    }
	    cout<<a[n]<<endl;
	}
	return 0;
}