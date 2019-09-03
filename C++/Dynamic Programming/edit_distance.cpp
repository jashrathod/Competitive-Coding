// EDIT DISTANCE

#include <iostream>
#include <string.h>
using namespace std;

int min(int a, int b, int c)
{
    if(a <= b && a <= c)  return a;
    else if(b <= a && b <= c)  return b;
    else  return c;
}

int edit(string s1, string s2, int m, int n)
{
    int a[m+1][n+1];
    for(int i=0; i<=m; i++)
    {
        a[i][0] = i;
        for(int j=1; j<=n; j++)
        {
            if(i == 0)  a[i][j] = j;
            else if(s1[i-1] == s2[j-1])  a[i][j] = a[i-1][j-1];
            else  a[i][j] = 1 + min(a[i-1][j], a[i-1][j-1], a[i][j-1]);
        }
    }
    return a[m][n];
}

int main() 
{
	int t, m, n;
	cin>>t;
	while(t--)
	{
	    string s1, s2;
	    cin>>m>>n;
	    cin>>s1>>s2;
	    cout<<edit(s1, s2, m, n)<<endl;
	}
	return 0;
}
