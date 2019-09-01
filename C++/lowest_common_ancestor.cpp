// LOWEST COMMON ANCESTOR

// Method 1

Node *p = NULL;
bool lca1(Node* node, int n1, int n2)
{
    if(node == NULL)  return false;
    else if(node->left == NULL && node->right == NULL)
    {
        if(node->data == n1 || node->data == n2)  return true;
        else  return false;
    }
    else if(node->data == n1 || node->data == n2)
    {
        bool x = lca1(node->left, n1, n2);
        bool y = lca1(node->right, n1, n2);
        bool z = true;
        if(x == false && y == false)  return true;
        else 
        {
            p=node;
            return true;
        }
    }
    else
    {
        bool x = lca1(node->left, n1, n2);
        bool y = lca1(node->right, n1, n2);
        if(x == false && y == false)  return false;
        else if(x == true && y == true)
        {
            p=node;
            return true;
        }
        else  return true;
    }
}

Node* lca(Node* root ,int n1 ,int n2 )
{
    bool t = lca1(root, n1, n2);
    Node *q = p;
    p = NULL;
    return q;
}

Node* lca(Node* root ,int n1 ,int n2 )
{
    if (root == NULL) return NULL; 
    if (root->data == n1 || root->data == n2) 
        return root; 
  
    Node *left_lca  = lca(root->left, n1, n2); 
    Node *right_lca = lca(root->right, n1, n2); 
  
    if (left_lca && right_lca)  return root; 
    
    return (left_lca != NULL)? left_lca: right_lca;
}

// Method 2

Node * lca(Node* root , int n1, int n2)
{
    if(root == NULL) return NULL;
    if(root->data == n1 || root -> data == n2) return root;
    
    Node* l = lca(root -> left, n1, n2);
    Node* r = lca(root -> right, n1, n2);
    
    if(l && r) return root;
    if(l) return l;
    if(r) return r;
    return NULL;
}
