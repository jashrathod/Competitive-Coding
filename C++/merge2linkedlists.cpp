// MERGE TWO LINKED LISTS

Node* sortedMerge(Node* head1,   Node* head2)
{
    if(head1 == NULL)  return head2;
    else if(head2 == NULL)  return head1;
    Node *ptr1, *ptr2, *ptr3, *temp_ptr, *head;
    if(head1->data < head2->data)
    {
        ptr1=head1->next;
        ptr3=head1;
        ptr2=head2;
    }
    else
    {
        ptr1=head2->next;
        ptr3=head2;
        ptr2=head1;
    }
    head = ptr3;
    while(ptr1 != NULL)
    {
        if(ptr2->data < ptr1->data)
        {
            temp_ptr=ptr2->next;
            ptr3->next=ptr2;
            ptr2->next=ptr1;
            ptr2=temp_ptr;
            ptr3=ptr3->next;
        }
        else
        {
            ptr3=ptr1;
            ptr1=ptr1->next;
        }
    }
    if(ptr2 != NULL)
        ptr3->next=ptr2;
    return head;
}