// Dice throw

#include<bits/stdc++.h>
using namespace std;
# define mod 1000000007
long long int dp[55][55];
long long int rec (long long int face, long long int throws, long long int sum)
{
    if(sum == 0 && throws == 0)  return 1;
    if(sum < 0 || throws == 0)  return 0;
    if(dp[throws][sum] != -1)  return dp[throws][sum];
    
    long long int ans=0;
    for(long long int i=1; i<=face; i++)
        ans += rec(face, throws-1, sum-i);
    
    return dp[throws][sum] = ans;
}


int main()
 {
	long long int t;
	cin>>t;
	while(t--)
	{
	   long long int faces, throws, sum;
	   cin>>faces>>throws>>sum;
	   memset(dp, -1, sizeof dp);
	   cout<<rec(faces, throws, sum)<<endl;
	}
	return 0;
}