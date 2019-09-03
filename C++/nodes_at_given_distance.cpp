// Nodes at given distance in binary tree

// 1

#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *left, *right;
};

int counter=0;
int target=0;
struct node *ptr=NULL;
void printkdistanceNodeDown(node *root, int k);
int printkdistanceNode(node* root, node* target , int k);

node *newnode(int data)
{
    node *temp = new node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
 void insert(struct node *root,int n1,int n2,char lr)
 {
     if(root==NULL)
        return;
     if(root->data==n1)
     {
         switch(lr)
         {
          case 'L': root->left=newnode(n2);
                    break;
          case 'R': root->right=newnode(n2);
                    break;
         }
     }
     else
     {
         insert(root->left,n1,n2,lr);
         insert(root->right,n1,n2,lr);
     }
 }
 void Inorder(struct node* root)
{
    if(counter==0)
    {
        cin>>target;
        counter++;
    }
    if(root==NULL)
        return ;
    Inorder(root->left);
    if(root->data==target)
         ptr=root;
    Inorder(root->right);
}

int main()
{
    int t,k;
    cin>>t;
    while(t--)
    {
    int n;
    cin>>n;
    struct node *root=NULL;
    while(n--)
    {
        char lr;
        int n1,n2;
        cin>>n1>>n2;
        cin>>lr;
        if(root==NULL)
        {
            root=newnode(n1);
            switch(lr){
                    case 'L': root->left=newnode(n2);
                    break;
                    case 'R': root->right=newnode(n2);
                    break;
                    }
        }
        else
        {
            insert(root,n1,n2,lr);
        }
    }
    Inorder(root);
    node * target =ptr;
    cin>>k;
    printkdistanceNode(root, target, k);
    cout<<endl;
    counter=0;
    }
    return 0;
}

void printkdistanceNodeDown(node *root, int k)
{
    if(root == NULL || k < 0)  return;
    if(k == 0)  
    {
        cout<<root->data<<" ";
        return;
    }
    printkdistanceNodeDown(root->left, k-1);
    printkdistanceNodeDown(root->right, k-1);
}

int printkdistanceNode(node* root, node* target , int k)
{
    if (root == NULL) return -1; 
    if (root == target) 
    { 
        printkdistanceNodeDown(root, k); 
        return 0; 
    } 

    int dl = printkdistanceNode(root->left, target, k); 
    if (dl != -1) 
    { 
         if (dl + 1 == k) 
            cout << root->data << endl; 
         else
            printkdistanceNodeDown(root->right, k-dl-2); 
         return 1 + dl; 
    } 
  
    int dr = printkdistanceNode(root->right, target, k); 
    if (dr != -1) 
    { 
         if (dr + 1 == k) 
            cout << root->data << endl; 
         else
             printkdistanceNodeDown(root->left, k-dr-2);
         return 1 + dr; 
    } 

    return -1; 
}

// 2

#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *left, *right;
};

int counter=0;
int target=0;
struct node *ptr=NULL;
void printkdistanceNodeDown(node *root, int k);
int printkdistanceNode(node* root, node* target , int k);

node *newnode(int data)
{
    node *temp = new node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
 void insert(struct node *root,int n1,int n2,char lr)
 {
     if(root==NULL)
        return;
     if(root->data==n1)
     {
         switch(lr)
         {
          case 'L': root->left=newnode(n2);
                    break;
          case 'R': root->right=newnode(n2);
                    break;
         }
     }
     else
     {
         insert(root->left,n1,n2,lr);
         insert(root->right,n1,n2,lr);
     }
 }
 void Inorder(struct node* root)
{
    if(counter==0)
    {
        cin>>target;
        counter++;
    }
    if(root==NULL)
        return ;
    Inorder(root->left);
    if(root->data==target)
         ptr=root;
    Inorder(root->right);
}

int main()
{
    int t,k;
    cin>>t;
    while(t--)
    {
    int n;
    cin>>n;
    struct node *root=NULL;
    while(n--)
    {
        char lr;
        int n1,n2;
        cin>>n1>>n2;
        cin>>lr;
        if(root==NULL)
        {
            root=newnode(n1);
            switch(lr){
                    case 'L': root->left=newnode(n2);
                    break;
                    case 'R': root->right=newnode(n2);
                    break;
                    }
        }
        else
        {
            insert(root,n1,n2,lr);
        }
    }
    Inorder(root);
    node * target =ptr;
    cin>>k;
    printkdistanceNode(root, target, k);
    cout<<endl;
    counter=0;
    }
    return 0;
}

void f(node *T, node *prev, unordered_map <node * ,node*> &parent)
{
    if(T)
    {
        parent[T]=prev;
        f(T->left, T, parent);
        f(T->right, T, parent);
    }
}

int printkdistanceNode(node* root, node* target , int k)
{
    
    if(root == NULL || target == NULL)    
        return 0;
    
    node *p=NULL;
    unordered_map <node *, node *> parent;
    f(root,p, parent);
    
    queue <node*> q;    
    q.push(target);
    node *nl = new node(); 
    nl->data=-1;    
    nl->left=NULL;  
    nl->right=NULL;
    
    q.push(nl); int count=1;
    
    unordered_map <node *,int> visited;    
    visited[target]++;
    
    while(!q.empty())
    {
        node *temp = q.front();   q.pop();
        if(temp == nl)
        {
            if(q.empty())   break;
            if(k == count) 
            {
                while(!q.empty())
                {
                    cout << q.front()->data<<" ";
                    q.pop();
                }
                break;
            }
            count++;
            q.push(nl);
        }
        else
        {
            if(temp->left && visited.find(temp->left) == visited.end())
            {
                q.push(temp->left);
                visited[temp->left]++;
            }
            if(temp->right && visited.find(temp->right)  == visited.end())
            {
                q.push(temp->right);
                visited[temp->right];
            }
            if(parent[temp] && visited.find(parent[temp]) == visited.end())
            {
                q.push(parent[temp]);
                visited[parent[temp]]++;
            }
        }
    }
    return 1;
}