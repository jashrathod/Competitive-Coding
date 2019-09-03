// Total Decoding Messages

#include <iostream>
using namespace std;

int totalDecode(string s, int n)
{
    int a[n+1];
    a[n] = 1;
    if(s[n-1] == '0')  a[n-1] = 0;
    else  a[n-1] = 1;
    for(int i=n-2; i>=0; i--)
    {
        if(s[i] == '0')  a[i] = 0;
        else if((s[i]-48)*10 + (s[i+1]-48) > 26)  a[i] = a[i+1];
        else  a[i] = a[i+1] + a[i+2];
    }
    return a[0];
}

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    string s;
	    cin>>s;
	    cout<<totalDecode(s, n)<<endl;
	}
	return 0;
}