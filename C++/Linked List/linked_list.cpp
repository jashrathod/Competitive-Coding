// Linked List

#include <iostream>

class linkedlist
{
    struct Node
    {
        int data;
        Node *next;
        
        Node(int x)
        {
            data = x;
            next = NULL;
        }
    };
    Node *head = NULL;
    
    public:
    
    void add(int x)
    {
        Node *n = new Node(x);
        if(head == NULL)  head = n;
        else
        {
            Node *ptr = head;
            while(ptr->next != NULL)
                ptr = ptr->next;
            ptr->next = n;
        }
    }
    
    void display()
    {
        Node *ptr = head;
        while(ptr != NULL)
        {
            std::cout<<ptr->data<<" ";        
            ptr = ptr->next;
        }
    }
};

int main() 
{
    int x, y, z;
	std::cin>>x>>y>>z;
	linkedlist l;
	l.add(x);
	l.add(y);
	l.add(z);
	l.display();
	return 0;
}