// Longest Increasing Subsequence

#include <bits/stdc++.h>
using namespace std;

int lis(int a[], int n)
{
    int v[n];
    for(int i=0; i<n; i++)  v[i] = 1;
    for(int i=1; i<n; i++)
    {
        for(int j=0; j<i; j++)
        {
            if(a[j] < a[i])
            {
                v[i] = max(v[i], 1+v[j]);
            }
        }
    }
    int m=INT_MIN;
    for(int i=0; i<n; i++)
    {
        m = max(m, v[i]);
    }
    return m;
}

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0; i<n; i++)
	    {
	        cin>>a[i];
	    }
	    cout<<lis(a, n)<<endl;
	}
	return 0;
}