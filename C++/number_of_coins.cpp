// Number of coins

#include <bits/stdc++.h>
using namespace std;

int coins(int v[], int n, int m)
{
    int a[m+1];
    a[0] = 0;
    for(int i=1; i<=m; i++)
    {
        a[i] = INT_MAX;
        for(int j=0; j<n; j++)
        {
            if(v[j] <= i)
            {
                int s = a[i-v[j]];
                if(s != INT_MAX && s+1 < a[i])  
                    a[i] = s+1;
            }
        }
    }
    if(a[m] == INT_MAX)  return -1;
    return a[m];
}

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    int m, n;
	    cin>>m>>n;
	    int v[n];
	    for(int i=0; i<n; i++)  cin>>v[i];
	    cout<<coins(v, n, m)<<endl;
	}
	return 0;
}