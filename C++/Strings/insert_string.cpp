// INSERT ONE STRING IN ANOTHER

#include<iostream>
#include<string.h>
#include<stack>
using namespace std;

int main()
{
	int p, i=0, j=0;
    char a[]="hello", b[]="world", c[10];
    cin>>p;
    for(i=0; i<p; i++)
    {
    	c[i]=a[i];
    }
    for(j=0; j<strlen(b); j++)
    {
    	c[i]=b[j];
    	i++;
    }
    for(j=p; j<strlen(a); j++)
    {
    	c[i]=a[j];
    	i++;
    }
    cout<<c;
	return 0;
}