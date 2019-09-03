// Longest Repeating Subsequence

#include <iostream>
using namespace std;

int max(int a, int b)  {  return (a>b) ? a : b;  }

int lrs(string s, int n)
{
    int a[n+1][n+1];
    for(int i=0; i<=n; i++)
    {
        a[i][0] = 0;
        a[0][i] = 0;
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(s[i-1] == s[j-1] && i != j)  a[i][j] = 1 + a[i-1][j-1];
            else  a[i][j] = max(a[i-1][j], a[i][j-1]);
        }
    }
    return a[n][n];
}

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    string s;
	    cin>>n>>s;
	    cout<<lrs(s, n)<<endl;
	}
	return 0;
}