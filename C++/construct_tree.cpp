// Construct Tree from Preorder Traversal

Node* build(int v, int pre[], char pren[], int &node)
{
    if(node >= v) return NULL;
    Node* n = new Node;
    
    if(pren[node] == 'L')
    {
        n->data=pre[node];
        n->left=NULL;
        n->right=NULL;
        return n;
    }
    
    n->data = pre[node];
    node++;
    n->left = build(v, pre, pren, node);
    node++;
    n->right = build(v, pre, pren, node);
    return n;
}

struct Node *constructTree(int n, int pre[], char preLN[])
{
    int node=0;
    return build(n, pre, preLN, node);
}