// STOCK BUY AND SELL

#include <iostream>
using namespace std;

void maxProfit(long long a[], int n)
{
    int start=0, end=0, flag=0;
    for(int i=1; i<n; i++)
    {
        if(a[end] == a[end+1] && flag != 2)
        {
            start=i;
            end=i;
        }
        else if(a[i]>=a[end])
        {
            end=i; 
            flag=2;
        }
        else
        { 
            if (start != end && a[end]-a[start] > 0)  
            {
                cout<<"("<<start<<" "<<end<<") ";
                flag=1;
            }
            start=i;
            end=i;
        }
    }
    if(flag == 0)  cout<<"No Profit";
    else if(flag == 2)  cout<<"("<<start<<" "<<end<<") ";
}

int main() {
	int t, n;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    long long a[n];
	    for(int i=0; i<n; i++)
	        cin>>a[i];
	    maxProfit(a, n);
	    cout<<endl;
	}
	return 0;
}
