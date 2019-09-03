// max subarray

#include <iostream>
using namespace std;

int min_val=0;

// int max(int a, int b, int c)
// {
//     if(a >= b && a >= c)
//         return a;
//     if(b >= a && b >= c)
//         return b;
//     else return c;
// }

int max(int a, int b) { return (a > b)? a : b; } 
int max(int a, int b, int c) { return max(max(a, b), c); } 

int max_cross_over(int a[], int begin, int mid, int end)
{
    int sum=0, m=min_val-1;
    for(int i=mid; i>=begin; i--)
    {
        sum=sum+a[i];
        if(sum>m)  m=sum;
    }
    int left_max=m;
    sum=0;
    m=min_val-1;
    for(int i=mid+1; i<=end; i++)
    {
        sum=sum+a[i];
        if(sum>m)  m=sum;
    }
    int right_max=m;
    return (left_max + right_max);
}

int max_subarray(int a[], int begin, int end)
{
    if(begin == end) return a[begin];
    if(begin<end)
    {
        int mid=(begin+end)/2;
        return max(max_subarray(a, begin, mid), max_subarray(a, mid+1, end), max_cross_over(a, begin, mid, end));
    }
}

int main() 
{
	int t, n;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    int a[n];
	    cin>>a[0];
	    min_val=a[0];
	    for(int i=1; i<n; i++)
	    {
	        cin>>a[i];
	        if(a[i]<min_val)  min_val=a[i];
	    }
	    cout<<max_subarray(a, 0, n-1)<<endl;
	}
	return 0;
}
