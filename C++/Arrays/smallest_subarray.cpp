// Smallest subarray with sum greater than x

#include <iostream>
using namespace std;

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n, m, l=1001;
	    cin>>n>>m;
	    int a[n];
	    for(int i=0; i<n; i++)  cin>>a[i];
	    for(int i=0; i<n; i++)
	    {
	        int sum = 0;
	        for(int j=i; j<n; j++)
	        {
	            sum = sum + a[j];
	            if(sum > m && l > j-i+1)  
	            {
	                l = j - i + 1;
	                break;
	            }
	        }
	    }
	    cout<<l<<endl;
	}
	return 0;
}