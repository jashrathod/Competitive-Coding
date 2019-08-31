// MINIMUM ELEMENT IN STACK

#include<bits/stdc++.h>
using namespace std;
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
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
           //getMin
           cout<<a->getMin()<<" ";
       }
       }
       cout<<endl;
   }
}

int _stack :: getMin()
{
    if(s.empty())  return -1;
    else  return minEle;
}

int _stack ::pop()
{
    if(s.empty())  return -1;
    if(s.top() >= minEle)  
    {
        int x = s.top();
        s.pop();
        return x;
    }
    int a = minEle;
    minEle = 2*minEle - s.top();
    s.pop();
    return a;
}

void _stack::push(int x)
{
    if(s.empty())  
    {
        s.push(x);
        minEle = x;
    }
    else if(x > minEle)
    {
        s.push(x);
    }
    else
    {
        s.push(2*x - minEle);
        minEle = x;
    }
}
