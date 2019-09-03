// Reach a given score

#include <iostream>
using namespace std;

int score(int n)
{
    int a[3] = {3, 5, 10};
    int m[4][n+1];
    for(int i=0; i<=n; i++)  m[0][i] = 0;
    for(int i=1; i<4; i++)  m[i][0] = 1;
    for(int i=1; i<4; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(j >= a[i-1])  m[i][j] = m[i-1][j] + m[i][j-a[i-1]];
            else  m[i][j] = m[i-1][j];
        }
    }
    return m[3][n];
}

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    cout<<score(n)<<endl;
	}
	return 0;
}