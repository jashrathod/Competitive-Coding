// RIGHT VIEW OF BINARY TREE

#include <bits/stdc++.h>
using namespace std;
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

void rightView(struct Node *root);

int main()
{
  int t;
  struct Node *child;
  scanf("%d\n", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d\n",&n);
     struct Node *root = NULL;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
        if (m.find(n1) == m.end())
        {
           parent = new Node(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];
        child = new Node(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }
     rightView(root);
     cout << endl;
  }
  return 0;
}

void rightviewfn(Node *root, int &max_level, int level)
{
    if(root == NULL)  return;
    if(max_level < level)
    {
        cout<<root->data<<" ";
        max_level = level;
    }
    rightviewfn(root->right, max_level, level+1);
    rightviewfn(root->left, max_level, level+1);
}

void rightView(Node *root)
{
    int max_level = 0;
    rightviewfn(root, max_level, 1);
}
