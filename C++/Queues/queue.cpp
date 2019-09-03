// Queue

#include <iostream>

class queue
{
    int *a, n, f, b;
    
    public:
    
    queue(int x)
    {
        a = new int[x];
        n = x;
        f = -1;
        b = -1;
    }
    
    bool empty()
    {
        if(f == -1 && b == -1)  return true;
        else  return false;
    }
    
    int front()
    {
        return a[f];
    }
    
    void push(int x)
    {
        if(b == n-1)  b = 0;
        else  b++;
        a[b] = x;
        if(f == -1)  f++;
    }
    
    void pop()
    {
        if(f == b)  
        {
            f = -1;
            b = -1;
        }
        else if(f == n-1)  f = 0;
        else  f++;
    }

};

int main() 
{
    int x, y, z;
	std::cin>>x>>y>>z;
	queue q(3);
	std::cout<<q.empty()<<std::endl;
	q.push(x);
	q.push(y);
	std::cout<<q.front()<<std::endl;
	q.pop();
	std::cout<<q.front()<<std::endl;
	q.push(z);
	std::cout<<q.empty()<<std::endl;
	return 0;
}