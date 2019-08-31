// Y FORMATION

#include<bits/stdc++.h>

int intersectPoint(Node* head1, Node* head2)
{
    unordered_set<Node*> s;
    Node *ptr1=head1, *ptr2=head2;
    while(ptr1 != NULL)
    {
        s.insert(ptr1);
    }
    while(ptr2 != NULL)
    {
        if(s.find(ptr2) != s.end())
        {
            return ptr2->data;
        }
        ptr2 = ptr2->next;
    }
    return -1;
}