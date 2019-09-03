// sort array of 0s, 1s, 2s

// Method 1

#include <iostream>
using namespace std;

int main() 
{
	int t, n;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    int a[n], j=0, i, k=0;
	    for(i=0; i<n; i++)
	        cin>>a[i];
	    i=-1;
	    while(i != n-1)
	    {
	        for(j=i+1; j<n; j++)
	        {
	            if(a[j] == k)
	            {
	                i++;
	                int t=a[i];
	                a[i]=a[j];
	                a[j]=t;
	            }
	        }
	        k++;
	    }
	    for(i=0; i<n; i++)
	        cout<<a[i]<<" ";
	    cout<<endl;
	}
	return 0;
}


// Method 2

#include <iostream>
using namespace std;

int main() 
{
	int t, n;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    int a[n], zero=0, one=0, two=0;
	    for(int i=0; i<n; i++)  
        {
            cin>>a[i];
            if(a[i] == 0)  zero++;
            else if(a[i] == 1)  one++;
            else  two++;
        }
	    
	    for(int i=0; i<zero; i++)  cout<<0<<" ";
        for(int i=0; i<one; i++)  cout<<1<<" ";
        for(int i=0; i<two; i++)  cout<<2<<" ";

	    cout<<endl;
	}
	return 0;
}

