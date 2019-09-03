// Special Stack

void push(int a)
{
     s.push(a);
}
bool isFull(int n)
{
     return (s.size() >= n) ? true : false;
}
bool isEmpty()
{
    return (s.empty()) ? true : false;
}
int pop()
{
    int x = s.top();
    s.pop();
    return x;
}
int getMin()
{
    stack<int> t;
    int m;
    while(!s.empty())
    {
        if(t.empty() || m > s.top())
        {
            m = s.top();
        }
        t.push(s.top());
        s.pop();
    }
    while(!t.empty())
    {
        s.push(t.top());
        t.pop();
    }
    return m;
}