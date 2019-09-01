// MINIMUM NUMBER OF PLATFORMS

#include <iostream>
#include <string.h>
using namespace std;

int max(int a, int b)
{
    return (a>b)?a:b;
}

void sort(int a[], int n)
{
    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(a[j]<a[i])
            {
                int t=a[j];
                a[j]=a[i];
                a[i]=a[j];
            }
        }
    }
}

int platforms(int a[], int b[], int n)
{
    int count=0;
    string s="";
    sort(a, n);
    sort(b, n);
    int i=0, j=0;
    while(i<n && j<n)
    {
        if(a[i]<b[j])
        {
            s = s+"a";
            i++;
        }
        else if(a[i]>b[j])
        {
            s = s+"d";
            j++;
        }
        else
        {
            if(i>j)
            {
                s = s+"a";
                i++;
            }
            else
            {
                s = s+"d";
                j++;
            }
        }
    }
    // cout<<s<<endl;
    int m = 0;
    for(i=0; i<s.size(); i++)
    {
        if(s[i] == 'a')
        {
            count++;
            m = max(m, count);
        }
        else if(s[i] == 'd')
        {
            count--;
            m = max(m, count);
        }
    }
    return m;
}

int main() 
{
	int t, n;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    int a[n], b[n];
	    for(int i=0; i<n; i++)  cin>>a[i];
	    for(int i=0; i<n; i++)  cin>>b[i];
	    cout<<platforms(a, b, n)<<endl;
	}
	return 0;
}
