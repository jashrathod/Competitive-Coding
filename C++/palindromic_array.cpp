// Palindromic Array

#include <iostream>
using namespace std;

int palindrome(int a[], int n)
{
    int i=0, j=n-1, m=0;
    while(i < j)
    {
        if(a[i] == a[j])
        {
            i++;
            j--;
        }
        else if(a[i] < a[j])
        {
            a[i+1] = a[i+1] + a[i];
            i++;
            m++;
        }
        else
        {
            a[j-1] = a[j-1] + a[j];
            j--;
            m++;
        }
    }
    return m;
}

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0; i<n; i++)  cin>>a[i];
	    cout<<palindrome(a, n)<<endl;
	}
	return 0;
}