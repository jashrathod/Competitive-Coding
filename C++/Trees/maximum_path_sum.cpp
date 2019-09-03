// MAXIMUM PATH SUM

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node *left, *right;
};

Node *newNode(int data)
{
    Node *node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}

int maxPathSum(struct Node *root);

void insert(Node *root, int a1,int a2, char lr)
{
	if(root==NULL)
		return ;
	if(root->data==a1)
    {
		switch(lr)
        {
			case 'L':root->left=newNode(a2);
					break;
			case 'R':root->right=newNode(a2);
					break;
		}
	}
	insert(root->left,a1,a2,lr);
	insert(root->right,a1,a2,lr);
}
void inorder(Node *root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main()
{
	int t;
	cin>>t;
	while(t--)
    {
		int n;
		cin>>n;
		Node *root=NULL;
		while(n--)
        {
			int a1,a2;
			char lr;
			cin>>a1>>a2>>lr;
			if(root==NULL)
            {
				root=newNode(a1);
				switch(lr){
					case 'L':root->left=newNode(a2);
							break;
					case 'R':root->right=newNode(a2);
							break;
				}
			}
			else
				insert(root,a1,a2,lr);
		}
		cout<<maxPathSum(root)<<endl;		
	}
}

int fn(struct Node *root, int &res) 
{ 
    if (root == NULL)  return 0; 
    if (!root->left && !root->right)  return root->data; 
  
    int ls = fn(root->left, res); 
    int rs = fn(root->right, res); 
  
    if (root->left && root->right) 
    { 
        res = max(res, ls + rs + root->data); 
        return max(ls, rs) + root->data; 
    } 
    
    return (!root->left) ? rs + root->data : ls + root->data; 
} 

int maxPathSum(struct Node *root)
{
    int res = INT_MIN; 
    fn(root, res); 
    return res; 
}
