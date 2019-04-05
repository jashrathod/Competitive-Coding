// GAME OF TWO STACKS 

#include<iostream>
#include<stack>
#include<string.h>
using namespace std;

int main()
{
	int g, n[2], x, a, c, sum;
	cin>>g;
	for(int k=0; k<g; k++)
	{
		c=sum=0;
		cin>>n[0]>>n[1]>>x;
		stack <int> s[2], t[2];
		for(int i=0; i<2; i++)
		{
			for(int j=0; j<n[i]; j++)
			{
				cin>>a;
				s[i].push(a);
			}  
			while(!s[i].empty())
			{
				int x=s[i].top();
				s[i].pop();
				t[i].push(x);
			}	
		}
		while(sum<=x)
		{
			int y, flag=0;
			if(t[0].empty() && t[1].empty())
				flag=1;
			else if(t[0].empty())
			{	
				y=t[1].top();
				t[1].pop();
			}
			else if(t[1].empty())
			{	
				y=t[0].top();
				t[0].pop();
			}
			else if(t[0].top()>t[1].top())
			{	
				y=t[1].top();
				t[1].pop();
			}
			else
			{	
				y=t[0].top();
				t[0].pop();
			}
			
			c++;
			if(flag==0)
				sum=sum+y;
			else
				sum=y+1;
		}
		c--;
		cout<<c<<endl;
	}	
	return 0;
}