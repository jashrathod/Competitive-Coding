// NEXT LARGEST

#include <bits/stdc++.h>
using namespace std;
int main() 
{	
	int t;
	cin>>t;	
	while(t--)
	{
	    int n;
	    cin>>n;
	    long long arr[n];
	    for(int i=0;i<n;i++)
	        cin>>arr[i];
	    long long v[n];     
	    stack<long long> s;
	    for(int i=n-1;i>=0;i--)
	    {
	        while(!s.empty() && s.top()<=arr[i])
	             s.pop();
	        if(s.empty())  v[i]=-1;
	        else  v[i]=s.top();
	        s.push(arr[i]);   
	    }
	    for(int i=0;i<n;i++)
	        cout<<v[i]<<" ";    
	    cout<<endl;
	}
	return 0;
}
