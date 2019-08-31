// MAXIMUM ELEMENT IN STACK

#include<bits/stdc++.h>
using namespace std;

class _stack
{
    stack<int> s;
    int maxEle;
public :
    int getMax();
    int pop();
    void push(int);
};
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
       int q;
       cin>>q;
        _stack *a = new _stack();
       while(q--){
       int qt;
       cin>>qt;
       if(qt==1)
       {
           //push
           int att;
           cin>>att;
           a->push(att);
       }
       else if(qt==2)
       {
           //pop
           cout<<a->pop()<<" ";
       }
       else if(qt==3)
       {
           //getMax
           cout<<a->getMax()<<" ";
       }
       }
       cout<<endl;
   }
}

int _stack :: getMax()
{
    if(s.empty())  return -1;
    else  return maxEle;
}

int _stack ::pop()
{
    if(s.empty())  return -1;
    if(s.top() <= maxEle)  
    {
        int x = s.top();
        s.pop();
        return x;
    }
    int a = maxEle;
    maxEle = 2*maxEle - s.top();
    s.pop();
    return a;
}

void _stack::push(int x)
{
    if(s.empty())  
    {
        s.push(x);
        maxEle = x;
    }
    else if(x < maxEle)
    {
        s.push(x);
    }
    else
    {
        s.push(2*x - maxEle);
        maxEle = x;
    }
}
