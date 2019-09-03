// Rod Cutting

#include <iostream>
using namespace std;

int max(int a, int b)  {  return (a>b) ? a : b;  }

int rod(int a[], int n)
{
    int m[n+1][n+1];
    for(int i=0; i<=n; i++)
    {
        m[i][0] = 0;
        m[0][i] = 0;
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(j >= i)  m[i][j] = max(m[i-1][j], m[i][j-i] + a[i-1]);
            else  m[i][j] = m[i-1][j];
        }
    }
    return m[n][n];
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
	    for(int i=0; i<n; i++)  cin>>a[i];
	    cout<<rod(a, n)<<endl;
	}
	return 0;
}