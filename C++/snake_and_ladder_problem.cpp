// Snake and Ladder Problem

#include <iostream>
#include <queue>
using namespace std;

int main() 
{
	int t;
	cin>>t;
	int a[30];
    bool vis[30];
	while(t--)
	{
	    int n;
	    cin>>n;
	    for(int i=0; i<30; i++)  
	    {
	        a[i] = i;
	        vis[i] = false;
	    }
	    for(int i=0; i<n; i++)
	    {
	        int x, y;
	        cin>>x>>y;
	        a[x-1] = y-1;
	    }
	    queue<int> q1, q2;
	    q1.push(0);
	    q2.push(0);
	    vis[0] = true;
	    while(q1.front() != 29)
	    {
	        int x = q1.front(), y = q2.front();
	        for(int i=1; i<=6; i++)
	        {
	            if(x+i < 30 && !vis[x+i])
	            {
	                q1.push(a[x+i]);
	                q2.push(y+1);
	                vis[x+i] = true;
	                vis[a[x+i]] = true;
	            }
	        }
	        q1.pop();
	        q2.pop();
	    }
	    cout<<q2.front()<<endl;
	}
	return 0;
}