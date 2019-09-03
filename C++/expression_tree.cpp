// Expression Tree

#include<bits/stdc++.h>
using namespace std;

struct node{
	string data;
	node *left;
	node *right;
};

int evalTree(node *);
int main()
{
    int t;
    cin>>t;
    while(t--){
    int n;
    cin>>n;
	string s[n];
	for(int i=0;i<n;i++)
		cin>>s[i];
	int p=0;
	node *root = new node;
	root->data = s[p];
	root->left=NULL;
	root->right=NULL;
	queue<node *> q;
	q.push(root);
    p=1;
	while(!q.empty())
	{
		node *f = q.front();
		q.pop();
		node  *l,*r;
		if(p!=n){
        l=new node;
		l->data = s[p];
		f->left = l;
		p++;
		q.push(l);
	    }
	    else
	    {
	    	f->left = NULL;
	    }
		if(p!=n){
        r=new node;
		r->data = s[p];
		f->right = r;
		p++;
		q.push(r);
		}else
		{
			f->right=NULL;
		}
	}
	cout<<evalTree(root)<<endl;
    }
}

int strnum(string s)
{
    int n = 0;
    for(int i=0; i<s.length(); i++)
    {
        n = 10*n + (s[i] - 48);
    }
    return n;
}

int evalTree(node* root)
{
    if(root->left == NULL && root->right == NULL)  
        return strnum(root->data);
    int x = evalTree(root->left);
    int y = evalTree(root->right);
    if(root->data == "+")  return x+y;
    else if(root->data == "-")  return x-y;
    else if(root->data == "*")  return x*y;
    else  return x/y;
}