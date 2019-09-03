// Factorial of Large Numbers

#include <bits/stdc++.h>
using namespace std;

void fact(int n)
{
    string s = "1";
    for(int i=1; i<=n; i++)
    {
        int carry = 0;
        for(int j=0; j<s.size(); j++)
        {
            int x = (s[j] - 48) * i + carry;
            s[j] = (x % 10) + 48;
            carry = x / 10;
        }
        while(carry)  
        {
            int d = carry % 10;
            s = s + char(d + 48);
            carry = carry / 10;
        }
    }
    for(int i=s.size()-1; i>=0; i--)
    {
        cout<<s[i];
    }
}

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    fact(n);
	    cout<<endl;
	}
	return 0;
}