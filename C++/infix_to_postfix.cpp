// Infix to Postfix

#include <iostream>
#include <stack>
#include <map>
using namespace std;

void postfix(string str)
{
    map<char,int> mp;
    mp['(']=0;
    mp['-']=2;
    mp['+']=2;
    mp['/']=3;
    mp['*']=3;
    mp['^']=5;
    stack<char> st;
    int i=0;
    while(str[i])
    {
        if(isalpha(str[i]))
        {
            cout<<str[i];
        }
        else
        if(str[i]=='(')
        {
            st.push('(');
        }
        else
        if(str[i]==')')
        {
            while(!st.empty())
            {
                char ch=st.top();
                st.pop();
                if(ch=='(')
                break;
                else
                cout<<ch;
            }
        }
        else
        if(st.empty() || mp[st.top()]<mp[str[i]])
        {
            st.push(str[i]);
        }
        else
        {
            while(!st.empty() && mp[str[i]]<=mp[st.top()])
            {
                char ch=st.top();
                st.pop();
                cout<<ch;
            }
            st.push(str[i]);
        }
        i++;
    }
    while(!st.empty())
    {
        char ch=st.top();
        st.pop();
        cout<<ch;
    }
    cout<<endl;
}

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    string s;
	    cin>>s;
	    postfix(s);
	}
	return 0;
}