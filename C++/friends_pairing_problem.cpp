// Friends Pairing Problem 

 #include <iostream>
using namespace std;

long long int friends(long long int n)
{
    long long int a[n];
    a[0] = 1;
    a[1] = 2;
    for(long long int i=2; i<n; i++)
    {
        a[i] = (a[i-1] + (i)*a[i-2]) % 1000000007;
    }
    return a[n-1];
}

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    long long int n;
	    cin>>n;
	    cout<<friends(n)<<endl;
	}
	return 0;
}