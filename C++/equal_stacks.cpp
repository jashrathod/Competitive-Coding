// EQUAL STACKS

#include<iostream>
#include<stack>
#include<string.h>
using namespace std;

int main()
{
	int n[3], sum[3], a;
	stack <int> s[3], t[3];
	cin>>n[0]>>n[1]>>n[2];
	sum[0]=sum[1]=sum[2]=0;
	for(int i=0; i<3; i++)
	{
		for(int j=0; j<n[i]; j++)
		{
			cin>>a;
			sum[i]=sum[i]+a;
			s[i].push(a);
		}
		while(!s[i].empty())
		{
			int x=s[i].top();
			s[i].pop();
			t[i].push(x);
		}	
	}
	while(sum[0]!=sum[1] || sum[1]!=sum[2] || sum[0]!=sum[2])
	{
		int flag=0;
		if(sum[0]>sum[1] && sum[0]>sum[2])
		{
			sum[0]=sum[0]-t[0].top();
			t[0].pop();
			flag=1;
		}	
		if(sum[1]>sum[0] && sum[1]>sum[2])
		{
			sum[1]=sum[1]-t[1].top();
			t[1].pop();
			flag=1;
		}	
		if(sum[2]>sum[1] && sum[2]>sum[0])
		{
			sum[2]=sum[2]-t[2].top();
			t[2].pop();
			flag=1;
		}	
		if(flag==0)
		{
			if(sum[0]==sum[1])
			{
				sum[0]=sum[0]-t[0].top();
				t[0].pop();
				sum[1]=sum[1]-t[1].top();
				t[1].pop();
			}
			else if(sum[1]==sum[2])
			{
				sum[1]=sum[1]-t[1].top();
				t[1].pop();
				sum[2]=sum[2]-t[2].top();
				t[2].pop();
			}
			else
			{
				sum[0]=sum[0]-t[0].top();
				t[0].pop();
				sum[2]=sum[2]-t[2].top();
				t[2].pop();
			}
		}
	}
	cout<<sum[0];
	return 0;
}