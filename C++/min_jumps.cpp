// MINIMUM NUMBER OF JUMPS

#include <bits/stdc++.h>
using namespace std;

int min(int a, int b)  { return (a<b) ? a : b;  }

int minJumps(int arr[], int n)  
{  
    int *jumps = new int[n];   
    int i, j;  
  
    if (n == 0 || arr[0] == 0)  
        return INT_MAX;  
  
    jumps[0] = 0;  
    for (i = 1; i < n; i++)  
    {  
        jumps[i] = INT_MAX;  
        for (j = 0; j < i; j++)  
        {  
            if (i <= j + arr[j] && jumps[j] != INT_MAX)  
            {  
                jumps[i] = min(jumps[i], jumps[j] + 1);  
                break;  
            }  
        }  
    }  
    return jumps[n-1];  
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
	    int x = minJumps(a, n);
	    if(x == INT_MAX)  x = -1;
	    cout<<x<<endl;
	}
	return 0;
}
