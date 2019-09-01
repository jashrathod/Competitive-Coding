// Count number of hops

// Recursive

#include <iostream>
using namespace std;

int fn(int n, int a[])
{
    if(n < 0)  return 0;
    if(n == 0)  return 1;
    return fn(n-3) + fn(n-2) + fn(n-1);
}

int main() 
 {
	int t, n;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    int a[n+1] = { -1 };
	    a[0] = 0;
	    cout<<fn(n, a)<<endl;
	}
	return 0;
}

// Dynamic Programming

#include <iostream>
using namespace std;

int fn(int n)
{
    if(n <= 0)  return 0;
    
    int a[n] = { 0 };
    
    a[0] = 1;
    a[1] = 2;
    a[2] = 4;
    
    for(int i=3; i<n; i++)
    {
        // if(i-1 > 0)  a[i] += a[i-1];
        // else if(i-1 == 0)  a[i]++;
        
        // if(i-2 > 0)  a[i] += a[i-2];
        // else if(i-2 == 0)  a[i]++;
        
        // if(i-3 > 0)  a[i] += a[i-3];
        // else if(i-3 == 0)  a[i]++;
        
        a[i] = a[i-1] + a[i-2] + a[i-3];
    }
    
    return a[n-1];
}

int main() 
 {
	int t, n;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    cout<<fn(n)<<endl;
	}
	return 0;
}
