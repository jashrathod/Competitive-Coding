// BINARY TREE TO DOUBLY LINKED LIST

void inord(Node *n, queue<int> &q)
{
    if(n == NULL)  return;
    inord(n->left, q);
    q.push(n->data);
    inord(n->right, q);
}

void bToDLL(Node *root, Node **head_ref)
{
    queue<int> q;
    inord(root, q);
    Node* new_node1 = new Node(q.front());
    Node *p = new_node1;
    q.pop();
    *head_ref = new_node1;
    while(!q.empty())
    {
        Node* new_node = new Node(q.front());
        p->right = new_node;
        new_node->left = p;
        p = p->right;
        q.pop();
    }
    p->right = NULL;
}