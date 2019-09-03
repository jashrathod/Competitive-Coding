// READ AN ARRAY AND FIND THE SMALLEST NO.

#include<iostream>
#include<string.h>
#include<stack>
using namespace std;

int ra(int a[]);
int main()
{
	int a[10]={1,2,3,4,5,0,7,8,9,10};
	int m = ra(a);
	cout<<m;
	return 0;
}
int ra(int a[])
{
	int m=a[0];
	for(int i=0; i<10; i++)
	{
		if(a[i]<m)
			m=a[i];
	}
	return m;
}