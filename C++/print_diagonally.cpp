// Print Diagonally

#include <iostream>
using namespace std;

void diagonal(int a[20][20], int n)
{
    int p=0, q=0, flag=0;
    while(q < n)
    {
        int i=p, j=q;
        while(j >= 0)
        {
            cout<<a[i][j]<<" ";
            i++;
            j--;
        }
        q++;
    }
    q--;
    p++;
    while(p < n)
    {
        int i=p, j=q;
        while(i < n)
        {
            cout<<a[i][j]<<" ";
            i++;
            j--;
        }
        p++;
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
	    int a[20][20];
	    for(int i=0; i<n; i++)
	        for(int j=0; j<n; j++)
	            cin>>a[i][j];
	    diagonal(a, n);
	    cout<<endl;
	}
	return 0;
}