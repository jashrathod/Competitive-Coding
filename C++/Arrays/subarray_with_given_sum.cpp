// SUBARRAY WITH GIVEN SUM

#include <iostream>
using namespace std;

int main() 
{
	int t, n, s;
	cin>>t;
// 	for(int k=0; k<t; k++)
    while(t--)
	{
	    cin>>n>>s;
	    int a[n], start, end, flag=0;
	    for(int i=0; i<n; i++)
	        cin>>a[i];
	    for(int i=0; i<n; i++)
	    {
	        int sum=0;
	        for(int j=i; j<n; j++)
	        {
	            sum=sum+a[j];
	            if(sum == s)
	            {
	                start=i+1;
	                end=j+1;
	                flag=1;
	                break;
	            }
	        }
	        if(flag == 1)  break;
	    }
	    if(flag == 1)  cout<<start<<" "<<end<<endl;
	    else cout<<-1<<endl;
	}
	return 0;
}
