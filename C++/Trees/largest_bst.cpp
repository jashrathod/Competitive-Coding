// Largest BST

#include <bits/stdc++.h>
using namespace std;
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct Node* newNode(int data)
{
  struct Node* node = new Node;
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return(node);
}
void inorder(Node *root)
{
    if (root == NULL)
       return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);    
}
int largestBst(Node *root);
/* Driver program to test size function*/
int main()
{
  int t;
  scanf("%d
", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     struct Node *root = NULL;
     struct Node *child;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
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
    cout<<largestBst(root)<< endl;
  }
  return 0;
}

int max(int a, int b, int c)
{
    if(a>=b && a>=c)  return a;
    else if(b>=a && b>=c)  return b;
    return c;
}

bool isBST(Node *root, int l, int r)
{
    if(root == NULL)  return true;
    if(root->data < l || root->data > r)  return false;
    return isBST(root->left, l, root->data) &
           isBST(root->right, root->data, r);
}

int sizeBST(Node *root)
{
    if(root == NULL)  return 0;
    return 1 + sizeBST(root->left) + sizeBST(root->right);
}

int largestBst(Node *root)
{
    if(root == NULL)  return 0;
    int s = 0;
    if(isBST(root, INT_MIN, INT_MAX))
    {
        int x = sizeBST(root);
        if(s < x)  s = x;
    }
    return max(s, largestBst(root->left), largestBst(root->right));
}