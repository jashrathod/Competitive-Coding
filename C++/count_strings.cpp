// Count of strings that can be formed using a, b and c under given constraints

#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int t;
    cin>>t;
    
    while(t--)
    {
        long long int n;
        cin>>n;
        long long int b0c0= 1, b0c1= n, b0c2= n*(n-1)/2, b1c0= n, 
                      b1c1= n*(n-1), b1c2= n*(n-1)*(n-2)/2;
        
        cout << b0c0 + b0c1 + b0c2 + b1c0 + b1c1 + b1c2 << endl; 
    }
    return 0;
}