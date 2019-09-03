// Merge Sort for Linked List

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("
");
}
void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        a = mergeSort(a);
        printList(a);
    }
    return 0;
}  

int length(Node *n)
{
    int l = 0;
    while(n)
    {
        l++;
        n = n->next;
    }
    return l;
}

Node* merge(Node *p1, Node *p2)
{
    if(p1 == NULL)  return p2;
    if(p2 == NULL)  return p1;
    Node *res=NULL;
    if(p1->data < p2->data)
    {
        res = p1;
        res->next = merge(p1->next, p2);
    }
    else
    {
        res = p2;
        res->next = merge(p1, p2->next);
    }
    return res;
}

Node* mergeSort(Node* head) 
{
    if(head->next == NULL)  return head;
    int n = length(head), k;
    if(n%2 == 0)  k = n/2;
    else  k = n/2 + 1;
    Node *p1=head, *p2=head, *temp;
    while(k--)
    {
        temp = p2;
        p2 = p2->next;
    }
    temp->next = NULL;
    p1 = mergeSort(p1);
    p2 = mergeSort(p2);
    return merge(p1, p2);
}