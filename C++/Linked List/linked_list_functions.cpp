//LINKED LISTS

#include<iostream>
#include<stdlib.h> 
// #include<assert.h>
#include<string.h>
#include<stack>
using namespace std;

void add_begin(int d);
void add_end(int d);
void add_after(int d, int pos);
void add_before(int d, int pos);
void delete_begin();
void delete_end();
void delete_after(int pos);
void delete_before(int pos);
void reverse_linked_list();
void show();

struct node
{
	node *next;
	int data;
};
node *start=NULL, *ptr, *preptr;

int main()
{
	int t, d, pos;
	cin>>t;
	for(int i=0; i<t; i++)
	{
		cin>>d;
		add_end(d);
	} 
	// cin>>d>>pos;
	// add_after(d, pos);
	// show();
	// cin>>d>>pos;
	// add_before(d, pos);
	delete_before(4);
	delete_after(1);
	// reverse_linked_list();
	show();
	return 0;
}

void add_begin(int d)
{
	node *newnode=new node;
	newnode->data=d;
	newnode->next=NULL;
	if(start!=NULL)
		newnode->next=start;
	start=newnode;
}

void add_end(int d)
{
	node *newnode = new node;
	newnode->data=d;
	newnode->next=NULL;
	if(start==NULL)
		start=newnode;
	else
	{
		ptr=start;
		while(ptr->next!=NULL)
			ptr=ptr->next;
		ptr->next=newnode;
	}
}

void add_after(int d, int pos)
{
	node *newnode=new node;
	newnode->data=d;
	ptr=start;
	for(int i=0; i<pos; i++)
	{
		preptr=ptr;
		ptr=ptr->next;
	}
	preptr->next=newnode;
	newnode->next=ptr;
}

void add_before(int d, int pos)
{
	node *newnode=new node;
	newnode->data=d;
	ptr=start;
	for(int i=0; i<pos-1; i++)
	{
		preptr=ptr;
		ptr=ptr->next;
	}
	preptr->next=newnode;
	newnode->next=ptr;
}

void delete_begin()
{
	ptr=start;
	start=start->next;
	free(ptr);
}

void delete_end()
{
	ptr=start;
	while(ptr->next!=NULL)
	{
		preptr=ptr;
		ptr=ptr->next;
	}
	preptr->next=NULL;
	free(ptr);
}

void delete_after(int pos)
{
	ptr=start;
	for(int i=0; i<pos; i++)
	{
		preptr=ptr;
		ptr=ptr->next;
	}
	preptr->next=ptr->next;
	free(ptr);
}

void delete_before(int pos)
{
	ptr=start;
	for(int i=0; i<pos-2; i++)
	{
		preptr=ptr;
		ptr=ptr->next;
	}
	preptr->next=ptr->next;
	free(ptr);
}

// void reverse_linked_list()
// {
// 	node *start1=NULL;
// 	ptr=start;
// 	while(ptr!=NULL)
// 	{
// 		node *newnode=new node;
// 		newnode->data=ptr->data;
// 		newnode->next=NULL;
// 		if(start1!=NULL)
// 			newnode->next=start;
// 		start=newnode;
// 		ptr=ptr->next;
// 	}
// 	ptr=start1;
// 	while(ptr!=NULL)
// 	{
// 		cout<<ptr->data<<" ";
// 		ptr=ptr->next;
// 	}
// }

void show()
{
	// cout<<endl;
	ptr=start;
	while(ptr!=NULL)
	{	
		cout<<ptr->data<<endl;
		ptr=ptr->next;
	}
}