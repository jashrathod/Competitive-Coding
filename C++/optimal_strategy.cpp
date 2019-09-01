// Optimal strategy for a Game


// Rescursive

#include <bits/stdc++.h>
using namespace std;

int max1(int a, int b)  {  return (a>b) ? a : b;  }
int max(int a, int b, int c, int d)  {  return max1(max1(a, b), max1(c, d));  }

int fn2(int arr[], int i, int j, int sum) 
{ 
    if (j == i + 1) 
        return max(arr[i], arr[j]); 
  
    return max((sum - fn2(arr, i+1, j, sum - arr[i])), 
               (sum - fn2(arr, i, j-1, sum - arr[j]))); 
} 
  
int fn1(int* arr, int n) 
{ 
    int sum = 0; 
    sum = accumulate(arr, arr + n, sum); 
    return fn2(arr, 0, n - 1, sum); 
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
	    cout<<fn1(a, n)<<endl;
	}
	return 0;
}


// Dynamic Programming

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int dp[101][101];

int find(int arr[],int st,int end)
{
    if(st == end)  return arr[st];
    if(st == end-1)  return max(arr[st],arr[end]);
    if(dp[st][end] != -1)  return dp[st][end];
    dp[st][end] = max(arr[st] + min(find(arr,st+2,end), find(arr,st+1,end-1)),
                      arr[end] + min(find(arr,st+1,end-1),find(arr,st,end-2)));
    return dp[st][end];
}

int main() 
{
	int t, n;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    int arr[n];
	    memset(dp,-1,sizeof(dp));
	    for(int i=0;i<n;i++)  cin>>arr[i];
	    int st=0, end=n-1;
	    find(arr,st,end);
	    cout<<dp[0][end]<<endl;
	}
	return 0;
}
