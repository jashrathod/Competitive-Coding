// Top View of Binary Tree

#include <bits/stdc++.h>
using namespace std;

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
void topView(struct Node *root);

int main()
{
  int t;
  struct Node *child;
  cin >> t;
  while (t--)
  {
     map<int, Node*> m;
     int n;
     cin >> n;
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
     topView(root);
     cout << endl;
  }
  return 0;
}

void topviewfn(Node *root, int hd, int &min, int &max, unordered_map<int, pair<int, int>> &m, int ht)
{
    if(root == NULL)  return;
    
    if(hd < min) 
    {
        min = hd;
        m[hd].first = root->data;
        m[hd].second = ht;
    }
    if(hd > max) 
    {
        max = hd;
        m[hd].first = root->data;
        m[hd].second = ht;
    }
    if(min <= hd && hd <= max && m[hd].second > ht)
    {
        m[hd].first = root->data;
        m[hd].second = ht;
    }
    
    topviewfn(root->left, hd-1, min, max, m, ht+1);
    topviewfn(root->right, hd+1, min, max, m, ht+1);
}

void topView(struct Node *root)
{
    unordered_map<int, pair<int, int>> m;
    int min = INT_MAX, max = INT_MIN;
    topviewfn(root, 0, min, max, m, 0);
    for(int i=min; i<=max; i++)
    {
        cout<<m[i].first<<" ";
    }
}