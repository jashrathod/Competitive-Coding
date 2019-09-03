// Painting the Fence

#include <iostream>
using namespace std;

long long int paint(long long int n, long long int k)
{
    long long int a[n+1] = { 0 };
    a[1] = k;
    long long int s=0, d=k;
    for(int i=2; i<=n; i++)
    {
        s = d;
        d = a[i-1] * (k-1);
        d = d % 1000000007;
        a[i] = (d + s ) % 1000000007; 
    }
    return a[n];
}

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    long long int n, k;
	    cin>>n>>k;
	    cout<<paint(n, k)<<endl;
	}
	return 0;
}