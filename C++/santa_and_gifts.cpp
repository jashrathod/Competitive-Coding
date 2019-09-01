// Santa and Gifts

#include <bits/stdc++.h>
using namespace std;

int fn(vector<int> &a, int n, int c)
{
    sort(a.begin(), a.end());
    vector<int>::iterator it; 
    while(a.size() != c)
    {
        int x = a[0] + a[1], i;
        it = a.begin();
        a.erase(it); 
        it = a.begin(); 
        a.erase(it);
        a.push_back(x);
        
        for(i = a.size()-2; a[i]>x; i--)
            a[i+1] = a[i];
        
        a[i+1] = x;
    }
    return a[c-1];
}

int main() 
{
	int t, n, c, x;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    vector<int> a;
	    for(int i=0; i<n; i++)  
	    {
	        cin>>x;
	        a.push_back(x);
	    }
	    cin>>c;
	    if(c>n)  cout<<-1<<endl;
	    else  cout<<fn(a, n, c)<<endl;
	}
	return 0;
}
