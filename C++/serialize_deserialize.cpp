// SERIALIZE AND DESERIALIZE

void serialize(Node *root,vector<int> &A)
{

    queue<Node* >q;
    q.push(root);
    A.push_back(root->data);
    while(!q.empty())
    {
        Node* t = q.front();
        q.pop();
        
        if(t->left)
        {
            q.push(t->left);
            A.push_back(t->left->data);
        }
        else A.push_back(-1);

        if(t->right)
        {
            q.push(t->right);
            A.push_back(t->right->data);
        }
        else A.push_back(-1);
    }
}

Node * deSerialize(vector<int> &A)
{
    Node * root;
    if(A[0]!=-1) root = newNode(A[0]);
    else root = NULL;
    queue<Node*>q;
    q.push(root);
    int i=0;
    while(!q.empty())
    {
        Node* t = q.front();
        q.pop();
        if(A[i+1]!=-1)
        {
            t->left = newNode(A[i+1]);
            q.push(t->left);
        }
        else t->left = NULL;
        
        if(A[i+2]!=-1)
        {
            t->right = newNode(A[i+2]);
            q.push(t->right);
        }
        else t->right = NULL;
        
        i+=2;
    }
    return root;
   
}