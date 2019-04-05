// TEXT EDITOR

#include<iostream>
#include<stdlib.h> 
// #include<assert.h>
#include<string.h>
#include<stack>
using namespace std;

int main()
{
	int q;
	cin>>q;
	for(int i=0; i<q; i++)
	{
		int c, d;
		string str;
		stack <char> s, t;
		cin>>c;
		if(c==1)
		{
			cin>>str;
			for(int j=0; str[j]!='\0'; j++)
			{
				s.push(str[j]);
			}
		}
		else if(c==2)
		{
			cin>>d;
			for(int j=0; j<d; j++)
			{
				s.pop();
			}
		}
		else if(c==3)
		{
			cin>>d;
			while(!s.empty())
			{
				t.push(s.top());
				s.pop();
			}
			for(int j=0; j<d; j++)
			{
				s.push(t.top());
				t.pop();
			}
			cout<<s.top()<<endl;
			while(!s.empty())
			{
				s.push(t.top());
				t.pop();
			}
		}
	}
	return 0;
}