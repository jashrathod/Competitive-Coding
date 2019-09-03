// Clone a linked list

Node *copyList(Node *head) 
{
    Node *ptr = head;
    Node *h = NULL, *p = NULL;
    Node *n = new Node(ptr->data);
    h = n;
    p = n;
    ptr = ptr->next;
    while(ptr != NULL)
    {
        Node *n = new Node(ptr->data);
        p->next = n;
        p = p->next;
        ptr = ptr->next;
    }
    ptr = head;
    p = h;
    while(p != NULL)
    {
        if(ptr->arb != NULL)
        {
            Node *q = h;
            while(q->data != ptr->arb->data)  q = q->next;
            p->arb = q;
        }
        ptr = ptr->next;
        p = p->next;
    }
    return h;
}
