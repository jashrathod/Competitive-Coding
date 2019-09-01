// Next greater number set digits

#include <iostream>
#include <string.h>
using namespace std;

void next_greatest(string n)
{
    int l=n.size(), i;
    for(i=l-2; i>=0; i--)
    {
        if(n[i+1] > n[i])  break;
    }
    if(i == -1)
    {
        cout<<"not possible"<<endl;
        return;
    }
    int s = i+1;
    for(int j=i+1; j<l; j++)
    {
        if(n[j] > n[i] && n[j] < n[s])  s = j;
    }
    int t = n[s];
    n[s] = n[i];
    n[i] = t;
    for(int p=i+1; p<l; p++)
    {
        for(int q=i+1; q<l-p+i; q++)
        {
            if(n[q] > n[q+1])
            {
                int z = n[q];
                n[q] = n[q+1];
                n[q+1] = z;
            }
        }
    }
    cout<<n<<endl;
}

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    string n;
	    cin>>n;
	    next_greatest(n);
	}
	return 0;
}