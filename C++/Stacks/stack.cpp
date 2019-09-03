// Stack

#include <iostream>

class stack
{
    int *a, n, i;
    
    public:
    
    stack(int x)
    {
        a = new int[x];
        n = x;
        i = -1;
    }
    
    bool empty()
    {
        if(i == -1)  return true;
        else  return false;
    }
    
    int top()
    {
        return a[i];
    }
    
    void push(int x)
    {
        i++;
        a[i] = x;
    }
    
    void pop()
    {
        i--;
    }

};

int main() 
{
    int x, y, z;
	std::cin>>x>>y>>z;
	stack s(3);
	std::cout<<s.empty()<<std::endl;
	s.push(x);
	s.push(y);
	std::cout<<s.top()<<std::endl;
	s.pop();
	s.push(z);
	std::cout<<s.empty()<<std::endl;
	return 0;
}