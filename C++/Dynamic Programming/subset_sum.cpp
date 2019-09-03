// Subset Sum Problem


// Recursive Approach

#include <iostream>
using namespace std;

int fn(int a[], int n, int sum)
{
    if(n<0 || sum<0)  return 0;
    if(a[n] == sum)  return 1;
    int x = fn(a, n-1, sum);
    int y = fn(a, n-1, sum - a[n]);
    if(x == 2 || y == 2 || (x == 1 && y == 1))  return 2;
    else if(x == 1 || y == 1)  return 1;
    else  return 0;
}

int main() 
{
	int t, n;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    int a[n];
	    int sum = 0;
	    
	    for(int i=0; i<n; i++)  
	    {
	        cin>>a[i];
	        sum = sum+a[i];
	    }
	    
	    if(sum%2 != 0)  cout<<"NO"<<endl;
	    else 
	    {
	        int x = fn(a, n-1, sum/2);
	        if(x == 2)  cout<<"YES"<<endl;
	        else  cout<<"NO"<<endl;
	    }
	}
	return 0;
}

// Dynamic Programming

#include <iostream>
using namespace std;

int fn(int a[], int n, int sum)
{
    bool m[n+1][sum+1];
    
    for(int i=0; i<=n; i++)  m[i][0] = 1;
    for(int i=1; i<=sum; i++)  m[0][i] = 0;
    
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=sum; j++)
        {
            if(a[i-1]>j)  m[i][j] = m[i-1][j];
            else  m[i][j] = m[i-1][j] || m[i-1][j-a[i-1]];
        }
    }
    return m[n][sum];
}

int main() 
{
	int t, n;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    int a[n];
	    int sum = 0;
	    
	    for(int i=0; i<n; i++)  
	    {
	        cin>>a[i];
	        sum = sum+a[i];
	    }
	    
	    if(sum%2 != 0)  cout<<"NO"<<endl;
	    else 
	    {
	        int x = fn(a, n, sum/2);
	        if(x == 1)  cout<<"YES"<<endl;
	        else  cout<<"NO"<<endl;
	    }
	} 
	return 0;
}
