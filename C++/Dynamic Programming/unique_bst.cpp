// Unique BST


// Recursive

#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<numTrees(n)<<"
";
    }
}	
int numTrees(int n) 
{
    if(n == 0 || n == 1)  return 1;
    int res = 0;
    for(int i=1; i<=n; i++)
    {
        res += numTrees(i-1)*numTrees(n-i); 
    }
    return res;
}


// Dynamic Programming

#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<numTrees(n)<<"
";
    }
}	
int numTrees(int n) 
{
    int a[n+1];
    a[0] = 1;
    if(n > 0)  a[1] = 1;
    for(int i=2; i<=n; i++)
    {
        int res = 0;
        for(int j=1; j<=i; j++)
        {
            res += a[j-1]*a[i-j];
        }
        a[i] = res;
    }
    return a[n];
}