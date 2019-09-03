// Array Pair Sum Divisibility Problem

#include <iostream>
using namespace std;

bool divis(int a[], int n, int k)
{
    bool b[n] = { false };
    for(int i=0; i<n-1; i++)
    {
        if(b[i] == false)
        {
            for(int j=i+1; j<n; j++)
            {
                if(b[j] == false)
    	        {
    	            if((a[i]+a[j]) % k == 0)
    	            {
    	                b[i] = true;
    	                b[j] = true;
    	                break;
    	            }
    	        }
            }
            if(b[i] == false)  return false;
        }
    }
    for(int i=0; i<n; i++)
    {
        if(b[i] == false)  
            return false;
    }
    return true;
}

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>>n;
	    int a[n];
	    for(int i=0; i<n; i++)  cin>>a[i];
	    cin>>k;
	    bool x;
	    if(n%2 != 0)  x = false;
	    else  x = divis(a, n, k);
	    if(x == false)  cout<<"False"<<endl;
	    else  cout<<"True"<<endl;
	}
	return 0;
}