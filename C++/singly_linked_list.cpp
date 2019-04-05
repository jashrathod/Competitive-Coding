// SINGLY LINKED LIST

#include<iostream>
#include<string.h>
#include<stack>
using namespace std;

class Queue
{
	struct node {
		int data;
		node* next;};
	node *ptr, *preptr, *postptr;
	node* start;
	int flag=0;
	
	public:
		Queue() {
			start=NULL;
		}

		void create(int x) {
			node *new_node = new node;
			new_node->data=x;
			new_node->next=NULL;

			if(start==NULL)
			{
				start=new_node;
			}
			else
			{
				ptr=start;
				while(ptr->next!=NULL)
					ptr=ptr->next;
				ptr->next=new_node;
			}
		}

		void add_beginning(int x) {
			node *new_node = new node;
			new_node->data=x;
			new_node->next=start;
			start=new_node;
		}

		void add_end(int x) {
			node *new_node = new node;
			new_node->data=x;
			new_node->next=NULL;
			ptr=start;
			while(ptr->next!=NULL)
				ptr=ptr->next;
			ptr->next=new_node;
		}		

		void add_after(int x, int y) {
			node *new_node = new node;
			new_node->data=x;
			preptr=start;
			ptr=start;
			while(preptr->data!=y)
			{
				preptr=ptr;
				ptr=ptr->next;
			}
			preptr->next=new_node;
			new_node->next=ptr;
		}

		void add_before(int x, int y) {
			node *new_node = new node;
			new_node->data=x;
			preptr=start;
			ptr=start;
			while(ptr->data!=y)
			{
				preptr=ptr;
				ptr=ptr->next;
			}
			preptr->next=new_node;
			new_node->next=ptr;
		}

		void delete_beginning() {
			ptr=start->next;
			start=ptr;
		}

		void delete_end() {
			ptr=start;
			preptr=ptr;
			while(ptr->next!=NULL)
			{
				preptr=ptr;
				ptr=ptr->next;
			}
		}

		void delete_middle(int y) {
			preptr=start;
			ptr=start;
			postptr=start;
			while(ptr->data!=y)
			{
				preptr=ptr;
				ptr=ptr->next;
				postptr=ptr->next;
			}
			preptr->next=postptr;
		}

		void delete_after(int y) {
			preptr=start;
			ptr=start;
			postptr=start;
			while(preptr->data!=y)
			{
				preptr=ptr;
				ptr=ptr->next;
				postptr=ptr->next;
			}
			preptr->next=postptr;
		}

		void delete_entire() {
			ptr=start;
			preptr=start;
			while(ptr->next!=NULL)
			{
				preptr=ptr;
				ptr=ptr->next;
				preptr=NULL;
			}
			flag=1;
		}

		void display() {
			ptr=start;
			if(flag==0)
			{
			while(ptr!=NULL)
			{
				cout<<ptr->data<<" ";
				ptr=ptr->next;
			}}
			else
				cout<<"entire linked list deleted.";
			cout<<endl;
		}
};

int main()
{
	Queue obj;

	obj.create(1);
	obj.create(2);
	obj.create(3);
	obj.create(4);
	obj.create(5);

	obj.add_beginning(0);
	obj.add_end(6);
	obj.add_after(20,2);
	obj.add_before(20,2);

	obj.delete_beginning();
	obj.delete_end();
	obj.delete_middle(3);
	obj.delete_after(2);
	obj.display();
	
	obj.delete_entire();
	obj.display();

	return 0;
}
