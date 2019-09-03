// MAXIMUM SUM INCREASING SUBSEQUENCE

#include <iostream>
using namespace std;

int incSum(int a[], int n)
{
    int b[n];
    b[0] = a[0];
    for(int i=1; i<n; i++)
    {
        b[i] = a[i];
        for(int j=0; j<i; j++)
        {
            if(a[i]>a[j] && b[i]<b[j]+a[i])
                b[i] = b[j] + a[i];
        }
    }
    int m = 0;
    for(int i=0; i<n; i++)
    {
        if(m < b[i])
            m = b[i];
    }
    return m;
}

int main() 
{
	int t, n;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    int a[n];
	    for(int i=0; i<n; i++)  cin>>a[i];
	    cout<<incSum(a, n)<<endl;
	}
	return 0;
}
