// Job Sequencing Problem

#include <iostream>
using namespace std;

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int id[n], deadline[n], profit[n];
	    for(int i=0; i<n; i++)
	    {
	        cin>>id[i]>>deadline[i]>>profit[i];
	    }
	    for(int i=0; i<n-1; i++)
	    {
	        for(int j=0; j<n-i-1; j++)
	        {
	            if(profit[j]<profit[j+1])
	            {
	                int t = profit[j+1];
	                profit[j+1] = profit[j];
	                profit[j] = t;
	                
	                t = deadline[j+1];
	                deadline[j+1] = deadline[j];
	                deadline[j] = t;
	                
	                t = id[j+1];
	                id[j+1] = id[j];
	                id[j] = t;
	            }
	        }
	    }
	    
	    int a[n] = { 0 }, c=0, p=0;
	    for(int i=0; i<n; i++)
	    {
	        if(a[deadline[i]-1] == 0)
	        {
	            p += profit[i];
	            c++;
	            a[deadline[i]-1] = 1;
	        }
	        else
	        {
	            for(int j=deadline[i]-1; j>=0; j--)
	            {
	                if(a[j] == 0)
	                {
	                    p += profit[i];
        	            c++;
        	            a[j] = 1;
        	            break;
	                }
	            }
	        }
	    }
	    cout<<c<<" "<<p<<endl;
	}
	return 0;
}