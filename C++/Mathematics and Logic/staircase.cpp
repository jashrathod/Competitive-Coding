// Maximum height of staircase

#include <iostream>
#include <math.h>
using namespace std;

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	   
        // Method 2
        int ht = 0;
	    for(int i=1; n>0; i++)
	    {
	        n = n-i;
	        if(n >= 0)  ht++;
	    }
	    cout<<ht<<endl;

        // Method 2
	    int ht1 = (-1 + sqrt(1+8*n)) / 2;
	    cout<<ht1<<endl;
	}
	return 0;
}