// Minimum Cost of Ropes

#include <iostream>
#include <queue>
using namespace std;

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    long long int n, sum=0;
	    cin>>n;
	    long long int a[n];
	    priority_queue<long long int, vector<long long int>, greater<long long int>> q;
	    for(int i=0; i<n; i++)
	    {
	        cin>>a[i];
	        q.push(a[i]);
	    }
	    while(q.size() != 1)
	    {
	        long long int x = q.top();
	        q.pop();
	        long long int y = q.top();
	        q.pop();
	        q.push(x+y);
	        sum = sum + x + y;
	    }
	    cout<<sum<<endl;
	}
	return 0;
}