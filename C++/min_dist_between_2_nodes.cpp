// Min distance between two given nodes of a Binary Tree

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data)
{
  struct Node* node = (struct Node*)
                       malloc(sizeof(struct Node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return(node);
}
int findDist(Node* ,int ,int );

int main()
{
  int t;
  struct Node *child;
  scanf("%d
", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d
",&n);
     struct Node *root = NULL;
     if(n==1)
     {
        int a;
        cin>>a;
        cout<<a<<endl;
     }else{
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
      //  cout << n1 << " " << n2 << " " << (char)lr << endl;
        if (m.find(n1) == m.end())
        {
           parent = newNode(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];
        child = newNode(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }
     int a,b;
     cin>>a>>b;
     cout<<findDist(root,a,b)<<endl;
  }
  }
  return 0;
}
  
int max(int a, int b)  {  return (a>b) ? a : b;  }
   
Node* lca(Node* root, int a, int b)
{
    if(root == NULL)  return NULL;
    if(root->data == a || root->data == b)  return root;
    Node* l = lca(root->left, a, b);
    Node* r = lca(root->right, a, b);
    if(l && r)  return root;
    if(l)  return l;
    if(r)  return r;
    return NULL;
}

int dist(Node* root, int x)
{
    if(root == NULL)  return -100000;
    if(root->data == x)  return 1;
    return 1 + max(dist(root->left, x), dist(root->right, x));
}

int findDist(Node* root, int a, int b)
{
    Node *n = lca(root, a, b);
    int a_len = dist(root, a);
    int b_len = dist(root, b);
    int x_len = dist(root, n->data);
    return a_len + b_len - 2 * x_len;
} 