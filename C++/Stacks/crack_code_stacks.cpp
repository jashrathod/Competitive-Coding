#include<iostream>
using namespace std;

class Stack 
{
    struct stack_array{
        int a[n]
    };
    int n, a[n], pos;
    
    public:

        Stack(int n1)
        {
            n = n1;
            pos = 0;
        }

        int top()
        {
            return pos+1;
        }

        int peek()
        {
            return a[pos];
        }

        void push(int x)
        {
            if(pos == n-1)
                cout<<"OVERFLOW";
            else
            {
                a[pos] = x;
                pos++;
            }
        }

        int pop()
        {
            if(pos == 0)
                 cout<<"UNDERFLOW";
            else
                pos--;
        }

        void displayStack()
        {
            for(int i=0; i<=pos; i++)
                cout<<a[pos]<<" ";
        }
};

int main()
{
    Stack s(10);
    s.pop();
    s.push(2);
    s.push(4);
    s.push(3);
    s.push(1);
    s.pop();
    s.push(6);
    s.top();
    s.peek();
    s.push(12);
    s.top();
    s.peek();
    s.displayStack();
    return 0;
}