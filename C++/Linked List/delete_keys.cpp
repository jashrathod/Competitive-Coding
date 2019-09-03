// Delete keys in a Linked list

#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
};
void append(struct Node** head_ref, struct Node **tail_ref,
           int new_data)
{
    struct Node* new_node = new Node;
    new_node->data  = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL)
       *head_ref = new_node;
    else
       (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}

struct Node* deleteAllOccurances(struct Node *head,int );
void printList(Node *head)
{
   while (head != NULL)
   {
      cout << head->data << " ";
      head = head->next;
   }
   cout << "
";
}

int main()
{
  int T,i,n,l;
  for (int i=0; i<2000; i++);
    cin>>T;
    while(T--){
    struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        for(i=1;i<=n;i++)
        {
            cin>>l;
            append(&head, &tail, l);
        }
	int kk;
	cin>>kk;
    head =deleteAllOccurances(head,kk);
    printList(head);
    }
    return 0;
}

Node* deleteAllOccurances(Node *head, int x)
{
    while(head->data == x)
    {
        Node *t = head;
        head = head->next;
        delete t;
    }
    if(head)
    {
        Node *p = head->next, *q = head;
        while(p)
        {
            if(p->data == x)
            {
                q->next = p->next;
                Node *t = p;
                p = p->next;
                delete t;
            }
            else
            {
                q = p;
                p = p->next;
            }
        }
    }
    return head;
}