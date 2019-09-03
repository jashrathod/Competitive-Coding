// Missing and Multiple

#include <iostream>
using namespace std;

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n, missing, multiple;
	    cin>>n;
	    int a[n], b[n] = { 0 };
	    for(int i=0; i<n; i++) 
	    {
	        cin>>a[i];
	        b[a[i]-1]++;
	    }
	    for(int i=0; i<n; i++) 
	    {
	        if(b[i] == 0)  missing = i+1;
	        if(b[i] > 1)  multiple = i+1;
	    }
	    cout<<multiple<<" "<<missing<<endl;
	}
	return 0;
}