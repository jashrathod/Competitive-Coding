// LONGEST INCREASING SEQUENCE


// Recursive

#include <bits/stdc++.h>
using namespace std;

int max(int a, int b)
{
    return (a>b) ? a : b;
}

int lis(int a[], int i, int n)
{
    if(i >= n)  return 0;
    int m=INT_MIN;
    for(int j=i+1; j<=n; j++)
    {
        if(a[j]>a[i])
        {
            int x = 1 + lis(a, j, n);
            m = max(m, x);
        }
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
	    cout<<lis(a, 0, n)<<endl;
	}
	return 0;
}


// Dynamic Programming

#include <bits/stdc++.h>
using namespace std;

int lis(int a[], int n)
{
    int b[n];
    b[0] = 1;
    for(int i=1; i<n; i++)
    {
        b[i]=1;
        for(int j=0; j<i; j++)
        {
            if(a[j] < a[i] && b[i] < b[j]+1)
                b[i] = b[j] + 1;
        }
    }
    int me = INT_MIN;
    for(int i=0; i<n; i++)
    {
        if(me < b[i])
            me = b[i];
    }
    return me;
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
	    cout<<lis(a, n)<<endl;
	}
	return 0;
}
