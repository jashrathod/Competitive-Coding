// nCr

#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007

int min(int a, int b)  {  return (a<b) ? a : b;  }

long long int fact(int n, int r)
{
    long long int a[n+1][r+1];
    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<=min(r, i); j++)
        {
            if(j == 0 || j == i)  a[i][j] = 1;
            else  a[i][j] = (a[i-1][j-1]%mod + a[i-1][j]%mod)%mod;
        }
    }
    return a[n][r];
}

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n, r;
	    cin>>n>>r;
	    cout<<fact(n, r)<<endl;
	}
	return 0;
}