// NUMBER OF WAYS TO MAKE COIN CHANGE


// Recursive

#include <iostream>
using namespace std;

int fn(int a[], int m, int n)
{
    if(n == 0)  return 1;
    if(n < 0)  return 0;
    if(n >= 1 && m <= 0)  return 0;
    return fn(a, m-1, n) + fn(a, m, n-a[m-1]);
}

int main() 
 {
	int t, m, n;
	cin>>t;
	while(t--)
	{
	    cin>>m;
	    int a[m];
	    for(int i=0; i<m; i++)  cin>>a[i];
	    cin>>n;
	    cout<<fn(a, m, n)<<endl;
	}
	return 0;
}

// Dynamic Programming

#include <iostream>
using namespace std;

int fn(int a[], int m, int n)
{
    int p[m+1][n+1];
    for(int i=0; i<m+1; i++)
    {
        p[i][0] = 1;
        for(int j=1; j<n+1; j++)
        {
            if(i == 0)  p[i][j] = 0;
            else if(j < a[i-1])
                p[i][j] = p[i-1][j];
            else 
                p[i][j] = p[i-1][j] + p[i][j-a[i-1]];
        }
    }
    return p[m][n];
}

int main() 
 {
	int t, m, n;
	cin>>t;
	while(t--)
	{
	    cin>>m;
	    int a[m];
	    for(int i=0; i<m; i++)  cin>>a[i];
	    cin>>n;
	    cout<<fn(a, m, n)<<endl;
	}
	return 0;
}
