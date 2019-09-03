// Count Pairs whose sum is equal to X

#include <bits/stdc++.h>
using namespace std;
struct Node
{
int data;
struct Node* next;
};
void append(struct Node** headRef, int newData)
{
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
	struct Node *last = *headRef;
	new_node->data = newData;
	new_node->next = NULL;
	if (*headRef == NULL)
	{
	    *headRef = new_node;
	    return;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = new_node;
	return;
}
void printList(struct Node* head){
    while(head){
        cout<<head->data<<' ';
        head = head->next;
    }
}
int countPairs(struct Node* head1, struct Node* head2,	int x);

int main()
{
    int T;
    cin>>T;
    while(T--){
        struct Node* head1 = NULL;
	    struct Node* head2 = NULL;
	    int n1, n2, tmp, x;
	    cin>>n1;
	    while(n1--){
	        cin>>tmp;
	        append(&head1, tmp);
	    }
	    cin>>n2;
	    while(n2--){
	        cin>>tmp;
	        append(&head2, tmp);
	    }
	    cin>>x;
	    cout<<countPairs(head1, head2, x)<<'
';
    }
	return 0;
}

int countPairs(struct Node* head1, struct Node* head2,	int x)
{
    unordered_set<int> s;
    Node *ptr = head1;
    while(ptr != NULL)
    {
        s.insert(x - ptr->data);
        ptr = ptr->next;
    }
    ptr = head2;
    int c = 0;
    while(ptr != NULL)
    {
        if(s.find(ptr->data) != s.end())  c++;
        ptr = ptr->next;
    }
    return c;
}