// Kth Smallest Element

#include <iostream>
#include <climits>
using namespace std;

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n, k, min=INT_MAX, max=INT_MIN;
	    cin>>n;
	    int a[n];
	    for(int i=0; i<n; i++)
	    {
	        cin>>a[i];
	        if(a[i] < min)  min = a[i];
	        if(a[i] > max)  max = a[i];
	    }
	    cin>>k;
	    int x[max-min+1] = { 0 };
	    for(int i=0; i<n; i++)
	    {
	        x[a[i]-min]++;
	    }
	    for(int i=0; i<max-min+1; i++)
	    {
	        if(x[i])  k--;
	        if(k == 0)  
	        {
	            cout<<(min+i)<<endl;
	            break;
	        }
	    }
	}
	return 0;
}