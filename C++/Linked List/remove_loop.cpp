// REMOVE THE LOOP IN A LINKED LIST

#include<bits/stdc++.h>

void removeTheLoop(Node *head)
{
    unordered_set<Node*> s;
    Node* ptr;
    while(head != NULL)
    {
        if(s.find(head) != s.end())
        {
            ptr->next = NULL;
        }
        else
        {
            ptr = head;
            head = head->next;   
        }
    }
}