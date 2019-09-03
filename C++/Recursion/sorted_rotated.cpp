// Minimum element in a sorted and rotated array

#include <iostream>
using namespace std;

int min(int x, int y)  {  return (x<y) ? x : y;  }

int fn(int a[], int i, int j)
{
    if(i == j)  return a[i];
    if(i+1 == j)  return min(a[i], a[j]);
    int k = (i+j)/2;
    if(a[k+1] > a[k] && a[k-1] > a[k])  return a[k];
    int x = fn(a, i, k-1);
    int y =  fn(a, k+1, j);
    return min(x, y);
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
	    for(int i=0;i<n; i++)
	        cin>>a[i];
	    cout<<fn(a, 0, n-1)<<endl;
	}
	return 0;
}
