// Sort a Stack

void SortedStack :: sort()
{
    if(s.empty())  return;
    int temp = s.top();
    s.pop();
    sort();
    
    stack<int> t;
    while(!s.empty() && s.top() > temp)
    {
        t.push(s.top());
        s.pop();
    }
    s.push(temp);
    while(!t.empty())
    {
        s.push(t.top());
        t.pop();
    }
}