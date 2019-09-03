// Count ways to N'th Stair(Order does not matter)

#include<bits/stdc++.h>
using namespace std;
long long mod =1000000007;
long long countWays(int);
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int m;
        cin>>m;
        cout<<countWays(m)<<endl; 
    }
    return 0;
}

long long countWays(int m)
{
    // int a[m], x=1;
    // a[0] = 1;
    // for(int i=1; i<m; i++)
    // {
    //     if(i%2 == 1)  a[i] = ++x;
    //     else  a[i] = x;
    // }
    // return a[m-1];
    
    return m/2 + 1;
}