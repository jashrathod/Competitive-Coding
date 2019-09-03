// Maximum Product Subarray

#include<bits/stdc++.h>
using namespace std;

int main() 
{
	int t;
	cin>>t;
	while(t--)
    {
	    long long int n,neg=0,z=0;
	    cin>>n;
	    long long int a[n];
	    for(int i=0;i<n;i++)
	    {
	        cin>>a[i];
	        if(a[i]<0){neg++;}
	        if(a[i]==0){z++;}
	    }
	    if(neg==1 && z==n-1 && z!=0)  cout<<"0"<<endl;
        else if(neg==1 && n==1)  cout<<a[0]<<endl;
        else
        {
            long long int maxi=1,mini=1,maxl=0;
            for(int i=0;i<n;i++)
            {
                if(a[i]>0)
                {
                    maxi=maxi*a[i];
                    mini=min(mini*a[i],(long long)1);
                }
                else if(a[i]<0)
                {
                    long long int temp=maxi;
                    maxi=max(mini*a[i],(long long)1);
                    mini=temp*a[i];
                }
                else
                {
                    maxi=1;
                    mini=1;
                }
                if(maxl<maxi)  maxl=maxi;
            }
            cout<<maxl<<endl;
        }
    }    
	return 0;
}
