// Eggs Dropping Problem


// Recursive

#include <iostream>
#include <limits.h>
using namespace std;

int max(int a, int b)  {  return (a>b) ? a : b;  }

int fn(int e, int f)
{
    if(f == 0 || f == 1 || e == 1)  return f;
    int m = INT_MAX, t;
    for(int i=1; i<=f; i++)
    {
        t = max(fn(e-1, i-1), fn(e, f-i));
        if(m>t)  m = t;
    }
    return 1 + m; 
}

int main() 
{
	int t, e, f;
	cin>>t;
	while(t--)
    {
        cin>>e>>f;
        cout<<fn(e, f)<<endl;
    }
	return 0;
}

// Dynamic Programming

#include <iostream>
#include <limits.h>
using namespace std;

int max(int a, int b)  {  return (a>b) ? a : b;  }

int fn(int e, int f)
{
    int m[e+1][f+1];
    for(int i=1; i<=e; i++)
    {
        m[i][0] = 0;
        m[i][1] = 1;
    }
    
    for(int i=1; i<=f; i++)
        m[1][i] = i;
        
    for(int i=2; i<=e; i++)
    {
        for(int j=2; j<=f; j++)
        {
            m[i][j] = INT_MAX;
            for(int k=1; k<=j; k++)
            {
                int q = 1 + max(m[i-1][k-1], m[i][j-k]);
                if(q<m[i][j])  m[i][j] = q;
            }
        }
    }
    return m[e][f];
}

int main() 
{
	int t, e, f;
	cin>>t;
	while(t--)
    {
        cin>>e>>f;
        cout<<fn(e, f)<<endl;
    }
	return 0;
}
