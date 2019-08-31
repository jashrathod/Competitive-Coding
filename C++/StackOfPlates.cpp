#include<iostream>
using namespace std;

class LinkedList
{
    struct node
    {
        int data;
        node* next;
    };

    node* start;
    node* top;
    node* ptr;
    int n, curr_len;
    

    public:

    LinkedList()
    {
        start = NULL;
    }

    void add_linked_list(int key)
    {
        node* newnode = new node;
        newnode->data = key;
        newnode->next = NULL;
        if(start == NULL)
        {
            start =  newnode;
            top = newnode;
        }
        else
        {
            top->next = newnode;
            top = newnode;
        }
    }

    void delete_linked_list()
    {
        ptr = start;
        while(ptr->next != top)
            ptr = ptr->next;
        top = ptr;
        ptr = ptr->next;
        free(ptr);
        top->next = NULL;
    }

    void display_linked_list()
    {
        ptr = start;
        while(ptr != NULL)
        {
            cout<<ptr->data<<" ";
            ptr = ptr->next;
        }
    }
};


int main()
{
    LinkedList l;
    // for(int i=0; i<10; i++)
    //     l.add_linked_list(10+i);

    // l.display_linked_list();

    // for(int i=0; i<3; i++)
    //     l.delete_linked_list();

    // l.display_linked_list();



    return 0;
} 