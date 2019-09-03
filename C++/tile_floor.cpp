// Ways To Tile A Floor

#include <iostream>
using namespace std;

long long int tile(int n)
{
    long long int a[n];
    a[0] = 1;
    a[1] = 2;
    for(int i=2; i<n; i++)
    {
        a[i] = a[i-1] + a[i-2];
    }
    return a[n-1];
}

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    cout<<tile(n)<<endl;
	}
	return 0;
}