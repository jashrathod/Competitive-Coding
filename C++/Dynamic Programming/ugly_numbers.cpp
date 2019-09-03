// Ugly Numbers

#include <bits/stdc++.h>
using namespace std;

long long int getNthUglyNo(long long int n, long long int ugly[]) 
{ 
    // long long int ugly[n]; 
    long long int i = 0, j = 0, k = 0; 
    long long int z1 = 2, z2 = 3, z3 = 5; 
    long long int next_ugly_no = 1; 
  
    ugly[0] = 1; 
    for (int p=1; p<n; p++) 
    { 
        next_ugly_no = min(z1, min(z2, z3)); 
        ugly[p] = next_ugly_no; 
        
        if (next_ugly_no == z1) 
        { 
            i = i+1; 
            z1 = ugly[i]*2; 
        } 
        if (next_ugly_no == z2) 
        { 
            j = j+1; 
            z2 = ugly[j]*3; 
        } 
        if (next_ugly_no == z3) 
        { 
            k = k+1; 
            z3 = ugly[k]*5; 
        } 
    }
    return next_ugly_no; 
} 

int main() 
{
	int t;
	scanf("%d", &t);
	long long int a[10000];
	getNthUglyNo(10000, a);
	while(t--)
	{
	    int n;
	    scanf("%d", &n);
	   // cout<<getNthUglyNo(n)<<endl;
	    cout<<a[n-1]<<endl;
	}
	return 0;
}