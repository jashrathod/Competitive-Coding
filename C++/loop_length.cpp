// Find Length of Loop

int countNodesinLoop(struct Node *head)
{
    Node *start, *ptr=head;
    Node *f=head->next->next, *s=head->next;
    while(s && f && f->next)
    {
        f = f->next->next;
        s = s->next;
        if(s == f)  break;
    }
    ptr = head;
    if(f == NULL || f->next == NULL)  return 0;
    else
    {
        unordered_set<Node *> s;
        while(s.find(ptr) == s.end())
        {
            s.insert(ptr);
            ptr = ptr->next;
        }
        start = ptr;
        int l=1;
        while(ptr->next != start)
        {
            l++;
            ptr = ptr->next;
        }
        return l;
    }
    return 1;
}