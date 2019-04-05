// BALANCED BRACKETS

#include<iostream>
#include<stack>
#include<string.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	for(int j=0; j<n; j++)
	{
		stack <char> s;
		string b;
		int flag=0;
		cin>>b;
		for(int i=0; b[i]!='\0'; i++)
		{
			if(b[i]=='(' || b[i]=='{' || b[i]=='[')
				s.push(b[i]);
			else if((b[i]==')' && s.top()=='(') || 
				(b[i]=='}' && s.top()=='{') || (b[i]==']' && s.top()=='['))
				s.pop();
			else
			{
				flag=1;
				break;
			}
		}
		if(flag==0 && s.empty())
			cout<<"YES";
		else
			cout<<"NO";
		cout<<endl;
	}
	return 0;
}