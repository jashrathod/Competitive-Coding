// Transform One String to Another using Minimum Number of Given Operation

#include<bits/stdc++.h> 
using namespace std; 
  
int minOps(string& A, string& B) 
{ 
    int m = A.length(), n = B.length(); 
    
    if (n != m) 
       return -1; 
    
    int count[256]; 
    memset(count, 0, sizeof(count)); 
    
    for (int i=0; i<n; i++)   
       count[B[i]]++; 
    
    for (int i=0; i<n; i++)    
       count[A[i]]--;         
    
    for (int i=0; i<256; i++)   
      if (count[i]) 
         return -1; 
  
    int res = 0; 
    for (int i=n-1, j=n-1; i>=0; ) 
    { 
        while (i>=0 && A[i] != B[j]) 
        { 
            i--; 
            res++; 
        } 
  
        if (i >= 0) 
        { 
            i--; 
            j--; 
        } 
    } 
    return res; 
} 
  
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s1, s2;
        cin>>s1>>s2;
        cout<<minOps(s1, s2);
    }
    return 0; 
} 