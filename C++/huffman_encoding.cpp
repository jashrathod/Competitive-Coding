// Huffman Encoding

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    
    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

class myComparator 
{ 
public: 
    int operator() (const Node *p1, const Node *p2) 
    { 
        return p1->data > p2->data; 
    } 
};

void preorder(Node *n, string s)
{
    if(n->left == NULL && n->right == NULL)
    {
        cout<<s<<" ";
        return;
    }
    preorder(n->left, s+"0");
    preorder(n->right, s+"1");
}

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    string s;
	    cin>>s;
	    int a[s.size()];
	    priority_queue<Node *, vector<Node *>, myComparator> q;
	    for(int i=0; i<s.size(); i++)  
	    {
	        cin>>a[i];
	        q.push(new Node(a[i]));
	    }
	    while(q.size() != 1)
	    {
	        Node *x = q.top();
	        q.pop();
	        Node *y = q.top();
	        q.pop();
	        Node *n = new Node(x->data + y->data);
	        n->left = x;
	        n->right = y;
	        q.push(n);
	    }
	    preorder(q.top(), "");
	    cout<<endl;
	}
	return 0;
}