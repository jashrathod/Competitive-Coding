// LEFT ROTATE

#include<iostream>
#include<stdlib.h> 
// #include<assert.h>
#include<string.h>
#include<stack>
using namespace std;

int main()
{
	int n, d, temp;
	cin>>n>>d;
	int a[n];
	for(int i=0; i<n; i++)
	{
		cin>>a[i];
	}
	for(int i=0; i<n; i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
	for(int i=0; i<d; i++)
	{
		temp=a[0];
		for(int i=1; i<n; i++)
		{
			a[i-1]=a[i];
		}
		a[n-1]=temp;
	}
	for(int i=0; i<n; i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
	return 0;
}