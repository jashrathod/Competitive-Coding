// FIXING TWO NODES OF A BST

void inorderr(struct Node * r, vector <int> &v)
{
    if(r == NULL)  return ;
    inorderr(r->left,v);
    v.push_back(r->data);
    inorderr(r->right,v);
}

struct Node * newnode(int d)
{
    struct Node * nn = (struct Node *)malloc(sizeof(struct Node));
    nn->data = d;
    nn->left = nn->right = NULL;
    return nn;
}

struct Node * insertt(struct Node * r, int d)
{
    if(r == NULL)  return newnode(d);
    if(r->data > d)  r->left = insertt(r->left,d);
    else if(r->data < d)  r->right = insertt(r->right,d);
    return r;
}

int indexx;

void inorderupdate(struct Node * r, vector <int> v)
{
    if(r == NULL)  return;
    inorderupdate(r->left,v);
    r->data = v[indexx];
    indexx++;
    inorderupdate(r->right,v);
}

struct Node *correctBST( struct Node* root )
{
    vector <int> v;
    inorderr(root,v);
    sort(v.begin(),v.end());
    indexx = 0;
    inorderupdate(root,v);
    return root;
}
