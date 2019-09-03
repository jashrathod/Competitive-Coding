// STACKS USING ARRAYS

#include<iostream>
#include<string.h>
#include<stack>
using namespace std;

const int MAX=100;
char s[MAX];
int top = -1;
void push(char);
void pop();
char peek();

int main()
{
	char input[MAX];
	cin>>input;
	for(int i=0; input[i]!='\0'; i++)
	{
		if(input[i]=='(' || input[i]=='*' || input[i]=='/' || input[i]=='%')
			push(input[i]);
		else if(input[i]=='-' || input[i]=='+')
		{
			if(top==-1)
				push(input[i]);
			else if(peek()=='*' || peek()=='/' || peek()=='%')
			{
				pop();
				push(input[i]);
			}
			else
				push(input[i]);
		}
		else if(input[i]==')')
		{
			while(peek()!='(')
				pop();
			pop();
		}
		else
			cout<<input[i];
	}
	while(top!=-1)
		pop();
	cout<<endl;
	return 0;
}

void push(char t)
{
	if(top==MAX-1)
		cout<<"\noverflow";
	else
	{
		top++;
		s[top]=t;
	}
}

void pop()
{
	if(top==-1)
		cout<<"\nunderflow";
	else if(peek()=='(')
		top--;
	else
	{
		cout<<peek();
		top--;
	}
}

char peek()
{
	return s[top];
}
