// Bleak Numbers

/*
Given an integer, check whether it is Bleak or not.

A number ‘n’ is called Bleak if it cannot be represented as sum of a positive number x and set bit count in x, 
i.e., x + countSetBits(x) is not equal to n for any non-negative number x.

Examples :

3 is not Bleak as it can be represented
as 2 + countSetBits(2).

4 is t Bleak as it cannot be represented 
as sum of a number x and countSetBits(x)
for any number x.
*/

#include <iostream>
using namespace std;

int csb(int n)
{
    int c=0;
    while(n != 0)
    {
        if(n%2 == 1)  c++;
        n = n/2;
    }
    return c;
}

int bleak(int n)
{
    for(int i=n; i>=0; i--)
    {
        if(n == i + csb(i))  
            return 0;
    }
    return 1;
}

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    cout<<bleak(n)<<endl;
	}
	return 0;
}