// DIAMETER OF A BINARY TREE

int height(Node* n)
{
    if(n == NULL)  return 0;
    return 1 + max(height(n->left), height(n->right));
}
int diameter(Node* node)
{
    if(node == NULL)  return 0;
    return max(max(1 + height(node->left) + height(node->right), diameter(node->left)), diameter(node->right));
}



// LEFT VIEW OF BUNARY TREE

void leftViewUtil(Node *root, int level, int *max_level)  
{  
    if (root==NULL) return;    
    if (*max_level < level)  
    {  
        cout<<root->data<<" ";  
        *max_level = level;  
    }   
    leftViewUtil(root->left, level+1, max_level);  
    leftViewUtil(root->right, level+1, max_level);  
}  
  
void leftView(Node *root)  
{  
    int max_level = 0;  
    leftViewUtil(root, 1, &max_level);  
}  


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




// CHECK FOR BALANCED TREE

int max(int a, int b)
{
    if(a > b)  return a;
    else  return b;
}
int height(Node *node)
{
    if(node == NULL)  return 0;
    else  return 1 + max(height(node->left), height(node->right));
}
bool isBalanced(Node *node)
{
    if(node == NULL)  return true;
    int x = height(node->left);
    int y = height(node->right);
    if(abs(x-y) > 1)  return false;
    else if(x == 0 && y == 0)  return true;
    else 
        return (isBalanced(node->left) & isBalanced(node->right));
}


// LOWEST COMMON ANCESTOR

// Method 1

Node *p = NULL;
bool lca1(Node* node, int n1, int n2)
{
    if(node == NULL)  return false;
    else if(node->left == NULL && node->right == NULL)
    {
        if(node->data == n1 || node->data == n2)  return true;
        else  return false;
    }
    else if(node->data == n1 || node->data == n2)
    {
        bool x = lca1(node->left, n1, n2);
        bool y = lca1(node->right, n1, n2);
        bool z = true;
        if(x == false && y == false)  return true;
        else 
        {
            p=node;
            return true;
        }
    }
    else
    {
        bool x = lca1(node->left, n1, n2);
        bool y = lca1(node->right, n1, n2);
        if(x == false && y == false)  return false;
        else if(x == true && y == true)
        {
            p=node;
            return true;
        }
        else  return true;
    }
}

Node* lca(Node* root ,int n1 ,int n2 )
{
    bool t = lca1(root, n1, n2);
    Node *q = p;
    p = NULL;
    return q;
}

Node* lca(Node* root ,int n1 ,int n2 )
{
    if (root == NULL) return NULL; 
    if (root->data == n1 || root->data == n2) 
        return root; 
  
    Node *left_lca  = lca(root->left, n1, n2); 
    Node *right_lca = lca(root->right, n1, n2); 
  
    if (left_lca && right_lca)  return root; 
    
    return (left_lca != NULL)? left_lca: right_lca;
}

// Method 2

Node * lca(Node* root , int n1, int n2)
{
    if(root == NULL) return NULL;
    if(root->data == n1 || root -> data == n2) return root;
    
    Node* l = lca(root -> left, n1, n2);
    Node* r = lca(root -> right, n1, n2);
    
    if(l && r) return root;
    if(l) return l;
    if(r) return r;
    return NULL;
}


// LEVEL ORDER TRAVERSAL IN SPIRAL FORM

void printSpiral(Node *root)
{
    stack<Node*> s1, s2;
    s1.push(root);
    while(!s1.empty() || !s2.empty())
    {
        while(!s1.empty())
        {
            cout<<s1.top()->data<<" ";
            if(s1.top()->right)  s2.push(s1.top()->right);
            if(s1.top()->left)  s2.push(s1.top()->left);
            s1.pop();
        }
        while(!s2.empty())
        {
            cout<<s2.top()->data<<" ";
            if(s2.top()->left)  s1.push(s2.top()->left);
            if(s2.top()->right)  s1.push(s2.top()->right);
            s2.pop();
        }
    }
}



// PRINT VERTICAL ORDER

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

void verticalOrder(Node *root);

int main()
{
  int t;
  struct Node *child;
  scanf("%d", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
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
     verticalOrder(root);
     cout << endl;
  }
  return 0;
}

void verticalOrder(Node *root)
{ 
    if (!root)  return; 
  
    map < int, vector<int> > m; 
    int hd = 0; 
  
    queue<pair<Node*, int> > que; 
    que.push(make_pair(root, hd)); 
  
    while (!que.empty()) 
    { 
        pair<Node *,int> temp = que.front(); 
        que.pop(); 
        hd = temp.second; 
        Node* node = temp.first; 
        m[hd].push_back(node->data); 

        if (node->left != NULL) 
            que.push(make_pair(node->left, hd-1)); 
        if (node->right != NULL) 
            que.push(make_pair(node->right, hd+1)); 
    } 
    
    map< int, vector<int> > :: iterator it; 
    for (it=m.begin(); it!=m.end(); it++) 
    { 
        for (int i=0; i<it->second.size(); ++i) 
            cout << it->second[i] << " "; 
    } 
}





// BOTTOM VIEW OF BINARY TREE

void printBottomViewUtil(Node * root, int curr, int hd, map <int, pair <int, int>> & m) 
{ 
    if (root == NULL)  return; 
    if (m.find(hd) == m.end())  
    {
        m[hd] = make_pair(root -> data, curr); 
    }
    else 
    { 
        pair < int, int > p = m[hd]; 
        if (p.second <= curr) 
        { 
            m[hd].second = curr; 
            m[hd].first = root -> data; 
        } 
    } 
    printBottomViewUtil(root -> left, curr + 1, hd - 1, m); 
    printBottomViewUtil(root -> right, curr + 1, hd + 1, m); 
} 

void bottomView(Node *root)
{
    map <int, pair<int, int>> m; 
    printBottomViewUtil(root, 0, 0, m); 
      
    map < int, pair < int, int > > ::iterator it; 
    for (it = m.begin(); it != m.end(); ++it) 
    { 
        pair < int, int > p = it -> second; 
        cout << p.first << " "; 
    } 
}



// CHECK FOR BINARY SEARCH TREE

stack <int> s;
void inorder(Node* node)
{
    if(node == NULL)  return;
    if(node->left)  inorder(node->left);
    s.push(node->data);
    if(node->right)  inorder(node->right);
}
bool isBST(Node* root) 
{
    inorder(root);
    bool v = true;
    int p, flag = 0;
    if(!s.empty())
    {
        p = s.top();
        s.pop();
    }
    while(!s.empty())
    {
        if(s.top()>=p && flag == 0)  
        {
            flag = 1;
            v = false;
        }
        p = s.top();
        s.pop();    
    }
    return v;
}



// CONNECT NODES AT SAME LEVEL

void connectRecur(Node* p)  
{  
    if (p == NULL)  return;  
    
    Node *q;
    if (p->left && p->right)  
    {
        p->left->nextRight = p->right;  
        q = p->right;
    }
    else if(p->left)  q = p->left;
    else if(p->right)  q = p->right;
    
    if(p->nextRight != NULL && (p->left || p->right))
    {
        if (p->nextRight->left)  
            q->nextRight = p->nextRight->left;
        else if (p->nextRight->right)  
            q->nextRight = p->nextRight->right;
        else  q->nextRight = NULL;    
    }
    else
    {
        if (p->left && p->right)  p->right->nextRight = NULL;
        else if(p->left)  p->left->nextRight = NULL;
        else if(p->right)  p->right->nextRight = NULL;
    }
        
    connectRecur(p->left);  
    connectRecur(p->right);  
}

void connect(Node *p)  
{  
    p->nextRight = NULL;   
    connectRecur(p);  
}  



// SERIALIZE AND DESERIALIZE

void serialize(Node *root,vector<int> &A)
{

    queue<Node* >q;
    q.push(root);
    A.push_back(root->data);
    while(!q.empty())
    {
        Node* t = q.front();
        q.pop();
        
        if(t->left)
        {
            q.push(t->left);
            A.push_back(t->left->data);
        }
        else A.push_back(-1);

        if(t->right)
        {
            q.push(t->right);
            A.push_back(t->right->data);
        }
        else A.push_back(-1);
    }
}

Node * deSerialize(vector<int> &A)
{
    Node * root;
    if(A[0]!=-1) root = newNode(A[0]);
    else root = NULL;
    queue<Node*>q;
    q.push(root);
    int i=0;
    while(!q.empty())
    {
        Node* t = q.front();
        q.pop();
        if(A[i+1]!=-1)
        {
            t->left = newNode(A[i+1]);
            q.push(t->left);
        }
        else t->left = NULL;
        
        if(A[i+2]!=-1)
        {
            t->right = newNode(A[i+2]);
            q.push(t->right);
        }
        else t->right = NULL;
        
        i+=2;
    }
    return root;
   
}




// BINARY TREE TO DOUBLY LINKED LIST

void inord(Node *n, queue<int> &q)
{
    if(n == NULL)  return;
    inord(n->left, q);
    q.push(n->data);
    inord(n->right, q);
}

void bToDLL(Node *root, Node **head_ref)
{
    queue<int> q;
    inord(root, q);
    Node* new_node1 = new Node(q.front());
    Node *p = new_node1;
    q.pop();
    *head_ref = new_node1;
    while(!q.empty())
    {
        Node* new_node = new Node(q.front());
        p->right = new_node;
        new_node->left = p;
        p = p->right;
        q.pop();
    }
    p->right = NULL;
}



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



// REMOVE DUPLICATES FROM A STRING

#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
	    unordered_set<char> u;
	    queue<char> q;
	    string s;
	    getline(cin, s);
	    for(int i=0; i<s.size(); i++)
        {
            if(u.find(s[i]) == u.end())
            {
                u.insert(s[i]);
                q.push(s[i]);
            }
        }
	    while(!q.empty())
	    {
	        cout<<q.front();
	        q.pop();
	    }
	    cout<<endl;
    }
	return 0;
}



// NUMBER OF PATHS IN A MATRIX

#include <bits/stdc++.h>
using namespace std;
int m, n;
int path_matrix(int i, int j)
{
    if(i>=m || j>=n)  return 0;
    if(i==m-1 && j==n-1)  return 1;
    return path_matrix(i+1, j) + path_matrix(i, j+1);
}
int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    cin>>m>>n;
	    cout<<path_matrix(0,0)<<endl;
	}
	return 0;
}



// JOSEPHUS PROBLEM

int josephus(int n, int k)
{
    if(n == 1)  return 1;
    return (josephus(n-1, k) + k - 1) % n + 1;
}



// SPECIAL KEYBOARD

#include <bits/stdc++.h>
using namespace std;

int special(int N) 
{ 
	if (N <= 6) 
		return N; 

	int screen[N];
	int b; 
	int n; 
	
	for (n = 1; n <= 6; n++) 
		screen[n - 1] = n; 
		
	for (n = 7; n <= N; n++) 
	{ 
		screen[n - 1] = 0; 
		for (b = n - 3; b >= 1; b--) 
		{ 
			int curr = (n - b - 1) * screen[b - 1]; 
			if (curr > screen[n - 1]) 
				screen[n - 1] = curr; 
		} 
	} 
	return screen[N - 1]; 
} 

int main() 
{ 
	int t, n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<special(n)<<endl; 
    } 
} 



// RELATIVE SORTING

#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int t, m, n;
	cin>>t;
	while(t--)
	{
	    cin>>m>>n;
	    int a[m], b[n];
	    map<int, int> u;
	    for(int i=0; i<m; i++)  
	    {
	        cin>>a[i];
	        if(u.find(a[i]) == u.end())  u.insert(make_pair(a[i], 1));
	        else  u[a[i]]++;
	    }
	    for(int i=0; i<n; i++)  
	    {
	        cin>>b[i];
	        if(u.find(b[i]) != u.end())
	        {
	            for(int j=0; j<u[b[i]]; j++)  
	                cout<<b[i]<<" ";
	            u.erase(b[i]);
	        }
	    }
	    map<int, int> :: iterator it;
	    for(it=u.begin(); it!=u.end(); it++)
	    {
	        for(int i=0; i<(*it).second; i++)
	        {
	            cout<<(*it).first<<" ";
	        }
	    }
	    cout<<endl;
	}
	return 0;
}



// FIND ALL FOUR SUM NUMBERS


// Brute - Force

#include <bits/stdc++.h>
using namespace std;

void fn(vector<int> &v, int a, int b, int i1, int i2, int i3, int i4, set<string> &s)
{
    if(i1 == i2 || i1 == i3 || i1 == i4 || i2 == i3 || i2 == i4 || i3 == i4 || 
       i1 >= i2 || i2 >= i3 || i3 >= i4 || i4 >= a)
    {
        return;
    }
    int y = v[i1] + v[i2] + v[i3] + v[i4];
    if(b == y)
    {
        string s1 = to_string(v[i1]) + " ";
        s1 = s1 + to_string(v[i2]);
        s1 = s1 + " ";
        s1 = s1 + to_string(v[i3]);
        s1 = s1 + " ";
        s1 = s1 + to_string(v[i4]);
        s1 = s1 + " $";
        if(s.find(s1) == s.end())  
        {
            cout<<s1;
            s.insert(s1);
        }
    }
    if(i4+1 != a)  fn(v, a, b, i1, i2, i3, i4+1, s);
    if(i3+1 != i4)  fn(v, a, b, i1, i2, i3+1, i4, s);
    if(i2+1 != i3)  fn(v, a, b, i1, i2+1, i3, i4, s);
    if(i1+1 != i2)  fn(v, a, b, i1+1, i2, i3, i4, s);
}

int main() 
{
	int t, a, b, x;
	cin>>t;
	while(t--)
	{
	    cin>>a>>b;
	    int flag = 0;
	    vector<int> v;
	    for(int i=0; i<a; i++)  
	    {
	        cin>>x;
	        v.push_back(x);
	    }
	    if(a<4)  cout<<-1;
	    else
	    {
	        set<string> s;
	        sort(v.begin(), v.end());
    	    fn(v, a, b, 0, 1, 2, 3, s);
    	    if(!s.empty())
    	    {
    	       // set<string> :: iterator it;
        	   // for(auto it:s)
        	   //     cout<<it;
        	    flag = 1;
    	    }
	    }
	    if(flag == 0)  cout<<-1;
	    cout<<endl;
	}
	return 0;
}


// Efficient

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,i,j,k,l;
    cin>>t;
    while(t--)
    {
        int n,sum;
        cin>>n>>sum;
        int a[n];
        for(i=0;i<n;i++)
          cin>>a[i];
        sort(a,a+n);  
        int p=0;
        unordered_map<string,int>mp;
        for(i=0;i<n-3;i++)
        {
            for(j=i+1;j<n-2;j++)
            {
                for(k=j+1;k<n-1;k++)
                {
                    for(l=k+1;l<n;l++)
                    {
                       if(a[i]+a[j]+a[k]+a[l]==sum)
                       {
                       string x="";
                       x=to_string(a[i])+to_string(a[j])+to_string(a[k])+to_string(a[l]); 
                       if(mp[x]==0)
                       {
                          cout<<a[i]<<" "<<a[j]<<" "<<a[k]<<" "<<a[l]<<" "<<"$";
                          mp[x]++;
                       }
                       }
                    }
                }
            }
        }
        if(mp.size()==0)
          cout<<"-1";
        cout<<endl;
    }
}



// 0-1 KNAPSACK PROBLEM

#include<bits/stdc++.h>
using namespace std;
  
int max(int a, int b) { return (a > b)? a : b; } 
  
void knapSack(int W, int wt[], int val[], int n) 
{ 
  int i, w; 
  int K[n+1][W+1]; 
  
  for (i = 0; i <= n; i++) 
  { 
      for (w = 0; w <= W; w++) 
      { 
          if (i==0 || w==0) 
              K[i][w] = 0; 
          else if (wt[i-1] <= w) 
                 K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]); 
          else
                 K[i][w] = K[i-1][w]; 
      } 
  } 
  cout << K[n][W] << endl; 
} 
  
int main() 
{ 
    int t, w, n, x;
    cin>>t;
    while(t--)
    {
        cin>>n>>w;
        int val[n], wt[n];
        for(int i=0; i<n; i++)  cin>>val[i];
        for(int i=0; i<n; i++)  cin>>wt[i];
        knapSack(w, wt, val, n); 
    }
    return 0; 
} 




// Minimum number of jumps

#include <bits/stdc++.h>
using namespace std;

int min(int a, int b)  { return (a<b) ? a : b;  }

int minJumps(int arr[], int n)  
{  
    int *jumps = new int[n];   
    int i, j;  
  
    if (n == 0 || arr[0] == 0)  
        return INT_MAX;  
  
    jumps[0] = 0;  
    for (i = 1; i < n; i++)  
    {  
        jumps[i] = INT_MAX;  
        for (j = 0; j < i; j++)  
        {  
            if (i <= j + arr[j] && jumps[j] != INT_MAX)  
            {  
                jumps[i] = min(jumps[i], jumps[j] + 1);  
                break;  
            }  
        }  
    }  
    return jumps[n-1];  
}  
int main() 
{
	int t, n;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    int a[n];
	    for(int i=0; i<n; i++)  cin>>a[i];
	    int x = minJumps(a, n);
	    if(x == INT_MAX)  x = -1;
	    cout<<x<<endl;
	}
	return 0;
}



// Shortest Common Supersequence

#include <bits/stdc++.h>
using namespace std;

int max(int a, int b)  {  return (a>b) ? a : b;  }

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    string s1, s2;
	    cin>>s1>>s2;
	    int m=s1.size(), n=s2.size();
	    int a[m+1][n+1];
	    for(int i=0; i<=m; i++)
	    {
	        for(int j=0; j<=n; j++)
    	    {
    	        if(i == 0 || j == 0)  a[i][j] = 0;
    	        else if(s1[i-1] == s2[j-1])  a[i][j] = 1 + a[i-1][j-1];
    	        else  a[i][j] = max(a[i-1][j], a[i][j-1]);
    	    }
	    }
	    cout << m+n-a[m][n] << endl;
	}
	return 0;
}



// Longest increasing sequence

// Recursive
#include <bits/stdc++.h>
using namespace std;

int max(int a, int b)
{
    return (a>b) ? a : b;
}

int lis(int a[], int i, int n)
{
    if(i >= n)  return 0;
    int m=INT_MIN;
    for(int j=i+1; j<=n; j++)
    {
        if(a[j]>a[i])
        {
            int x = 1 + lis(a, j, n);
            m = max(m, x);
        }
    }
    return m;
}

int main() 
{
	int t, n;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    int a[n];
	    for(int i=0; i<n; i++)  cin>>a[i];
	    cout<<lis(a, 0, n)<<endl;
	}
	return 0;
}


// Dynamic Programming
#include <bits/stdc++.h>
using namespace std;

int lis(int a[], int n)
{
    int b[n];
    b[0] = 1;
    for(int i=1; i<n; i++)
    {
        b[i]=1;
        for(int j=0; j<i; j++)
        {
            if(a[j] < a[i] && b[i] < b[j]+1)
                b[i] = b[j] + 1;
        }
    }
    int me = INT_MIN;
    for(int i=0; i<n; i++)
    {
        if(me < b[i])
            me = b[i];
    }
    return me;
}

int main() 
{
	int t, n;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    int a[n];
	    for(int i=0; i<n; i++)  cin>>a[i];
	    cout<<lis(a, n)<<endl;
	}
	return 0;
}




// Longest Common Subsequence

#include <iostream>
#include <string.h>
using namespace std;

int max(int a, int b)  {  return (a>b) ? a : b;  }

int lcs(string s1, string s2)
{
    int m=s1.size(), n=s2.size();
    int a[m+1][n+1];
    for(int i=0; i<=m; i++)
    {
        for(int j=0; j<=n; j++)
        {
            if(i == 0 || j == 0)  a[i][j] = 0;
            else if(s1[i-1] == s2[j-1])  a[i][j] = a[i-1][j-1] + 1;
            else  a[i][j] = max(a[i-1][j], a[i][j-1]);
        }
    }
    return a[m][n];
}

int main() 
{
	int t, n, m;
	cin>>t;
	while(t--)
	{
	    cin>>m>>n;
	    string s1, s2;
	    cin>>s1>>s2;
	    cout<<lcs(s1, s2)<<endl;
	}
	return 0;
}




// Maximum sum increasing subsequence

#include <iostream>
using namespace std;

int incSum(int a[], int n)
{
    int b[n];
    b[0] = a[0];
    for(int i=1; i<n; i++)
    {
        b[i] = a[i];
        for(int j=0; j<i; j++)
        {
            if(a[i]>a[j] && b[i]<b[j]+a[i])
                b[i] = b[j] + a[i];
        }
    }
    int m = 0;
    for(int i=0; i<n; i++)
    {
        if(m < b[i])
            m = b[i];
    }
    return m;
}

int main() 
{
	int t, n;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    int a[n];
	    for(int i=0; i<n; i++)  cin>>a[i];
	    cout<<incSum(a, n)<<endl;
	}
	return 0;
}



// Minimum number of platforms

#include <iostream>
#include <string.h>
using namespace std;

int max(int a, int b)
{
    return (a>b)?a:b;
}

void sort(int a[], int n)
{
    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(a[j]<a[i])
            {
                int t=a[j];
                a[j]=a[i];
                a[i]=a[j];
            }
        }
    }
}

int platforms(int a[], int b[], int n)
{
    int count=0;
    string s="";
    sort(a, n);
    sort(b, n);
    int i=0, j=0;
    while(i<n && j<n)
    {
        if(a[i]<b[j])
        {
            s = s+"a";
            i++;
        }
        else if(a[i]>b[j])
        {
            s = s+"d";
            j++;
        }
        else
        {
            if(i>j)
            {
                s = s+"a";
                i++;
            }
            else
            {
                s = s+"d";
                j++;
            }
        }
    }
    // cout<<s<<endl;
    int m = 0;
    for(i=0; i<s.size(); i++)
    {
        if(s[i] == 'a')
        {
            count++;
            m = max(m, count);
        }
        else if(s[i] == 'd')
        {
            count--;
            m = max(m, count);
        }
    }
    return m;
}

int main() 
{
	int t, n;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    int a[n], b[n];
	    for(int i=0; i<n; i++)  cin>>a[i];
	    for(int i=0; i<n; i++)  cin>>b[i];
	    cout<<platforms(a, b, n)<<endl;
	}
	return 0;
}





// Boolean Matrix

#include <bits/stdc++.h> 
using namespace std; 

int main() 
{ 
	int t;
	cin>>t;
    while(t--)
    {
        int R, C;
        cin>>R>>C;
        int mat[R][C];
        for(int i=0; i<R; i++)
        {
            for(int j=0; j<C; j++)
                cin>>mat[i][j];
        } 
        
        bool row[R]; 
    	bool col[C]; 
    	int i, j; 
    	for (i = 0; i < R; i++) 
        	row[i] = 0; 
    
    	for (i = 0; i < C; i++) 
        	col[i] = 0; 
    
        for (i = 0; i < R; i++) 
    	{ 
    		for (j = 0; j < C; j++) 
    		{ 
    			if (mat[i][j] == 1) 
    			{ 
    				row[i] = 1; 
    				col[j] = 1; 
    			} 
    		} 
    	} 
    	for (i = 0; i < R; i++) 
    	{ 
    		for (j = 0; j < C; j++) 
    		{ 
    			if ( row[i] == 1 || col[j] == 1 )  mat[i][j] = 1; 
    		} 
    	} 
    	for (i = 0; i < R; i++) 
    	{ 
    		for (j = 0; j < C; j++) 
    			cout << mat[i][j] << " "; 
    		cout << endl; 
    	} 
    }
	return 0; 
} 




// EDIT DISTANCE

#include <iostream>
#include <string.h>
using namespace std;

int min(int a, int b, int c)
{
    if(a <= b && a <= c)  return a;
    else if(b <= a && b <= c)  return b;
    else  return c;
}

int edit(string s1, string s2, int m, int n)
{
    int a[m+1][n+1];
    for(int i=0; i<=m; i++)
    {
        a[i][0] = i;
        for(int j=1; j<=n; j++)
        {
            if(i == 0)  a[i][j] = j;
            else if(s1[i-1] == s2[j-1])  a[i][j] = a[i-1][j-1];
            else  a[i][j] = 1 + min(a[i-1][j], a[i-1][j-1], a[i][j-1]);
        }
    }
    return a[m][n];
}

int main() 
{
	int t, m, n;
	cin>>t;
	while(t--)
	{
	    string s1, s2;
	    cin>>m>>n;
	    cin>>s1>>s2;
	    cout<<edit(s1, s2, m, n)<<endl;
	}
	return 0;
}



// Coin Change 

#include <iostream>
using namespace std;

int main() 
{
	int t, n;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    while(n)
	    {
	        if(n>=1 && n<2)
	        {
	            cout<<1<<" ";
	            n -= 1;
	        }
	        else if(n>=2 && n<5)
	        {
	            cout<<2<<" ";
	            n -= 2;
	        }
	        else if(n>=5 && n<10)
	        {
	            cout<<5<<" ";
	            n -= 5;
	        }
	        else if(n>=10 && n<20)
	        {
	            cout<<10<<" ";
	            n -= 10;
	        }
	        else if(n>=20 && n<50)
	        {
	            cout<<20<<" ";
	            n -= 20;
	        }
	        else if(n>=50 && n<100)
	        {
	            cout<<50<<" ";
	            n -= 50;
	        }
	        else if(n>=100 && n<200)
	        {
	            cout<<100<<" ";
	            n -= 100;
	        }
	        else if(n>=200 && n<500)
	        {
	            cout<<200<<" ";
	            n -= 200;
	        }
	        else if(n>=500 && n<2000)
	        {
	            cout<<500<<" ";
	            n -= 500;
	        }
	        else if(n>=2000)
	        {
	            cout<<2000<<" ";
	            n -= 2000;
	        }
	    }
	    cout<<endl;
	}
	return 0;
}




// Number of ways of Coin Change


// Recursive

#include <iostream>
using namespace std;

int fn(int a[], int m, int n)
{
    if(n == 0)  return 1;
    if(n < 0)  return 0;
    if(n >= 1 && m <= 0)  return 0;
    return fn(a, m-1, n) + fn(a, m, n-a[m-1]);
}

int main() 
 {
	int t, m, n;
	cin>>t;
	while(t--)
	{
	    cin>>m;
	    int a[m];
	    for(int i=0; i<m; i++)  cin>>a[i];
	    cin>>n;
	    cout<<fn(a, m, n)<<endl;
	}
	return 0;
}

// Dynamic Programming

#include <iostream>
using namespace std;

int fn(int a[], int m, int n)
{
    int p[m+1][n+1];
    for(int i=0; i<m+1; i++)
    {
        p[i][0] = 1;
        for(int j=1; j<n+1; j++)
        {
            if(i == 0)  p[i][j] = 0;
            else if(j < a[i-1])
                p[i][j] = p[i-1][j];
            else 
                p[i][j] = p[i-1][j] + p[i][j-a[i-1]];
        }
    }
    return p[m][n];
}

int main() 
 {
	int t, m, n;
	cin>>t;
	while(t--)
	{
	    cin>>m;
	    int a[m];
	    for(int i=0; i<m; i++)  cin>>a[i];
	    cin>>n;
	    cout<<fn(a, m, n)<<endl;
	}
	return 0;
}



// DFS of a Graph

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N, E;
        cin>>N>>E;
        
        vector<int> g[N];
        bool vis[N];
        
        memset(vis, false, sizeof(vis));
        
        for(int i=0;i<E;i++)
        {
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(0,g,vis);
        
        cout<<endl;
    }
}

void dfs(int s, vector<int> g[], bool vis[])
{
    if(vis[s] == true)  return;
    vis[s] = true;
    cout<<s<<" ";
    for(int i=0; i<g[s].size(); i++)
    {
        dfs(g[s][i], g, vis);
    }
}



// Subset Sum Problem


// Recursive Approach

#include <iostream>
using namespace std;

int fn(int a[], int n, int sum)
{
    if(n<0 || sum<0)  return 0;
    if(a[n] == sum)  return 1;
    int x = fn(a, n-1, sum);
    int y = fn(a, n-1, sum - a[n]);
    if(x == 2 || y == 2 || (x == 1 && y == 1))  return 2;
    else if(x == 1 || y == 1)  return 1;
    else  return 0;
}

int main() 
{
	int t, n;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    int a[n];
	    int sum = 0;
	    
	    for(int i=0; i<n; i++)  
	    {
	        cin>>a[i];
	        sum = sum+a[i];
	    }
	    
	    if(sum%2 != 0)  cout<<"NO"<<endl;
	    else 
	    {
	        int x = fn(a, n-1, sum/2);
	        if(x == 2)  cout<<"YES"<<endl;
	        else  cout<<"NO"<<endl;
	    }
	}
	return 0;
}

// Dynamic Programming

#include <iostream>
using namespace std;

int fn(int a[], int n, int sum)
{
    bool m[n+1][sum+1];
    
    for(int i=0; i<=n; i++)  m[i][0] = 1;
    for(int i=1; i<=sum; i++)  m[0][i] = 0;
    
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=sum; j++)
        {
            if(a[i-1]>j)  m[i][j] = m[i-1][j];
            else  m[i][j] = m[i-1][j] || m[i-1][j-a[i-1]];
        }
    }
    return m[n][sum];
}

int main() 
{
	int t, n;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    int a[n];
	    int sum = 0;
	    
	    for(int i=0; i<n; i++)  
	    {
	        cin>>a[i];
	        sum = sum+a[i];
	    }
	    
	    if(sum%2 != 0)  cout<<"NO"<<endl;
	    else 
	    {
	        int x = fn(a, n, sum/2);
	        if(x == 1)  cout<<"YES"<<endl;
	        else  cout<<"NO"<<endl;
	    }
	} 
	return 0;
}




// Eggs Dropping Problem


// Recursive

#include <iostream>
#include <limits.h>
using namespace std;

int max(int a, int b)  {  return (a>b) ? a : b;  }

int fn(int e, int f)
{
    if(f == 0 || f == 1 || e == 1)  return f;
    int m = INT_MAX, t;
    for(int i=1; i<=f; i++)
    {
        t = max(fn(e-1, i-1), fn(e, f-i));
        if(m>t)  m = t;
    }
    return 1 + m; 
}

int main() 
{
	int t, e, f;
	cin>>t;
	while(t--)
    {
        cin>>e>>f;
        cout<<fn(e, f)<<endl;
    }
	return 0;
}

// Dynamic Programming

#include <iostream>
#include <limits.h>
using namespace std;

int max(int a, int b)  {  return (a>b) ? a : b;  }

int fn(int e, int f)
{
    int m[e+1][f+1];
    for(int i=1; i<=e; i++)
    {
        m[i][0] = 0;
        m[i][1] = 1;
    }
    
    for(int i=1; i<=f; i++)
        m[1][i] = i;
        
    for(int i=2; i<=e; i++)
    {
        for(int j=2; j<=f; j++)
        {
            m[i][j] = INT_MAX;
            for(int k=1; k<=j; k++)
            {
                int q = 1 + max(m[i-1][k-1], m[i][j-k]);
                if(q<m[i][j])  m[i][j] = q;
            }
        }
    }
    return m[e][f];
}

int main() 
{
	int t, e, f;
	cin>>t;
	while(t--)
    {
        cin>>e>>f;
        cout<<fn(e, f)<<endl;
    }
	return 0;
}


// Santa and Gifts

#include <bits/stdc++.h>
using namespace std;

int fn(vector<int> &a, int n, int c)
{
    sort(a.begin(), a.end());
    vector<int>::iterator it; 
    while(a.size() != c)
    {
        int x = a[0] + a[1], i;
        it = a.begin();
        a.erase(it); 
        it = a.begin(); 
        a.erase(it);
        a.push_back(x);
        
        for(i = a.size()-2; a[i]>x; i--)
            a[i+1] = a[i];
        
        a[i+1] = x;
    }
    return a[c-1];
}

int main() 
{
	int t, n, c, x;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    vector<int> a;
	    for(int i=0; i<n; i++)  
	    {
	        cin>>x;
	        a.push_back(x);
	    }
	    cin>>c;
	    if(c>n)  cout<<-1<<endl;
	    else  cout<<fn(a, n, c)<<endl;
	}
	return 0;
}



def fn(a, n, c):
    a.sort()
    while len(a) != c:
        x = a[0] + a[1]
        del(a[0])
        del(a[1])
        a.append(x)
        a.sort()
    return a[c-1]


if __name__ == '__main__': 
    t = int(input())
	for i in range(t):
	    n = int(input())
	    a = []
	    for j in range(n):
	        x = int(input())
	        a.append(x)
	    c = int(input())
	    if c>n:  c
	        print(-1)
	    else:
	        print(fn(a, n, c))




// Optimal strategy for a Game


// Rescursive

#include <bits/stdc++.h>
using namespace std;

int max1(int a, int b)  {  return (a>b) ? a : b;  }
int max(int a, int b, int c, int d)  {  return max1(max1(a, b), max1(c, d));  }

int fn2(int arr[], int i, int j, int sum) 
{ 
    if (j == i + 1) 
        return max(arr[i], arr[j]); 
  
    return max((sum - fn2(arr, i+1, j, sum - arr[i])), 
               (sum - fn2(arr, i, j-1, sum - arr[j]))); 
} 
  
int fn1(int* arr, int n) 
{ 
    int sum = 0; 
    sum = accumulate(arr, arr + n, sum); 
    return fn2(arr, 0, n - 1, sum); 
} 

int main() 
{
	int t, n;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    int a[n];
	    for(int i=0; i<n; i++)  cin>>a[i];
	    cout<<fn1(a, n)<<endl;
	}
	return 0;
}


// Dynamic Programming

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int dp[101][101];

int find(int arr[],int st,int end)
{
    if(st == end)  return arr[st];
    if(st == end-1)  return max(arr[st],arr[end]);
    if(dp[st][end] != -1)  return dp[st][end];
    dp[st][end] = max(arr[st] + min(find(arr,st+2,end), find(arr,st+1,end-1)),
                      arr[end] + min(find(arr,st+1,end-1),find(arr,st,end-2)));
    return dp[st][end];
}

int main() 
{
	int t, n;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    int arr[n];
	    memset(dp,-1,sizeof(dp));
	    for(int i=0;i<n;i++)  cin>>arr[i];
	    int st=0, end=n-1;
	    find(arr,st,end);
	    cout<<dp[0][end]<<endl;
	}
	return 0;
}



// Count number of hops

// Recursive

#include <iostream>
using namespace std;

int fn(int n, int a[])
{
    if(n < 0)  return 0;
    if(n == 0)  return 1;
    return fn(n-3) + fn(n-2) + fn(n-1);
}

int main() 
 {
	int t, n;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    int a[n+1] = { -1 };
	    a[0] = 0;
	    cout<<fn(n, a)<<endl;
	}
	return 0;
}

// Dynamic Programming

#include <iostream>
using namespace std;

int fn(int n)
{
    if(n <= 0)  return 0;
    
    int a[n] = { 0 };
    
    a[0] = 1;
    a[1] = 2;
    a[2] = 4;
    
    for(int i=3; i<n; i++)
    {
        // if(i-1 > 0)  a[i] += a[i-1];
        // else if(i-1 == 0)  a[i]++;
        
        // if(i-2 > 0)  a[i] += a[i-2];
        // else if(i-2 == 0)  a[i]++;
        
        // if(i-3 > 0)  a[i] += a[i-3];
        // else if(i-3 == 0)  a[i]++;
        
        a[i] = a[i-1] + a[i-2] + a[i-3];
    }
    
    return a[n-1];
}

int main() 
 {
	int t, n;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    cout<<fn(n)<<endl;
	}
	return 0;
}



// Clone a linked list

Node *copyList(Node *head) 
{
    Node *ptr = head;
    Node *h = NULL, *p = NULL;
    Node *n = new Node(ptr->data);
    h = n;
    p = n;
    ptr = ptr->next;
    while(ptr != NULL)
    {
        Node *n = new Node(ptr->data);
        p->next = n;
        p = p->next;
        ptr = ptr->next;
    }
    ptr = head;
    p = h;
    while(p != NULL)
    {
        if(ptr->arb != NULL)
        {
            Node *q = h;
            while(q->data != ptr->arb->data)  q = q->next;
            p->arb = q;
        }
        ptr = ptr->next;
        p = p->next;
    }
    return h;
}



// Activity Selection - Morgan Stanley

#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int a[n], b[n];
	    
	    for(int i=0; i<n; i++)
	        cin>>a[i];
	    for(int i=0; i<n; i++)
	        cin>>b[i];
	        
	    for(int i=0; i<n-1; i++)
	    {
	        for(int j=i+1; j<n; j++)
	        {
	            if(b[j] < b[i])
	            {
	                swap(&b[j], &b[i]);
	                swap(&a[j], &a[i]);
	            }
	        }
	    }
	    
	    int i=1, count=1, l=0;
	    while(i < n)
	    {
	        if(a[i]>=b[l])
	        {
	            count++;
	            l=i;
	        }
	        i++;
	    }
	    cout<<count<<endl;
	}
	return 0;
}




// Largest subarray of 0's and 1's

// Recursive 

int fn(int arr[], int i, int j)
{
    if(i == j)  return 0;
    int z=0, o=0;
    for(int k=i; k<=j; k++)
    {
        if(arr[k] == 0)  z++;
        else  o++;
    }
    if(z == o)  return z+o;
    else if(z== 0 || o == 0)  return 0;
    else  return max(fn(arr, i+1, j), fn(arr, i, j-1));
}

int maxLen(int arr[], int n)
{
    return fn(arr, 0, n-1);
}

// Efficient (Similar to Kadane's Algorithm)

int maxLen(int arr[], int n)
{
    unordered_map<int,int> m;
    int sum = 0, ans = INT_MIN;
    for(int i = 0;i<n;i++)
    {
        if(arr[i] == 0)  arr[i] = -1;
    }
            
    for(int i=0; i<n; i++)
    {
        sum += arr[i];
        if(sum == 0)  ans = max(ans,i+1);
        if(m.find(sum) != m.end())  ans = max(ans,i-m[sum]);
        else  m[sum] = i;
    }
    if(ans == INT_MIN)  return 0;
    return ans; 
}



// Level Order Traversal - Morgan Stanley

void levelOrder(Node* node)
{
    queue <Node*> q1, q2;
    if(node)
    {
        q1.push(node);
        while(!q1.empty() || !q2.empty())
        {
            if(!q1.empty())
            {
                while(!q1.empty())
                {
                    if(q1.front()->left)  q2.push(q1.front()->left);
                    if(q1.front()->right)  q2.push(q1.front()->right);
                    cout<<q1.front()->data<<" ";
                    q1.pop();
                }
                cout<<"$ ";    
            }
            
            if(!q2.empty())
            {
                while(!q2.empty())
                {
                    if(q2.front()->left)  q1.push(q2.front()->left);
                    if(q2.front()->right)  q1.push(q2.front()->right);
                    cout<<q2.front()->data<<" ";
                    q2.pop();
                }
                cout<<"$ ";   
            }
        }
    }
}



// Maximum Product Subarray

#include<bits/stdc++.h>
using namespace std;

int main() 
{
	int t;
	cin>>t;
	while(t--)
    {
	    long long int n,neg=0,z=0;
	    cin>>n;
	    long long int a[n];
	    for(int i=0;i<n;i++)
	    {
	        cin>>a[i];
	        if(a[i]<0){neg++;}
	        if(a[i]==0){z++;}
	    }
	    if(neg==1 && z==n-1 && z!=0)  cout<<"0"<<endl;
        else if(neg==1 && n==1)  cout<<a[0]<<endl;
        else
        {
            long long int maxi=1,mini=1,maxl=0;
            for(int i=0;i<n;i++)
            {
                if(a[i]>0)
                {
                    maxi=maxi*a[i];
                    mini=min(mini*a[i],(long long)1);
                }
                else if(a[i]<0)
                {
                    long long int temp=maxi;
                    maxi=max(mini*a[i],(long long)1);
                    mini=temp*a[i];
                }
                else
                {
                    maxi=1;
                    mini=1;
                }
                if(maxl<maxi)  maxl=maxi;
            }
            cout<<maxl<<endl;
        }
    }    
	return 0;
}



// Minimum element in a sorted and rotated array

#include <iostream>
using namespace std;

int min(int x, int y)  {  return (x<y) ? x : y;  }

int fn(int a[], int i, int j)
{
    if(i == j)  return a[i];
    if(i+1 == j)  return min(a[i], a[j]);
    int k = (i+j)/2;
    if(a[k+1] > a[k] && a[k-1] > a[k])  return a[k];
    int x = fn(a, i, k-1);
    int y =  fn(a, k+1, j);
    return min(x, y);
}

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n; 
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n; i++)
	        cin>>a[i];
	    cout<<fn(a, 0, n-1)<<endl;
	}
	return 0;
}


// Spirally traversing a matrix

#include <iostream>
using namespace std;

void spiral()
{
    int m1, m2;
    cin>>m1>>m2;
    int arr[m1][m2];
    for(int i=0; i<m1; i++)
    {
        for(int j=0; j<m2; j++)
            cin>>arr[i][j];
    }
    int i=0, dir=0, n=m1*m2, k;
    int T=0, B=m1-1, L=0, R=m2-1;
    while(T<=B && L<=R)
    {
        if(dir==0)
        {
            for(k=L ; k<=R ; k++)
                printf("%d ",arr[T][k]);
            T++;
        }
        else if(dir==1)
        {
            for(k=T ; k<=B ; k++)
                printf("%d ",arr[k][R]);
            R--;
        }
        else if(dir==2)
        {
            for(k=R ; k>=L ; k--)
                printf("%d ",arr[B][k]);
            B--;
        }
        else if(dir==3)
        {
            for(k=B ; k>=T ; k--)
                printf("%d ",arr[k][L]);
            L++;
        }
        dir=(dir+1)%4;
    }
    cout<<endl;
}

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    spiral();
	}
	return 0;
}



// atoi - convert string to int 

int atoi(string str)
{
    int x = 0, y, j=0;
    if(str[0] == '-')  
    {
        y = -1;
        j=1;
    }
    else  y = 1;
    for(int i=j; str[i]!='\0'; i++)
    {
        if(str[i] - 48 > 9)
            return -1;
        else  x = 10*x + (str[i]-48);
    }
    return x*y;
}



// Day of the week

#include<iostream>
using namespace std;

int fn(int d,int m,int y)
{
    int t[]={0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    if(m < 3)   y = y - 1;
    return ((y + y/4 - y/100 + y/400 + t[m-1] + d) % 7);
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int d, m, y;
        cin>>d>>m>>y;
        string s[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
        cout<<s[fn(d, m, y)]<<endl; 
    }
    return 0;
}



// Find median in stream

// Not efficient

#include <iostream>
using namespace std;

void med_fn(int a[], int n)
{
    for(int i=0; i<n; i++)
    {
        int j = i-1, key = a[i];
        
        while(j>=0 && a[j]>key) 
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
        
        if(i/2 == (i+1)/2)  cout<<a[i/2]<<endl;
        else  cout<<((a[i/2] + a[(i+1)/2])/2)<<endl;
    }
}

int main() 
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];
    med_fn(a, n);
	return 0;
}





#include <iostream> 
using namespace std; 
  
#define MAX_HEAP_SIZE (1000000) 
#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0]) 
  
inline
void Exch(int &a, int &b) 
{ 
    int aux = a; 
    a = b; 
    b = aux; 
} 

bool Greater(int a, int b)  {  return a > b;  } 
bool Smaller(int a, int b)  {  return a < b;  } 
int Average(int a, int b)  {  return (a + b) / 2;  } 
  
int Signum(int a, int b) 
{ 
    if( a == b ) 
        return 0; 
  
    return a < b ? -1 : 1; 
} 
  
class Heap 
{ 
public: 
    Heap(int *b, bool (*c)(int, int)) : A(b), comp(c) 
    { 
        heapSize = -1; 
    } 
  
    virtual ~Heap() 
    { 
        if( A )  delete[] A; 
    } 
  
    virtual bool Insert(int e) = 0; 
    virtual int  GetTop() = 0; 
    virtual int  ExtractTop() = 0; 
    virtual int  GetCount() = 0; 
  
protected: 
  
    int left(int i)  {  return 2 * i + 1;  } 
  
    int right(int i)  {  return 2 * (i + 1);  } 
    int parent(int i) 
    { 
        if( i <= 0 )  return -1; 
        return (i - 1)/2; 
    } 
  
    int   *A; 
    bool  (*comp)(int, int); 
    int   heapSize; 
  
    int top(void) 
    { 
        int max = -1; 
        if( heapSize >= 0 )  max = A[0]; 
        return max; 
    } 
  
    int count()  {  return heapSize + 1;  } 
  
    void heapify(int i) 
    { 
        int p = parent(i); 
        if( p >= 0 && comp(A[i], A[p]) ) 
        { 
            Exch(A[i], A[p]); 
            heapify(p); 
        } 
    } 
  
    int deleteTop() 
    { 
        int del = -1; 
        if( heapSize > -1) 
        { 
            del = A[0]; 
            Exch(A[0], A[heapSize]); 
            heapSize--; 
            heapify(parent(heapSize+1)); 
        } 
        return del; 
    } 
  
    bool insertHelper(int key) 
    { 
        bool ret = false; 
        if( heapSize < MAX_HEAP_SIZE ) 
        { 
            ret = true; 
            heapSize++; 
            A[heapSize] = key; 
            heapify(heapSize); 
        } 
        return ret; 
    } 
}; 
  
class MaxHeap : public Heap 
{ 
private: 
  
public: 
    MaxHeap() : Heap(new int[MAX_HEAP_SIZE], &Greater)  {  } 
    ~MaxHeap()  { } 
    int GetTop()  {  return top();  } 
    int ExtractTop()  {  return deleteTop();  } 
    int  GetCount()  {  return count();  } 
    bool Insert(int key)  {  return insertHelper(key);  } 
}; 
  
class MinHeap : public Heap 
{ 
private: 

public: 
    MinHeap() : Heap(new int[MAX_HEAP_SIZE], &Smaller) { } 
    ~MinHeap() { } 
    int GetTop()  {  return top();  } 
    int ExtractTop()  {  return deleteTop();  } 
    int  GetCount()  {  return count();  } 
    bool Insert(int key)  {  return insertHelper(key);  } 
}; 

int getMedian(int e, int &m, Heap &l, Heap &r) 
{ 
    int sig = Signum(l.GetCount(), r.GetCount()); 
    switch(sig) 
    { 
    case 1:
        if( e < m )
        { 
            r.Insert(l.ExtractTop()); 
            l.Insert(e); 
        } 
        else  r.Insert(e); 
        m = Average(l.GetTop(), r.GetTop()); 
        break; 
    case 0:
        if( e < m ) 
        { 
            l.Insert(e); 
            m = l.GetTop(); 
        } 
        else
        { 
            r.Insert(e); 
            m = r.GetTop(); 
        } 
        break; 
  
    case -1:
        if( e < m )  l.Insert(e);  
        else
        { 
            l.Insert(r.ExtractTop()); 
            r.Insert(e); 
        } 
        m = Average(l.GetTop(), r.GetTop());
        break; 
    } 
    return m; 
} 
  
void printMedian(int A[], int size) 
{ 
    int m = 0; 
    Heap *left  = new MaxHeap(); 
    Heap *right = new MinHeap(); 
    for(int i = 0; i < size; i++) 
    { 
        m = getMedian(A[i], m, *left, *right); 
        cout << m << endl; 
    } 
    delete left; 
    delete right; 
} 
int main() 
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];
    printMedian(a, n);
	return 0;
}



// Java Solution

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Collections;
import java.util.PriorityQueue;

public class GFG {

	public static void main(String[] args) throws IOException {
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(reader.readLine());
		int[] a = new int[t];
		int i = 0;
		while (t-- > 0) {
			int x = Integer.parseInt(reader.readLine());
			a[i++] = x;
		}
		int[] medians = runningMedian(a);
		for (int median : medians) {
			System.out.println(median);
		}
	}

	private static final PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Collections.reverseOrder());
    private static final PriorityQueue<Integer> minHeap = new PriorityQueue<>();

    private static int[] runningMedian(int[] a) {
        
        int[] medians = new int[a.length];
        for (int i = 0; i < a.length; i++) {
            int number = a[i];
            addNum(number);
            medians[i] = findMedian();
        }
        return medians;
    }

    private static void addNum(int num) {
        minHeap.add(num);
        maxHeap.add(minHeap.remove());

        if (minHeap.size() < maxHeap.size()) {
            minHeap.add(maxHeap.remove());
        }
    }

    private static int findMedian() {
        if (minHeap.size() > maxHeap.size()) {
            return minHeap.peek();
        } else {
            return (minHeap.peek() + maxHeap.peek()) / 2;
        }
    }
}



// Next greater number set digits

#include <iostream>
#include <string.h>
using namespace std;

void next_greatest(string n)
{
    int l=n.size(), i;
    for(i=l-2; i>=0; i--)
    {
        if(n[i+1] > n[i])  break;
    }
    if(i == -1)
    {
        cout<<"not possible"<<endl;
        return;
    }
    int s = i+1;
    for(int j=i+1; j<l; j++)
    {
        if(n[j] > n[i] && n[j] < n[s])  s = j;
    }
    int t = n[s];
    n[s] = n[i];
    n[i] = t;
    for(int p=i+1; p<l; p++)
    {
        for(int q=i+1; q<l-p+i; q++)
        {
            if(n[q] > n[q+1])
            {
                int z = n[q];
                n[q] = n[q+1];
                n[q+1] = z;
            }
        }
    }
    cout<<n<<endl;
}

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    string n;
	    cin>>n;
	    next_greatest(n);
	}
	return 0;
}



// Minimum Distinct ids

#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n, m, count=0;
	    cin>>n;
	    int a[n];
	    for(int i=0; i<n; i++)  cin>>a[i];
	    cin>>m;
	    map<int, int> mp;
	    vector<pair<int, int>> v;
	    
	    for(int i=0; i<n; i++)
	    {
	        if(mp.find(a[i]) == mp.end())  mp[a[i]] = 1;
	        else  mp[a[i]]++;
	    }
	    
	    map<int, int>::iterator it = mp.begin();
	    for(it=mp.begin(); it!=mp.end(); it++)
	        v.push_back(make_pair(it->second, it->first));
	       
	    sort(v.begin(), v.end()); 
        int s = v.size();
        
	    for(int i=0; i<s; i++)
	    {
	        if(v[i].first > m)
	        {
	            v[i].first = v[i].first - m;
	            m=0;
	            break;
	        }
	        else
	        {
	            m = m - v[i].first;
	            v[i].first = 0;
	        }
	    }
	    for(int i=0; i<s; i++)
	    {
	        if(v[i].first != 0)  count++;
	    }
	    cout<<count<<endl;
	}
	return 0;
}



// Odd to Even

#include <iostream>
using namespace std;

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    string s, s1;
	    cin>>s;
	    s1 = s;
	    char b;
	    for(int i=0; i<s.size(); i++)
	    {
	        if((s[i]-48)%2 == 0 && s[i] < s[s.size()-1]) 
	        {
	            char a = s[i];
	            s[i] = s[s.size()-1];
	            s[s.size()-1] = a;
	            break;
	        }
	    }
	    if(s1 == s)
	    {
	        for(int i=s.size()-2; i>=0; i--)
    	    {
    	        if((s[i]-48)%2 == 0) 
    	        {
    	            char a = s[i];
    	            s[i] = s[s.size()-1];
    	            s[s.size()-1] = a;
    	            break;
    	        }
    	    }
	    }
	    cout<<s<<endl;
	}
	return 0;
}



// Number of coins

#include <bits/stdc++.h>
using namespace std;

int coins(int v[], int n, int m)
{
    int a[m+1];
    a[0] = 0;
    for(int i=1; i<=m; i++)
    {
        a[i] = INT_MAX;
        for(int j=0; j<n; j++)
        {
            if(v[j] <= i)
            {
                int s = a[i-v[j]];
                if(s != INT_MAX && s+1 < a[i])  
                    a[i] = s+1;
            }
        }
    }
    if(a[m] == INT_MAX)  return -1;
    return a[m];
}

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    int m, n;
	    cin>>m>>n;
	    int v[n];
	    for(int i=0; i<n; i++)  cin>>v[i];
	    cout<<coins(v, n, m)<<endl;
	}
	return 0;
}



// Rat in a Maze

#include <bits/stdc++.h>
using namespace std;
#define MAX 100
vector<string> printPath(int m[MAX][MAX], int n);
int main() 
{
	int t;
	cin>>t;
	while(t--)
    {
        int n;
        cin>>n;
        
        int m[100][100];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                cin>>m[i][j];
        }
        vector<string> res = printPath(m,n);
        for(int i=0;i<res.size();i++)
        cout<<res[i]<<" ";
        cout<<endl;
    }
	return 0;
}

void fn(int i, int j, int m[MAX][MAX], int n, string s, vector<string> &r)
{
    if(i < 0 || j < 0 || i >= n || j >= n || m[i][j] == 0 || m[i][j] == 2)  return ;
    else if(i == n-1 && j == n-1)
    {
        r.push_back(s);
        return ;
    }
    else
    {
        m[i][j] = 2;
        fn(i+1, j, m, n, s+'D', r);
        fn(i-1, j, m, n, s+'U', r);
        fn(i, j+1, m, n, s+'R', r);
        fn(i, j-1, m, n, s+'L', r);
        m[i][j]=1;
    }
}

vector<string> printPath(int m[MAX][MAX], int n)
{   
    vector<string> r;
    fn(0,0,m,n,"",r);
    sort(r.begin(), r.end());
    return r;
}




// Word Boggle 

#include <bits/stdc++.h>
using namespace std;

const int MAX = 7;

void fn(int i, int j, int k, int p, int q, string s, char m[MAX][MAX], 
        int b[MAX][MAX], vector<string> &v)
{
    if(b[i][j] == 1 || i < 0 || j < 0 || i >= p || j >= q || m[i][j] != s[k])  
    {
        return;
    }
    else if(k == s.size()-1 && b[i][j] == 0)
    {
        v.push_back(s);
        return;
    }
    else
    {
        b[i][j] = 1;
        k++; 
        fn(i-1, j-1, k, p, q, s, m, b, v);
        fn(i-1, j, k, p, q, s, m, b, v);
        fn(i-1, j+1, k, p, q, s, m, b, v);
        fn(i, j-1, k, p, q, s, m, b, v);
        fn(i, j+1, k, p, q, s, m, b, v);
        fn(i+1, j-1, k, p, q, s, m, b, v);
        fn(i+1, j, k, p, q, s, m, b, v);
        fn(i+1, j+1, k, p, q, s, m, b, v);
    }
}

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n, p, q;
	    cin>>n;
	    vector<string> r, v;
	    string x;
	    for(int i=0; i<n; i++)
	    {
	        cin>>x;
	        r.push_back(x);
	    }
	    cin>>p>>q;
	    char m[MAX][MAX];
	    for(int i=0; i<p; i++)
	    {
	        for(int j=0; j<q; j++)
    	        cin>>m[i][j];
	    } 
	    for(int z=0; z<n; z++)
	    {
	        for(int i=0; i<p; i++)
    	    {
    	        for(int j=0; j<q; j++)
    	        {
            	    int b[MAX][MAX] = { 0 };
        	        fn(i, j, 0, p, q, r[z], m, b, v);
    	        }
    	    }
	    }
	    sort(v.begin(), v.end());
	    if(v.size() != 0)
	    {
	        set<string> s;
	        for(int i=0; i<v.size(); i++)
	        {
	            if(s.find(v[i]) == s.end())  s.insert(v[i]);
	        }
	        set<string>:: iterator it;
	        for(it=s.begin(); it!=s.end(); it++)  
	            cout<<(*it)<<" ";
	    }
	    else  cout<<-1;
	    cout<<endl;
	}
	return 0;
}




// N-Queens Problem

#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool safe(int r, int c, int row[])
{
    for(int i=0; i<c; i++)
    {
        if (row[i] == r || (abs(row[i] - r) == abs(i - c)))  
            return false;
    }
    return true;
}

void backtrack(int c, int n, int row[])
{
    if (c > n-1)
    {
        cout << "[";
        for(int i=0; i<n; i++)
            cout << row[i] + 1 << " ";
        cout << "] ";
    }
    for(int r=0; r<n; r++)
    { 
        if (safe(r,c,row))
        {
            row[c] = r;
            backtrack(c+1, n, row);
        }
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int row[n];
        memset(row, 0, sizeof(row));
        if (n == 3 || n == 2)  cout << "-1";
        else  backtrack(0,n,row);
        cout<<endl;
    }
	return 0;
}



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



// Huffman Decoding

string decodeHuffmanData(struct MinHeapNode* root, string binaryString)
{
    MinHeapNode *r = root;
    string s = "";
    for(int i=0; i<binaryString.size(); i++)
    {
        if(binaryString[i] == '0')  r = r->left;
        else if(binaryString[i] == '1')  r = r->right;
        if(r->left == NULL && r->right == NULL)
        {
            s = s + r->data;
            r->freq = r->freq - 1;
            r = root;
        }
    }
    s = s + '\0';
    return s;
}



// Count Sort

void countSort(char arr[])
{
    int n=0;
    for(int i=0; arr[i]!='\0'; i++)
    {
        n++;
    }
    int v[26] = { 0 };
    for(int i=0; i<n; i++)
    {
        v[arr[i] - 'a']++;
    }
    for(int i=1; i<26; i++)
    {
        v[i] = v[i] + v[i-1];
    }
    char ans[n];
    for(int i=0; i<n; i++)
    {
        ans[v[arr[i] - 'a'] - 1] = arr[i];
        v[arr[i] - 'a']--;
    }
    for(int i=0; i<n; i++)
    { 
        arr[i] = ans[i];
    }
}




// Number following a pattern - Goldman sachs

#include <iostream>
#include <string.h>
using namespace std;

void fn(string arr) 
{ 
    int curr_max = 0; 
    int last_entry = 0; 
    int j; 
    for (int i=0; i<arr.length(); i++) 
    { 
        int noOfNextD = 0; 
  
        switch(arr[i]) 
        { 
        case 'I': 
            j = i+1; 
            while (arr[j] == 'D' && j < arr.length()) 
            { 
                noOfNextD++; 
                j++; 
            } 
                
            if (i==0) 
            { 
                curr_max = noOfNextD + 2; 
                cout << ++last_entry; 
                cout << curr_max; 
                last_entry = curr_max; 
            } 
            else
            { 
                curr_max = curr_max + noOfNextD + 1;  
                last_entry = curr_max; 
                cout << last_entry; 
            } 
            for (int k=0; k<noOfNextD; k++) 
            { 
                cout << --last_entry; 
                i++; 
            } 
            break; 
   
        case 'D': 
            if (i == 0) 
            { 
                j = i+1; 
                while (arr[j] == 'D' && j < arr.length()) 
                { 
                    noOfNextD++; 
                    j++; 
                } 
                curr_max = noOfNextD + 2; 
                cout << curr_max << curr_max - 1; 
                last_entry = curr_max - 1; 
            } 
            else
            { 
                cout << last_entry - 1; 
                last_entry--; 
            } 
            break; 
        } 
    } 
    cout << endl; 
} 

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    string s;
	    cin>>s;
	    fn(s);
	}
	return 0;
}



// Sort a Stack

void SortedStack :: sort()
{
    if(s.empty())  return;
    int temp = s.top();
    s.pop();
    sort();
    
    stack<int> t;
    while(!s.empty() && s.top() > temp)
    {
        t.push(s.top());
        s.pop();
    }
    s.push(temp);
    while(!t.empty())
    {
        s.push(t.top());
        t.pop();
    }
}



// Maximum height of staircase

#include <iostream>
#include <math.h>
using namespace std;

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	   
        // Method 2
        int ht = 0;
	    for(int i=1; n>0; i++)
	    {
	        n = n-i;
	        if(n >= 0)  ht++;
	    }
	    cout<<ht<<endl;

        // Method 2
	    int ht1 = (-1 + sqrt(1+8*n)) / 2;
	    cout<<ht1<<endl;
	}
	return 0;
}



// Special Stack

void push(int a)
{
     s.push(a);
}
bool isFull(int n)
{
     return (s.size() >= n) ? true : false;
}
bool isEmpty()
{
    return (s.empty()) ? true : false;
}
int pop()
{
    int x = s.top();
    s.pop();
    return x;
}
int getMin()
{
    stack<int> t;
    int m;
    while(!s.empty())
    {
        if(t.empty() || m > s.top())
        {
            m = s.top();
        }
        t.push(s.top());
        s.pop();
    }
    while(!t.empty())
    {
        s.push(t.top());
        t.pop();
    }
    return m;
}



// Second most repeated string in a sequence

#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n, c=0;
	    cin>>n;
	    string a[n];
	    map<string, int> m;
	    for(int i=0; i<n; i++)  
	    {
	        cin>>a[i];
	        if(m.find(a[i]) == m.end())  
	        {
	            m[a[i]] = 1;
	            c++;
	        }
	        else  m[a[i]]++;
	    }
	    map<string, int>:: iterator it, it1=m.begin(), it2;
	    int mx1=m.begin()->second, mx2=0;
	    for(it=m.begin(); it!=m.end(); it++)
	    {
	        if(it->second > mx1)
	        {
	            mx2 = mx1;
	            it2 = it1;
	            mx1 = it->second;
	            it1 = it;
	        }
	        else if(it->second > mx2 && it->second < mx1)
	        {
	            mx2 = it->second;
	            it2 = it;
	        }
	    }
	    cout<<it2->first<<endl;
	}
	return 0;
}



// Anagrams

#include <iostream>
#include <string.h>
#include <map>
using namespace std;

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    int f=0;
	    string s1, s2;
	    cin>>s1>>s2;
	    if(s1.length() != s2.length())  cout<<"NO"<<endl;
	    else
	    {
	        map<char, int> m1, m2;
	        for(int i=0; i<s1.length(); i++)
	        {
	            if(m1.find(s1[i]) != m1.end())  m1[s1[i]]++;
	            else  m1[s1[i]] = 1;
	        }
	        for(int i=0; i<s2.length(); i++)
	        {
	            if(m2.find(s2[i]) != m2.end())  m2[s2[i]]++;
	            else  m2[s2[i]] = 1;
	        }
	        map<char, int>:: iterator it1, it2;
	        for(it1=m1.begin(), it2=m2.begin(); it1!=m1.end(), 
	            it2!=m2.end(); it1++, it2++)
	        {
	            if(it1->first != it2->first || it1->second != it2->second)
	            {
	                cout<<"NO"<<endl;
	                f = 1;
	                break;
	            }
	        }
	        if(f == 0)  cout<<"YES"<<endl;
	    }
	}
	return 0;
}



// Missing and Multiple

#include <iostream>
using namespace std;

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n, missing, multiple;
	    cin>>n;
	    int a[n], b[n] = { 0 };
	    for(int i=0; i<n; i++) 
	    {
	        cin>>a[i];
	        b[a[i]-1]++;
	    }
	    for(int i=0; i<n; i++) 
	    {
	        if(b[i] == 0)  missing = i+1;
	        if(b[i] > 1)  multiple = i+1;
	    }
	    cout<<multiple<<" "<<missing<<endl;
	}
	return 0;
}



// Find Length of Loop

int countNodesinLoop(struct Node *head)
{
    Node *start, *ptr=head;
    Node *f=head->next->next, *s=head->next;
    while(s && f && f->next)
    {
        f = f->next->next;
        s = s->next;
        if(s == f)  break;
    }
    ptr = head;
    if(f == NULL || f->next == NULL)  return 0;
    else
    {
        unordered_set<Node *> s;
        while(s.find(ptr) == s.end())
        {
            s.insert(ptr);
            ptr = ptr->next;
        }
        start = ptr;
        int l=1;
        while(ptr->next != start)
        {
            l++;
            ptr = ptr->next;
        }
        return l;
    }
    return 1;
}



// Group Anagrams Together

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

string sorted(string s)
{
    for(int i=0; i<s.size()-1; i++)
    {
        for(int j=0; j<s.size()-i-1; j++)
        {
            if(s[j] > s[j+1])
            {
                char t = s[j];
                s[j] = s[j+1];
                s[j+1] = t;
            }
        }
    }
    return s;
}

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    string a[n];
	    map<string, int> m;
	    map<string, int> :: iterator it;
	    for(int i=0; i<n; i++)  
	    {
	        cin>>a[i];
	        a[i] = sorted(a[i]);
	        
	        if(m.find(a[i]) == m.end())  m[a[i]] = 1;
	        else  m[a[i]]++;
	    }
	    vector<pair<int, string>> v;
	    for(it=m.begin(); it!=m.end(); it++)
	    {
	        v.push_back(make_pair(it->second, it->first));
	    }
	    sort(v.begin(), v.end());
	    for(int i=0; i<v.size(); i++)  
	        cout<<v[i].first<<" ";
	    cout<<endl;
	}
	return 0;
}



// Quicksort

#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

int partition (int arr[], int low, int high)
{
    int key = arr[high], i=low, j=low-1;
    for(int i=low; i<high; i++)
    {
        if(arr[i] < key)
        {
            j++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    j++;
    int temp = arr[high];
    arr[high] = arr[j];
    arr[j] = temp;
    return j;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int arr[1000],n,T,i;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)  scanf("%d",&arr[i]);
        quickSort(arr, 0, n-1);
        printArray(arr, n);
    }
    return 0;
}



// Mergesort

#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int l, int m, int r)
{
    int left[m-l+1], right[r-m];
    for(int i=0; i<m-l+1; i++)  left[i] = arr[l+i];
    for(int i=0; i<r-m; i++)  right[i] = arr[m+i+1];
    int k=l, i=0, j=0;
    while(i < m-l+1 && j < r-m)
    {
        if(left[i] < right[j])
        {
            arr[k++] = left[i++];
        }
        else
        {
            arr[k++] = right[j++];
        }
    }
    while(j < r-m)
    {
        arr[k++] = right[j++];
    }
    while(i < m-l+1)
    {
        arr[k++] = left[i++];
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l+(r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int arr[1000],n,T,i;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d",&arr[i]);
        mergeSort(arr, 0, n-1);
        printArray(arr, n);
    }
    return 0;
}



// Smallest subarray with sum greater than x

#include <iostream>
using namespace std;

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n, m, l=1001;
	    cin>>n>>m;
	    int a[n];
	    for(int i=0; i<n; i++)  cin>>a[i];
	    for(int i=0; i<n; i++)
	    {
	        int sum = 0;
	        for(int j=i; j<n; j++)
	        {
	            sum = sum + a[j];
	            if(sum > m && l > j-i+1)  
	            {
	                l = j - i + 1;
	                break;
	            }
	        }
	    }
	    cout<<l<<endl;
	}
	return 0;
}



// Minimum Cost of Ropes

#include <iostream>
#include <queue>
using namespace std;

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    long long int n, sum=0;
	    cin>>n;
	    long long int a[n];
	    priority_queue<long long int, vector<long long int>, greater<long long int>> q;
	    for(int i=0; i<n; i++)
	    {
	        cin>>a[i];
	        q.push(a[i]);
	    }
	    while(q.size() != 1)
	    {
	        long long int x = q.top();
	        q.pop();
	        long long int y = q.top();
	        q.pop();
	        q.push(x+y);
	        sum = sum + x + y;
	    }
	    cout<<sum<<endl;
	}
	return 0;
}



// Heapsort

#include <bits/stdc++.h>
using namespace std;

void heapify(int arr[], int n, int i)  
{
    int largest = i; 
    int l = 2*i + 1; 
    int r = 2*i + 2; 
  
    if (l < n && arr[l] > arr[largest]) 
        largest = l; 
  
    if (r < n && arr[r] > arr[largest]) 
        largest = r; 
  
    if (largest != i) 
    { 
        int t = arr[i];
        arr[i] = arr[largest];
        arr[largest] = t;
        heapify(arr, n, largest); 
    }
}

void buildHeap(int arr[], int n)  
{ 
    for(int i=1; i<n; i++)
    {
        int j=i;
        while(j > 0 && arr[(j-1)/2] < arr[j])
        {
            int t = arr[j];
            arr[j] = arr[(j-1)/2];
            arr[(j-1)/2] = t;
            j = (j-1)/2;
        }
    }
}

void heapSort(int arr[], int n)
{
    buildHeap(arr, n);
    for (int i=n-1; i>=0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int arr[1000000],n,T,i;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d",&arr[i]);
        heapSort(arr, n);
        printArray(arr, n);
    }
    return 0;
}



// Binary Heap Operations

#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

void swap(int *x, int *y) 
{ 
    int temp = *x; 
    *x = *y; 
    *y = temp; 
}

struct MinHeap
{   
    int *harr; 
    int capacity;
    int heap_size;
    
    MinHeap(int c) 
    {     
       heap_size = 0;
       capacity = c;
       harr = new int[c];
    }
    
    ~MinHeap()
    {
        delete[] harr;
    }
    
    int parent(int i) 
    { 
        return (i-1)/2; 
    }
    
    int left(int i) 
    { 
        return (2*i + 1);
    }
    
    int right(int i) 
    { 
        return (2*i + 2);
    }
    
    void MinHeapify(int i)
    {
        int l = left(i);
        int r = right(i);
        int smallest = i;
        if (l < heap_size && harr[l] < harr[i])
            smallest = l;
        if (r < heap_size && harr[r] < harr[smallest])
            smallest = r;
        if (smallest != i)
        {
            swap(harr[i], harr[smallest]);
            MinHeapify(smallest);
        }
    }
    
    int extractMin()
    {
        if (heap_size <= 0) 
            return -1; 
        if (heap_size == 1) 
        { 
            heap_size--; 
            return harr[0]; 
        } 
        int root = harr[0]; 
        harr[0] = harr[heap_size-1]; 
        heap_size--; 
        MinHeapify(0); 
        return root; 
    }

    void decreaseKey(int i, int new_val)
    {
        harr[i] = new_val; 
        while (i != 0 && harr[parent(i)] > harr[i]) 
        { 
        swap(&harr[i], &harr[parent(i)]); 
        i = parent(i); 
        } 
    }
    
    void deleteKey(int i)
    {
        if(i < heap_size)
        {
            decreaseKey(i, INT_MIN); 
            extractMin();
        }
    }

    void insertKey(int k)
    {
        if (heap_size == capacity) 
        { 
            cout << -1; 
            return; 
        }
        heap_size++; 
        int i = heap_size - 1; 
        harr[i] = k; 
        while (i != 0 && harr[parent(i)] > harr[i]) 
        { 
            swap(&harr[i], &harr[parent(i)]); 
            i = parent(i); 
        }
    }
    
};

int main()
{
    int t;
    cin>>t;
    
    while(t--)
    {
        ll a;
        cin>>a;
        MinHeap h(a);
        for(ll i=0; i<a; i++)
        {
            int c;
            int  n;
            cin>>c;
            if(c==1)
            {  
                cin>>n;
                h.insertKey(n);
            }
            if(c==2)
            {  
                cin>>n;
                h.deleteKey(n);
            } 
            if(c==3)
            { 
                cout<<h.extractMin()<<" ";
            }
        
        }
        cout<<endl;
        h.harr=NULL;
    }
    return 0;
}




// Sum Tree

bool isSumTree(Node* root)
{
    if(root == NULL || (root->left == NULL && root->right == NULL))  
        return true;
    int sum = 0;
    if(root->left)  
    {
        if(root->left->left == NULL && root->left->right == NULL)
            sum = sum + (root->left->data);
        else  
            sum = sum + 2*(root->left->data);
    }
    if(root->right)  
    {
        if(root->right->left == NULL && root->right->right == NULL)
            sum = sum + (root->right->data);
        else  
            sum = sum + 2*(root->right->data);
    }
    if(sum != root->data)  return false;
    bool x = isSumTree(root->left);
    bool y = isSumTree(root->right);
    if(x & y)  return true;
    return false;
}



// Root to leaf path sum

bool hasPathSum(Node *node, int sum)
{
    if(node == NULL)  return false;
    if(node->left == NULL && node->right == NULL)
    {
        if(sum - node->data == 0)  return true;
        else  return false;
    }
    bool x = hasPathSum(node->left, sum - node->data);
    bool y = hasPathSum(node->right, sum - node->data);
    if(x || y)  return true;
    else  return false;
}



// Binary tree to DLL

void bToDLL(Node *root, Node **head_ref)
{
    if (root == NULL)  return; 
    
    bToDLL(root->right, head_ref); 
     
    root->right = *head_ref; 
    
    if (*head_ref != NULL)  
        (*head_ref)->left = root; 

    *head_ref = root; 
   
    bToDLL(root->left, head_ref);
}



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




// Total Decoding Messages

#include <iostream>
using namespace std;

int totalDecode(string s, int n)
{
    int a[n+1];
    a[n] = 1;
    if(s[n-1] == '0')  a[n-1] = 0;
    else  a[n-1] = 1;
    for(int i=n-2; i>=0; i--)
    {
        if(s[i] == '0')  a[i] = 0;
        else if((s[i]-48)*10 + (s[i+1]-48) > 26)  a[i] = a[i+1];
        else  a[i] = a[i+1] + a[i+2];
    }
    return a[0];
}

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    string s;
	    cin>>s;
	    cout<<totalDecode(s, n)<<endl;
	}
	return 0;
}




// Number Formation - (INCOMPLETE)

#include <iostream>
using namespace std;

long long int numform(int x, int y, int z)
{
    long long int m[x+1][y+1][z+1] = { 0 };
    for(int i=0; i<=x; i++)
    {
        for(int j=0; j<=y; j++)
        {
            for(int k=0; k<=z; k++)
            {
                if(k != 0)  m[i][j][k] = m[i][j][k] + 10*m[i][j][k-1] + 6;
                if(j != 0)  m[i][j][k] = m[i][j][k] + 10*m[i][j-1][k] + 5;
                if(i != 0)  m[i][j][k] = m[i][j][k] + 10*m[i-1][j][k] + 4;
            }
        }
    }
    long long int sum=0;
    for(int i=0; i<=x; i++)
    {
        for(int j=0; j<=y; j++)
        {
            for(int k=0; k<=z; k++)
            {
                sum = sum + m[i][j][k];
                // cout<<m[i][j][k]<<" ";
            }
        }
    }
    return sum+15;
}

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    int x, y, z;
	    cin>>x>>y>>z;
	    cout<<numform(x, y, z)<<endl;
	}
	return 0;
}


// BFS of a Graph

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        
        int N, E;
        cin>>N>>E;
        vector<int> adj[N];
        bool vis[N];
        for(int i=0;i<E;i++)
        {
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
        }
        
        bfs(0, adj, vis);
        cout<<endl;
    }
}

void bfs(int s, vector<int> adj[], bool vis[])
{
    queue<int> q;
    q.push(s);
    vis[s] = true;
    while(!q.empty())
    {
        for(int i=0; i<adj[q.front()].size(); i++)
        {
            if(vis[adj[q.front()][i]] == false)
            {
                q.push(adj[q.front()][i]);
                vis[adj[q.front()][i]] = true;
            }
        }
        cout<<q.front()<<" ";
        q.pop();
    }
}



// Topological Sort

#include<bits/stdc++.h>
using namespace std;

bool check(int V, int* res, vector<int> adj[])
{
    bool flag =true;
    for(int i=0; i<V && flag;i++)
    {
        int n=adj[res[i]].size();
        for(auto j : adj[res[i]])
        {
            for(int k=i+1;k<V;k++)
            {
                if(res[k]==j )
                    n--;
            }
        }
        if(n!=0)
            flag =false;
    }
    if(flag==false)
        return 0;
    return 1;
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N,E;
        cin>>E>>N;
        int u,v;
        
        vector<int> adj[N];
        
        for(int i=0;i<E;i++)
        {
            cin>>u>>v;
            adj[u].push_back(v);
        }
    
        int *res = topoSort(N, adj);
        
        cout<<check(N, res, adj)<<endl;
       
    }
}

void topologicalSortUtil(int v, bool visited[], stack<int> &Stack, vector<int> adj[]) 
{ 
    visited[v] = true; 
    
    for (int i=0; i<adj[v].size(); i++) 
    {
        if (!visited[adj[v][i]])  
            topologicalSortUtil(adj[v][i], visited, Stack, adj); 
    }
    
    Stack.push(v); 
}

int* topoSort(int V, vector<int> adj[])
{
    stack<int> Stack; 
    bool *visited = new bool[V]; 
    
    for (int i = 0; i < V; i++) 
        visited[i] = false; 
        
    for (int i = 0; i < V; i++) 
    {
        if (visited[i] == false) 
            topologicalSortUtil(i, visited, Stack, adj); 
    }
    
    int *arr = new int[V];
    
    for(int i=0; i<V; i++)
    {
        arr[i] = Stack.top();
        Stack.pop(); 
    }
    
    return arr; 
}



// Detect cycle in an undirected graph

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int V, E;
        cin>>V>>E;
        
        vector<int> adj[V];
        
        int u, v;
        for(int i=0;i<E;i++)
        {
            cin>>u>>v;
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        cout << isCyclic(adj, V)<<endl;
    }
}

bool dfs(int i, vector<int> arr[], int parent[], bool vis[])
{
    vis[i] = true;
    for(int j=0; j<arr[i].size(); j++)
    {
        if(i == arr[i][j])  
            return true;
        
        if(vis[arr[i][j]] && parent[i] != arr[i][j])
            return true;
        
        if(!vis[arr[i][j]])
        {
            parent[arr[i][j]] = i;
            if(dfs(arr[i][j], arr, parent, vis))  
                return true;
        }
    }
    return false;

}


bool isCyclic(vector<int> adj[], int n)
{
    int parent[n];
    for(int i=0; i<n; i++)  parent[i] = -1;
    
    bool vis[n] = { false };
  
    for(int i=0; i<n; i++)
    {
        if(!vis[i] && dfs(i, adj, parent, vis))  
            return true;
    }
    
    return false;
}




// Detect cycle in a directed graph

#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int v, e;
	    cin >> v >> e;
	    
	    vector<int> adj[v];
	    
	    for(int i =0;i<e;i++){
	        int u, v;
	        cin >> u >> v;
	        adj[u].push_back(v);
	    }
	    
	    cout << isCyclic(v, adj) << endl;
	    
	}
	
	return 0;
}

bool fn(vector<int> adj[], int i, bool vis[], bool temp[])
{
    vis[i] = true;
    temp[i] = true;
    for(int j=0; j<adj[i].size(); j++)
    {
        if(!vis[adj[i][j]] && fn(adj, adj[i][j], vis, temp))
            return true;
        else if (temp[adj[i][j]]) 
            return true; 
    }
    temp[i] = false;
    return false;
}

bool isCyclic(int V, vector<int> adj[])
{
    bool vis[V] = { false };
    bool temp[V] = { false };
    
    for(int i=0; i<V; i++)
    {
        if(fn(adj, i, vis, temp))  
            return true;
    }
    return false;
}




// Find Number of Islands

#include <bits/stdc++.h>
using namespace std;

int main() {
    
	int T;
	cin>>T;
	while(T--)
	{
		int N,M;
		cin>>N>>M;
		vector<int> A[N];
		for(int i=0;i<N;i++){
		    vector<int> temp(M);
		    A[i] = temp;
		    for(int j=0;j<M;j++){
		        cin>>A[i][j];
		    }
		}
		cout<<findIslands(A,N,M)<<endl;
	}
	return 0;
}

void fn(vector<int> a[], bool b[50][50], int n, int m, int i, int j)
{
    if(i<0 || j<0 || i>=n || j>=m || a[i][j] == 0 || b[i][j] == true)  return;
    b[i][j] = true;
    fn(a, b, n, m, i-1, j-1);
    fn(a, b, n, m, i-1, j);
    fn(a, b, n, m, i-1, j+1);
    fn(a, b, n, m, i, j-1);
    fn(a, b, n, m, i, j+1);
    fn(a, b, n, m, i+1, j-1);
    fn(a, b, n, m, i+1, j);
    fn(a, b, n, m, i+1, j+1);
}

int findIslands(vector<int> a[], int n, int m)
{
    bool b[50][50] = { false };
    int count = 0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(b[i][j] == false && a[i][j] == 1)
            {
                count++;
                fn(a, b, n, m, i, j);
            }
        }
    }
    return count;
}





// Implementing Dijkstra's Algorithm

#include<bits/stdc++.h>
using namespace std;
void dijkstra(vector<vector<int>> , int ,int );
int main()
{
    int t;
    int V;
    cin>>t;
    while(t--){
        cin>>V;
        
        vector<vector<int>> g(V);
        
        for(int i = 0;i<V;i++){
            vector<int> temp(V);
            g[i] = temp;
        }
        
        for(int i=0;i<V;i++)
        {
      	    for(int j=0;j<V;j++)
      	    {
      		    cin>>g[i][j];
      	    }
        }
        
        int s;
        cin>>s;
        
        dijkstra(g, s, V);
        cout<<endl;
       }
        return 0;
}

int min_index(int *v, int n, bool *visited)
{   
    int min=INT_MAX;
    int min_vertex;
    for(int i=0; i<n; i++)
    {
        if(v[i]<min && visited[i]==false)
        {
            min=v[i];
            min_vertex = i;
        }
    }
    return min_vertex;
}

void dijkstra(vector<vector<int>> graph, int src, int V)
{
    bool visited[V] = { false };
    int weights[V];
    weights[src]=0;
    
    for(int i=0; i<V; i++)
    {   
        if(i != src)
            weights[i] = INT_MAX;
    }
    
    for(int i=0; i<V; i++)
    {
        int min_vertex = min_index(weights, V, visited);
        visited[min_vertex]=true;
        for(int i=0; i<V; i++)
        {
            if(graph[min_vertex][i]>=1 && visited[i]==false)
            {
                if(graph[min_vertex][i] + weights[min_vertex] < weights[i])
                {
                    weights[i] = graph[min_vertex][i] + weights[min_vertex];
                } 
            }
        }
    }
    
    for(int i=0;i<V;i++)
        cout << weights[i] << " ";
}



// Reverse a Linked List

#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

void append(struct Node** head_ref, struct Node **tail_ref, int new_data)
{
    struct Node* new_node = new Node(new_data);
    
    if (*head_ref == NULL)
        *head_ref = new_node;
    else
        (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}
struct Node *reverseList(struct Node *head);

void printList(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
       printf("%d ", temp->data);
       temp  = temp->next;
    }
}

int main()
{
    int T,n,l;
    cin>>T;
    while(T--)
    {
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        for (int i=1; i<=n; i++)
        {
            cin>>l;
            append(&head, &tail, l);
        }
       head = reverseList(head);
       printList(head);
       cout << endl;
    }
    return 0;
}

Node* reverseList(Node *head)
{
    int flag=0;
    if(head->next == NULL)  return head;
    Node *ptr=head->next, *preptr=head, *t=ptr->next, *h; 
    while(ptr != NULL)
    {
        ptr->next = preptr;
        if(flag == 0)
        {
            preptr->next = NULL;
            flag = 1;
        }
        
        preptr = ptr;
        ptr = t;
        if(t)
        {
            t = t->next;
        }
    }
    return preptr;
}



// Minimum number of flips

#include <bits/stdc++.h>
using namespace std;

int min(int a, int b)
{
    return (a<b) ? a : b;
}

int flips(string s)
{
    int c=0;
    for(int i=0; i<s.size(); i++)
    {
        if(i%2 != s[i] - 48)  
        {
            c++;
        }
    }
    return min(s.size()-c, c);
}

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    string s;
	    cin>>s;
	    cout<<flips(s)<<endl;
	}
	return 0;
}



// Ugly Numbers

#include <bits/stdc++.h>
using namespace std;

long long int getNthUglyNo(long long int n, long long int ugly[]) 
{ 
    // long long int ugly[n]; 
    long long int i = 0, j = 0, k = 0; 
    long long int z1 = 2, z2 = 3, z3 = 5; 
    long long int next_ugly_no = 1; 
  
    ugly[0] = 1; 
    for (int p=1; p<n; p++) 
    { 
        next_ugly_no = min(z1, min(z2, z3)); 
        ugly[p] = next_ugly_no; 
        
        if (next_ugly_no == z1) 
        { 
            i = i+1; 
            z1 = ugly[i]*2; 
        } 
        if (next_ugly_no == z2) 
        { 
            j = j+1; 
            z2 = ugly[j]*3; 
        } 
        if (next_ugly_no == z3) 
        { 
            k = k+1; 
            z3 = ugly[k]*5; 
        } 
    }
    return next_ugly_no; 
} 

int main() 
{
	int t;
	scanf("%d", &t);
	long long int a[10000];
	getNthUglyNo(10000, a);
	while(t--)
	{
	    int n;
	    scanf("%d", &n);
	   // cout<<getNthUglyNo(n)<<endl;
	    cout<<a[n-1]<<endl;
	}
	return 0;
}



// Wave Array

#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0; i<n; i++)
	    {
	        cin>>a[i];
	    }
	    for(int i=0; i<n; i+=2)
	    {
	        if(i+1 < n)
	        {
	            int t = a[i];
	            a[i] = a[i+1];
	            a[i+1] = t;
	        }
	    }
	    for(int i=0; i<n; i++)
	    {
	        cout<<a[i]<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}



// Non-Repeating Element

#include <iostream>
#include <unordered_map>
using namespace std;

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    long long int a[n];
	    for(int i=0; i<n; i++)  cin>>a[i];
	    unordered_map<long long int, int> m;
	    int i=0;
	    for(int j=0; j<n; j++)
	    {
	        if(m.find(a[j]) == m.end())
	        {
	            m[a[j]] = 1;
	        }
	        else
	        {
	            m[a[j]]++;
	            if(a[j] == a[i])
	            {
	                while(i<=j && m[a[i]] != 1)
	                {
	                    i++;
	                }
	            }
	        }
	    }
	    if(i >= n)  cout<<0<<endl;
	    else  cout<<a[i]<<endl;
	}
	return 0;
}



// Knight Walk

#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        cin>>n>>m;
        int xst, yst, xen, yen;
        cin>>xst>>yst>>xen>>yen;
        bool vis[n+1][m+1];
        int a[n+1][m+1];
        for(int i=0; i<=n; i++)
        {
            for(int j=0; j<=m; j++)
            {
                vis[i][j]=true;
                a[i][j]=INT_MAX;
            }
        }
        
        queue<pair<int,int>>q;
        a[xst][yst]=0;
        q.push(make_pair(xst,yst));
        int xinc[]={1, -1, 1, -1, 2, -2, 2, -2};
        int yinc[]={2, 2, -2, -2, 1, 1, -1, -1};
        
        while(!q.empty())
        {
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            
            for(int i=0;i<8;i++)
            {
                int xin = x + xinc[i];
                int yin = y + yinc[i];
                
                if(xin>0 && xin<=n && yin>0 && yin<=m && vis[xin][yin])
                {
                    vis[xin][yin]=false;
                    if(a[xin][yin]>a[x][y]+1)
                    {
                        a[xin][yin]=a[x][y]+1;
                        q.push(make_pair(xin,yin));
                    }
                }
            }
        }
      
        if(a[xen][yen]==INT_MAX)  cout<<-1<<endl;
        else  cout<<a[xen][yen]<<endl;
    }
	return 0;
}



// Search in a Matrix 

// Recursive 

#include <iostream>
using namespace std;

int mat(int a[30][30], int n, int m, int i, int j, int v)
{
    if(i>n || j>m || i<0 || j<0)  return 0;
    else if(a[i][j] == v)  return 1;
    else if(i == n-1)  return mat(a, n, m, i, j+1, v);
    else if(j == m-1)  return mat(a, n, m, i+1, j, v);
    return (mat(a, n, m, i+1, j, v) | mat(a, n, m, i, j+1, v));
}

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n, m, v;
	    cin>>n>>m;
	    int a[30][30];
	    for(int i=0; i<n; i++)
	    {
	        for(int j=0; j<m; j++)
	        {
	            cin>>a[i][j];
	        }
	    }
	    cin>>v;
	    cout<<mat(a, n, m, 0, 0, v)<<endl;
	}
	return 0;
}

// Efficient

#include <iostream>
using namespace std;

int mat(int a[30][30], int n, int m, int i, int j, int v)
{
    while(i<n && j<m && i>=0 && j>=0)
    {
        if(v < a[i][j])  j--;
        else if(v > a[i][j])  i++;
        else if(v == a[i][j])  return 1;
    }
    return 0;
}

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n, m, v;
	    cin>>n>>m;
	    int a[30][30];
	    for(int i=0; i<n; i++)
	    {
	        for(int j=0; j<m; j++)
	        {
	            cin>>a[i][j];
	        }
	    }
	    cin>>v;
	    cout<<mat(a, n, m, 0, m-1, v)<<endl;
	}
	return 0;
}



// Array Pair Sum Divisibility Problem

#include <iostream>
using namespace std;

bool divis(int a[], int n, int k)
{
    bool b[n] = { false };
    for(int i=0; i<n-1; i++)
    {
        if(b[i] == false)
        {
            for(int j=i+1; j<n; j++)
            {
                if(b[j] == false)
    	        {
    	            if((a[i]+a[j]) % k == 0)
    	            {
    	                b[i] = true;
    	                b[j] = true;
    	                break;
    	            }
    	        }
            }
            if(b[i] == false)  return false;
        }
    }
    for(int i=0; i<n; i++)
    {
        if(b[i] == false)  
            return false;
    }
    return true;
}

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>>n;
	    int a[n];
	    for(int i=0; i<n; i++)  cin>>a[i];
	    cin>>k;
	    bool x;
	    if(n%2 != 0)  x = false;
	    else  x = divis(a, n, k);
	    if(x == false)  cout<<"False"<<endl;
	    else  cout<<"True"<<endl;
	}
	return 0;
}




// Unique BST


// Recursive

#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<numTrees(n)<<"
";
    }
}	
int numTrees(int n) 
{
    if(n == 0 || n == 1)  return 1;
    int res = 0;
    for(int i=1; i<=n; i++)
    {
        res += numTrees(i-1)*numTrees(n-i); 
    }
    return res;
}


// Dynamic Programming

#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<numTrees(n)<<"
";
    }
}	
int numTrees(int n) 
{
    int a[n+1];
    a[0] = 1;
    if(n > 0)  a[1] = 1;
    for(int i=2; i<=n; i++)
    {
        int res = 0;
        for(int j=1; j<=i; j++)
        {
            res += a[j-1]*a[i-j];
        }
        a[i] = res;
    }
    return a[n];
}




// Linked List

#include <iostream>

class linkedlist
{
    struct Node
    {
        int data;
        Node *next;
        
        Node(int x)
        {
            data = x;
            next = NULL;
        }
    };
    Node *head = NULL;
    
    public:
    
    void add(int x)
    {
        Node *n = new Node(x);
        if(head == NULL)  head = n;
        else
        {
            Node *ptr = head;
            while(ptr->next != NULL)
                ptr = ptr->next;
            ptr->next = n;
        }
    }
    
    void display()
    {
        Node *ptr = head;
        while(ptr != NULL)
        {
            std::cout<<ptr->data<<" ";        
            ptr = ptr->next;
        }
    }
};

int main() 
{
    int x, y, z;
	std::cin>>x>>y>>z;
	linkedlist l;
	l.add(x);
	l.add(y);
	l.add(z);
	l.display();
	return 0;
}



// Stack

#include <iostream>

class stack
{
    int *a, n, i;
    
    public:
    
    stack(int x)
    {
        a = new int[x];
        n = x;
        i = -1;
    }
    
    bool empty()
    {
        if(i == -1)  return true;
        else  return false;
    }
    
    int top()
    {
        return a[i];
    }
    
    void push(int x)
    {
        i++;
        a[i] = x;
    }
    
    void pop()
    {
        i--;
    }

};

int main() 
{
    int x, y, z;
	std::cin>>x>>y>>z;
	stack s(3);
	std::cout<<s.empty()<<std::endl;
	s.push(x);
	s.push(y);
	std::cout<<s.top()<<std::endl;
	s.pop();
	s.push(z);
	std::cout<<s.empty()<<std::endl;
	return 0;
}


// Queue

#include <iostream>

class queue
{
    int *a, n, f, b;
    
    public:
    
    queue(int x)
    {
        a = new int[x];
        n = x;
        f = -1;
        b = -1;
    }
    
    bool empty()
    {
        if(f == -1 && b == -1)  return true;
        else  return false;
    }
    
    int front()
    {
        return a[f];
    }
    
    void push(int x)
    {
        if(b == n-1)  b = 0;
        else  b++;
        a[b] = x;
        if(f == -1)  f++;
    }
    
    void pop()
    {
        if(f == b)  
        {
            f = -1;
            b = -1;
        }
        else if(f == n-1)  f = 0;
        else  f++;
    }

};

int main() 
{
    int x, y, z;
	std::cin>>x>>y>>z;
	queue q(3);
	std::cout<<q.empty()<<std::endl;
	q.push(x);
	q.push(y);
	std::cout<<q.front()<<std::endl;
	q.pop();
	std::cout<<q.front()<<std::endl;
	q.push(z);
	std::cout<<q.empty()<<std::endl;
	return 0;
}



// Largest square formed in a matrix

#include <iostream>
using namespace std;

int min(int a, int b, int c)
{
    if(a<=b && a<=c)  return a;
    else if(b<=a && b<=c)  return b;
    else  return c;
}

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    int m, n;
	    cin>>m>>n;
	    int a[m][n];
	    for(int i=0; i<m; i++)
	    {
	        for(int j=0; j<n; j++)
	        {
	            cin>>a[i][j];
	        }
	    }
	    int b[m][n], mx = -1;
	    for(int i=0; i<m; i++)  b[i][0] = a[i][0];
	    for(int j=0; j<n; j++)  b[0][j] = a[0][j];
	    for(int i=1; i<m; i++)
	    {
	        for(int j=1; j<n; j++)
	        {
	            if(a[i][j] == 1)
	                b[i][j] = 1 + min(b[i-1][j], b[i-1][j-1], b[i][j-1]);
	            else
	                b[i][j] = 0;
	        }
	    }
	    for(int i=0; i<m; i++)
	    {
	        for(int j=0; j<n; j++)
	        {
	            if(b[i][j] > mx)  mx = b[i][j];
	        }
	    }
	    cout<<mx<<endl;
	}
	return 0;
}



// Path in Matrix

#include <iostream>
using namespace std;

int max(int a, int b, int c)
{
    if(a>=b && a>=c)  return a;
    else if(b>=a && b>=c)  return b;
    else  return c;
}

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int a[n][n], b[n][n];
	    for(int i=0; i<n; i++)
	    {
	        for(int j=0; j<n; j++)
	        {
	            cin>>a[i][j];
	        }
	    }
	    for(int i=0; i<n; i++)
	    {
	        b[0][i] = a[0][i];
	    }
	    for(int i=1; i<n; i++)
	    {
	        for(int j=0; j<n; j++)
	        {
	            if(j>0 && j<n-1) 
	            {
	                b[i][j] = a[i][j] + max(b[i-1][j-1], b[i-1][j], b[i-1][j+1]);
	            }
	            else if(j == 0)
	            {
	                b[i][j] = a[i][j] + max(b[i-1][j], b[i-1][j+1], -1);
	            }
	            else
	            {
	                b[i][j] = a[i][j] + max(b[i-1][j-1], b[i-1][j], -1);
	            }
	        }
	    }
	    int mx = -1;
	    for(int i=0; i<n; i++)
	    {
	        if(mx < b[n-1][i])  mx = b[n-1][i];
	    }
	    cout<<mx<<endl;
	}
	return 0;
}



// Bipartite Graph

#include <bits/stdc++.h>
using namespace std;
const int MAX = 100;
bool isBipartite(int G[][MAX],int V);
int main()
{
    int t;
	cin>>t;
	int g[MAX][MAX];
	while(t--)
	{
		memset(g,0,sizeof (g));
		int n;
		cin>>n;
	
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cin>>g[i][j];
			}
		}
		
		cout<<isBipartite(g,n)<<endl;
	}
	return 0;
}


bool colorGraph(int G[][MAX],int color[],int pos, int c, int V)
{
    if(color[pos] != -1 && color[pos] != c) 
        return false; 
          
    color[pos] = c; 
    bool ans = true; 
    for(int i=0; i<V; i++)
    { 
        if(G[pos][i])
        { 
            if(color[i] == -1) 
                ans &= colorGraph(G, color, i, 1-c, V); 
                  
            if(color[i] != -1 && color[i] != 1-c) 
                return false; 
        } 
        if (!ans) 
            return false; 
    } 
      
    return true; 
}

bool isBipartite(int G[][MAX], int V)
{
    int color[V]; 
    for(int i=0;i<V;i++) 
        color[i] = -1; 
    
    for(int i=0; i<V; i++) 
    {
        if(G[i][i] != 0)
            return false;
    }
    
    int pos = 0; 
    return colorGraph(G, color, pos, 1, V); 
}


// Transform One String to Another using Minimum Number of Given Operation

#include<bits/stdc++.h> 
using namespace std; 
  
int minOps(string& A, string& B) 
{ 
    int m = A.length(), n = B.length(); 
    
    if (n != m) 
       return -1; 
    
    int count[256]; 
    memset(count, 0, sizeof(count)); 
    
    for (int i=0; i<n; i++)   
       count[B[i]]++; 
    
    for (int i=0; i<n; i++)    
       count[A[i]]--;         
    
    for (int i=0; i<256; i++)   
      if (count[i]) 
         return -1; 
  
    int res = 0; 
    for (int i=n-1, j=n-1; i>=0; ) 
    { 
        while (i>=0 && A[i] != B[j]) 
        { 
            i--; 
            res++; 
        } 
  
        if (i >= 0) 
        { 
            i--; 
            j--; 
        } 
    } 
    return res; 
} 
  
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s1, s2;
        cin>>s1>>s2;
        cout<<minOps(s1, s2);
    }
    return 0; 
} 



// Bleak Numbers

/*
Given an integer, check whether it is Bleak or not.

A number ‘n’ is called Bleak if it cannot be represented as sum of a positive number x and set bit count in x, 
i.e., x + countSetBits(x) is not equal to n for any non-negative number x.

Examples :

3 is not Bleak as it can be represented
as 2 + countSetBits(2).

4 is t Bleak as it cannot be represented 
as sum of a number x and countSetBits(x)
for any number x.
*/

#include <iostream>
using namespace std;

int csb(int n)
{
    int c=0;
    while(n != 0)
    {
        if(n%2 == 1)  c++;
        n = n/2;
    }
    return c;
}

int bleak(int n)
{
    for(int i=n; i>=0; i--)
    {
        if(n == i + csb(i))  
            return 0;
    }
    return 1;
}

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    cout<<bleak(n)<<endl;
	}
	return 0;
}



// Find whether path exists

#include <iostream>
using namespace std;

bool path(int a[20][20], bool b[20][20], int n, int i, int j)
{
    if(i<0 || j<0 || i==n || j==n || a[i][j] == 0 || b[i][j])  return false;
    if(a[i][j] == 2)  return true;
    b[i][j] = true;
    if(path(a, b, n, i+1, j) | path(a, b, n, i, j+1) | path(a, b, n, i, j-1) | path(a, b, n, i-1, j))  
        return true;
    return false;
}

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n, p=0, q=0;
	    cin>>n;
	    int a[20][20];
	    bool b[20][20];
	    for(int i=0; i<n; i++)
	    {
	        for(int j=0; j<n; j++)
	        {
	            cin>>a[i][j];
	            b[i][j] = false;
	            if(a[i][j] == 1) 
	            {
	                p = i;
	                q = j;
	            }
	        }
	    }
	    bool ispath = path(a, b, n, p, q);
	    if(ispath)  cout<<1;
	    else  cout<<0;
	    cout<<endl;
	}
	return 0;
}



// Shortest Path

#include<bits/stdc++.h>
using namespace std;
#define INF 999999
int t,n,m,arr[20][20],x,y,dp[20][20];
bool vis[20][20];

int solve(int i, int j, int x, int y)
{
	if(arr[i][j]==0 || vis[i][j])  return INF;
	if(i==x && j==y)  return 0;
	if(dp[i][j]<INF)  return dp[i][j];
	
	vis[i][j]=true;
	if(i+1<n && !vis[i+1][j])  dp[i][j]=min(dp[i][j], solve(i+1,j,x,y));
	if(i-1>=0 && !vis[i-1][j])  dp[i][j]=min(dp[i][j], solve(i-1,j,x,y));
	if(j+1<m && !vis[i][j+1])  dp[i][j]=min(dp[i][j], solve(i,j+1,x,y));
	if(j-1>=0 && !vis[i][j-1])  dp[i][j]=min(dp[i][j], solve(i,j-1,x,y));
	
	
    dp[i][j]+=1;
	return dp[i][j];
}

bool possible(int i,int j,int x,int y)
{

    if(arr[i][j]==0)
    return false;
    
    if(i==x && j==y)return true;
    
    vis[i][j]=true;
    
    if(i+1<n && !vis[i+1][j])
    {
     if(possible(i+1,j,x,y))
       return true;
    }
    if(i-1>=0 && !vis[i-1][j])
    {
        if(possible(i-1,j,x,y))
          return true;
    }
    if(j+1<m && !vis[i][j+1])
    {
        if(possible(i,j+1,x,y))
         return true;
    }
    if(j-1>=0 && !vis[i][j-1])
    {
        if(possible(i,j-1,x,y))
          return true;
    }
    return false;
    
}

int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>arr[i][j];
                
            }
        }
        memset(vis,false,sizeof(vis));
        cin>>x>>y;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                dp[i][j]=INF;
            }
        }
        
        if(possible(0,0,x,y))
        {
        	memset(vis,false,sizeof(vis));
            cout<<solve(0,0,x,y)<<endl;
        }
        else 
        {
            cout<<-1<<endl;
        }
    }
}



// Euler Path and Circuit

#include<bits/stdc++.h>
#include <list>
using namespace std;
class Graph
{
    int V;
    list<int> *adj;
public:
    Graph(int V)   {this->V = V; adj = new list<int>[V]; }
    ~Graph() { delete [] adj; }
    void addEdge(int v, int w);
    int isEulerian();
    bool isConnected();
    void DFSUtil(int v, bool visited[]);
};
 
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}
 
void Graph::DFSUtil(int v, bool visited[])
{
    visited[v] = true;
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFSUtil(*i, visited);
}
void test(Graph &g)
{
    int res = g.isEulerian();
    if (res == 0)
        cout << "0
";    //none
    else if (res == 1)
        cout << "1
";    //Euler path
    else
        cout << "2
";    //Euler cycle
}
int main()
{
	int t;
	cin>>t;
	while(t--){
		int v,e;
		cin>> v>>e;
		Graph g1(v);
		for(int i=0;i<e;i++){
			int a,b;
			cin>>a>>b;
		g1.addEdge(a, b);
		}
		test(g1);
	}
    return 0;
}

bool Graph::isConnected() 
{
//add code here.    
}
int Graph::isEulerian()
{
    int even=0, odd=0;
    
    for(int i=0; i<V; i++)
    {
        if(adj[i].size()%2!=0)
            odd++;
        else
            even++;
    }
    
    if(even==V)
        return 2;
    if(odd==2)
        return 1;
    return 0;
}



// Longest Palindrome in a String

#include <bits/stdc++.h> 
using namespace std; 

void printSubStr( string str, int low, int high ) 
{ 
	for( int i = low; i <= high; ++i ) 
		cout << str[i]; 
} 

int longestPalSubstr(string str) 
{ 
	int n = str.size(); 
	bool table[n][n]; 
	
	memset(table, 0, sizeof(table)); 

	int maxLength = 1; 
	
	for (int i = 0; i < n; ++i) 
		table[i][i] = true; 

	int start = 0; 
	for (int i = 0; i < n-1; ++i) 
	{ 
		if (str[i] == str[i+1]) 
		{ 
			table[i][i+1] = true; 
			start = i; 
			maxLength = 2; 
		} 
	} 

	for (int k = 3; k <= n; ++k) 
	{ 
		for (int i = 0; i < n-k+1 ; ++i) 
		{ 
			int j = i + k - 1; 

			if (table[i+1][j-1] && str[i] == str[j]) 
			{ 
				table[i][j] = true; 

				if (k > maxLength) 
				{ 
					start = i; 
					maxLength = k; 
				} 
			} 
		} 
	} 

    cout << "Longest palindrome substring is: "; 
    printSubStr( str, start, start + maxLength - 1 ); 
	
	return maxLength; 
} 

int main() 
{ 
	string str = "forgeeksskeegfor"; 
	cout << "\nLength is: " << longestPalSubstr( str ); 
	return 0; 
} 



// Convert to Sum Tree

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
void toSumTree(struct Node *node);

void printInorder(struct Node* node)
{
     if (node == NULL)
          return;
     printInorder(node->left);
     printf("%d ", node->data);
     printInorder(node->right);
}

struct Node* newNode(int data)
{
  struct Node* node = new Node;
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return(node);
}

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
     toSumTree(root);
     printInorder(root);
     printf("
");
  }
  return 0;
}
/* Utillity function to check if the given node is leaf or not */
int isLeaf(struct Node *node)
{
    if(node == NULL)
        return 0;
    if(node->left == NULL && node->right == NULL)
        return 1;
    return 0;
}
/* returns 1 if SumTree property holds for the given
    tree */
bool isSumTree(struct Node* node)
{
    int ls; // for sum of nodes in left subtree
    int rs; // for sum of nodes in right subtree
    /* If node is NULL or it's a leaf node then
       return true */
    if(node == NULL || isLeaf(node))
        return 1;
    if( isSumTree(node->left) && isSumTree(node->right))
    {
        // Get the sum of nodes in left subtree
        if(node->left == NULL)
            ls = 0;
        else if(isLeaf(node->left))
            ls = node->left->data;
        else
            ls = 2*(node->left->data);
        // Get the sum of nodes in right subtree
        if(node->right == NULL)
            rs = 0;
        else if(isLeaf(node->right))
            rs = node->right->data;
        else
            rs = 2*(node->right->data);
        /* If root's data is equal to sum of nodes in left
           and right subtrees then return 1 else return 0*/
        return(node->data == ls + rs);
    }
    return 0;
}

int st(Node *root)
{
    if(root == NULL)  return 0;
    if(root->left == NULL && root->right == NULL) 
    {
        int x = root->data;
        root->data = 0;
        return x;
    }
    int d = root->data, l = st(root->left), r = st(root->right);
    root->data = l + r;
    return l + r + d;
}

void toSumTree(Node *node)
{
    st(node);
}



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





// Print BST elements in given range

#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node* right;
    Node* left;
    
    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};
Node *insert(Node *root,int data)
{
    if(root==NULL)
    root=new Node(data);
    else if(data<root->data)
    root->left=insert(root->left,data);
    else
    root->right=insert(root->right,data);
    
    return root;
}
//Position this line where user code will be pasted.
int main() {
    
    int testcases;
    cin>>testcases;
    while(testcases--)
    {
        Node *root=NULL;
        int sizeOfArray;
        cin>>sizeOfArray;
        int arr[sizeOfArray];
        
        for(int i=0;i<sizeOfArray;i++)
        cin>>arr[i];
        
        for(int i=0;i<sizeOfArray;i++)
        {
            root=insert(root,arr[i]);
        }
        int l,h;
        cin>>l>>h;
        printNearNodes(root,l,h);
        cout<<endl;
    }
	return 0;
}

void printNearNodes(Node *root, int l, int h)
{
    if(root == NULL)  return;
    printNearNodes(root->left, l, h);
    if(root->data >= l && root->data <= h)  cout<<root->data<<" ";
    printNearNodes(root->right, l, h);
}








// C++ program to find path between two 
// cell in matrix 
#include<bits/stdc++.h> 
using namespace std; 
#define N 4 

class Graph 
{ 
	int V ; 
	list < int > *adj; 
public : 
	Graph( int V ) 
	{ 
		this->V = V ; 
		adj = new list<int>[V]; 
	} 
	void addEdge( int s , int d ) ; 
	bool BFS ( int s , int d) ; 
}; 

// add edge to graph 
void Graph :: addEdge ( int s , int d ) 
{ 
	adj[s].push_back(d); 
	adj[d].push_back(s); 
} 

// BFS function to find path from source to sink 
bool Graph :: BFS(int s, int d) 
{ 
	// Base case 
	if (s == d) 
		return true; 

	// Mark all the vertices as not visited 
	bool *visited = new bool[V]; 
	for (int i = 0; i < V; i++) 
		visited[i] = false; 

	// Create a queue for BFS 
	list<int> queue; 

	// Mark the current node as visited and 
	// enqueue it 
	visited[s] = true; 
	queue.push_back(s); 

	// it will be used to get all adjacent 
	// vertices of a vertex 
	list<int>::iterator i; 

	while (!queue.empty()) 
	{ 
		// Dequeue a vertex from queue 
		s = queue.front(); 
		queue.pop_front(); 

		// Get all adjacent vertices of the 
		// dequeued vertex s. If a adjacent has 
		// not been visited, then mark it visited 
		// and enqueue it 
		for (i = adj[s].begin(); i != adj[s].end(); ++i) 
		{ 
			// If this adjacent node is the destination 
			// node, then return true 
			if (*i == d) 
				return true; 

			// Else, continue to do BFS 
			if (!visited[*i]) 
			{ 
				visited[*i] = true; 
				queue.push_back(*i); 
			} 
		} 
	} 

	// If BFS is complete without visiting d 
	return false; 
} 

bool isSafe(int i, int j, int M[][N]) 
{ 
	if ((i < 0 || i >= N) || 
		(j < 0 || j >= N ) || M[i][j] == 0) 
		return false; 
	return true; 
} 

// Returns true if there is a path from a source (a 
// cell with value 1) to a destination (a cell with 
// value 2) 
bool findPath(int M[][N]) 
{ 
	int s , d ; // source and destination 
	int V = N*N+2; 
	Graph g(V); 

	// create graph with n*n node 
	// each cell consider as node 
	int k = 1 ; // Number of current vertex 
	for (int i =0 ; i < N ; i++) 
	{ 
		for (int j = 0 ; j < N; j++) 
		{ 
			if (M[i][j] != 0) 
			{ 
				// connect all 4 adjacent cell to 
				// current cell 
				if ( isSafe ( i , j+1 , M ) ) 
					g.addEdge ( k , k+1 ); 
				if ( isSafe ( i , j-1 , M ) ) 
					g.addEdge ( k , k-1 ); 
				if (j< N-1 && isSafe ( i+1 , j , M ) ) 
					g.addEdge ( k , k+N ); 
				if ( i > 0 && isSafe ( i-1 , j , M ) ) 
					g.addEdge ( k , k-N ); 
			} 

			// source index 
			if( M[i][j] == 1 ) 
				s = k ; 

			// destination index 
			if (M[i][j] == 2) 
				d = k; 
			k++; 
		} 
	} 

	// find path Using BFS 
	return g.BFS (s, d) ; 
} 

int main() 
{ 
	int M[N][N] = {{ 0 , 3 , 0 , 1 }, 
		{ 3 , 0 , 3 , 3 }, 
		{ 2 , 3 , 3 , 3 }, 
		{ 0 , 3 , 3 , 3 } 
	}; 

	(findPath(M) == true) ? 
	cout << "Yes" : cout << "No" <<endl ; 

	return 0; 
} 



// Infix to Postfix

#include <iostream>
#include <stack>
#include <map>
using namespace std;

void postfix(string str)
{
    map<char,int> mp;
    mp['(']=0;
    mp['-']=2;
    mp['+']=2;
    mp['/']=3;
    mp['*']=3;
    mp['^']=5;
    stack<char> st;
    int i=0;
    while(str[i])
    {
        if(isalpha(str[i]))
        {
            cout<<str[i];
        }
        else
        if(str[i]=='(')
        {
            st.push('(');
        }
        else
        if(str[i]==')')
        {
            while(!st.empty())
            {
                char ch=st.top();
                st.pop();
                if(ch=='(')
                break;
                else
                cout<<ch;
            }
        }
        else
        if(st.empty() || mp[st.top()]<mp[str[i]])
        {
            st.push(str[i]);
        }
        else
        {
            while(!st.empty() && mp[str[i]]<=mp[st.top()])
            {
                char ch=st.top();
                st.pop();
                cout<<ch;
            }
            st.push(str[i]);
        }
        i++;
    }
    while(!st.empty())
    {
        char ch=st.top();
        st.pop();
        cout<<ch;
    }
    cout<<endl;
}

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    string s;
	    cin>>s;
	    postfix(s);
	}
	return 0;
}



// Excel Sheet (Number to String)

#include <iostream>
#include <string.h>
using namespace std;

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    string s = "";
	    while(n)
	    {
	        if(n%26 == 0)  
	        {
	            s = "Z" + s;
	            n--;
	        }
	        else
	        {
	            s = char(n % 26 + 'A' - 1) + s;
	        }
	        n = n/26;
	    }
	    cout<<s<<endl;
	}
	return 0;
}



// Excel Sheet (String to Number)

#include <iostream>
using namespace std;

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    string s;
	    cin>>s;
	    int res = 0;
	    for(int i=0; i<s.size(); i++)
	    {
	        res = res*26 + (s[i] - 'A') + 1;
	    }
	    cout<<res<<endl;
	}
	return 0;
}



// Rotate by 90 degree

#include <iostream>
using namespace std;

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int a[n][n], b[n][n];
	    for(int i=0; i<n; i++)
	    {
	        for(int j=0; j<n; j++)
	        {
	            cin>>a[i][j];
	        }
	    }
	    int p = n-1, q=0;
	    for(int i=0 ; i<n; i++)
	    {
	        p=n-1;
	        for(int j=0; j<n; j++)
	        {
	            b[p][i] = a[i][j];
	            p--;
	        }
	    }
	    for(int i=0; i<n; i++)
	    {
	        for(int j=0; j<n; j++)
	        {
	            cout<<b[i][j]<<" ";
	        }
	    }
	    cout<<endl;
	}
	return 0;
}










// Unit Area of largest region of 1's

#include<bits/stdc++.h>
using namespace std;
#define SIZE 100

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        cin>>n>>m;
        
        int g[SIZE][SIZE];
        bool vis[SIZE][SIZE];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                cin>>g[i][j];
        }
        
        memset(vis, 0, sizeof(vis));
        
        cout << findAreaUtil(n, m, g, vis) << endl;
      
    }
      
	return 0;
}

int max1(int a, int b)  {  return (a>b) ? a : b;  }

int max(int a, int b, int c, int d, int e, int f, int g, int h)
{
    return max1(max1(max1(a, b), max1(c, d)), max1(max1(e, f), max1(g, h)));
}

int dfs(int n, int m, int i, int j, int g[SIZE][SIZE], bool vis[SIZE][SIZE])
{
    if(i<0 || j<0 || i==n || j==m || !g[i][j] || vis[i][j])  return 0;
    vis[i][j] = true;
    return 1 + dfs(n, m, i-1, j-1, g, vis) + dfs(n, m, i-1, j, g, vis) + 
               dfs(n, m, i-1, j+1, g, vis) + dfs(n, m, i, j-1, g, vis) + 
               dfs(n, m, i, j+1, g, vis) + dfs(n, m, i+1, j-1, g, vis) + 
               dfs(n, m, i+1, j, g, vis) + dfs(n, m, i+1, j+1, g, vis);
}

int findAreaUtil(int n, int m, int g[SIZE][SIZE], bool vis[SIZE][SIZE])
{
    int s=0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(g[i][j] && !vis[i][j])
            {
                int x = dfs(n, m, i, j, g, vis);
                if(x > s)  s = x;
            }
        }
    }
    return s;
}



// Top View of Binary Tree

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
void topView(struct Node *root);
/* Driver program to test size function*/
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



// Maximum Sum Rectangle

#include<bits/stdc++.h>
using namespace std;
int kadane(int arr[],int n)
{
    int max_ending_here=0;
    int max_so_far=0;
    int i,j,k,count=0,min=INT_MAX;
    for(i=0; i<n; i++)
    {   
        if(arr[i]<0)
            count++;
        if(arr[i]<min)
            min=arr[i];
        
        max_ending_here += arr[i];
        
        if(max_ending_here<0)
            max_ending_here=0;
        if(max_so_far<max_ending_here)
            max_so_far=max_ending_here;
    }
    if(count==n)
        return min;
    else
        return max_so_far;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int rows,columns,ans=INT_MIN;
        int i,j,k,l,r;
        cin>>rows>>columns;
        int mat[rows][columns];
        for(i=0;i<rows;i++)
        {
            for(j=0;j<columns;j++)
                cin>>mat[i][j];
        }
        int arr[rows];
        for(l=0;l<columns;l++)
        {
            memset(arr,0,sizeof(arr));
            for(r=l;r<columns;r++)
            {
                for(i=0; i<rows; i++)
                    arr[i]+=mat[i][r];
                ans=max(ans,kadane(arr,rows));
            }
        }
        cout<<ans<<endl;
    }
}




// Kth largest element in BST

#include<iostream>
using namespace std;
struct Node
{
    int key;
    Node *left, *right;
};
Node *newNode(int item)
{
    Node *temp = new Node;
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}
void kthLargest(Node *root, int k);
Node* insert(Node* node, int key)
{
    if (node == NULL) return newNode(key);
    if (key < node->key)
        node->left  = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    return node;
}
int main()
{
    int t;
	cin>>t;
	while(t--)
	{
		Node *root = NULL;
		int n;
		cin>>n;
		int a;
		cin>>a;
		root = insert(root, a);
		for(int i=0;i<n-1;i++)
		{
			cin>>a;
			insert(root,a);
		}
		int k;
		cin>>k;
		kthLargest(root, k);
	}
    return 0;
}

void inorder(Node *root, int &k)
{
    if(root == NULL || k < 0)  return;
    
    inorder(root->right, k);
    k--;
    
    if(k == 0)
    {
        cout<<root->key<<endl;
        return;
    }
    
    inorder(root->left, k);
}

void kthLargest(Node *root, int k)
{
    inorder(root, k);
}



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



// Stock Span Problem

#include <iostream>
using namespace std;

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int a[n+1];
	    a[0] = 801;
	    for(int i=1; i<=n; i++)  cin>>a[i];
	    for(int i=1; i<=n; i++)
	    {
	        for(int j=i-1; j>=0; j--)
	        {
	            if(a[i] < a[j])
	            {
	                cout<<i-j<<" ";
	                break;
	            }
	        }
	    }
	    cout<<endl;
	}
	return 0;
}



// Exit Point in a Matrix

#include <iostream>
using namespace std;

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    int m, n;
	    cin>>m>>n;
	    int a[m][n];
	    for(int i=0; i<m; i++)
	    {
	        for(int j=0; j<n; j++)
	            cin>>a[i][j];
	    }
	    int i=0, j=0, x=1;
	    while(i>=0 && j>=0 && i<m && j<n)
	    {
	        if(x == 1)
	        {
	            if(a[i][j] == 0)
	            {
	                j++;
	            }
	            else
	            {
	                x = 2;
	                a[i][j] = 0;
	            }
	        }
	        else if(x == 2)
	        {
	            if(a[i][j] == 0)
	            {
	                i++;
	            }
	            else
	            {
	                x = 3;
	                a[i][j] = 0;
	            }
	        }
	        else if(x == 3)
	        {
	            if(a[i][j] == 0)
	            {
	                j--;
	            }
	            else
	            {
	                x = 4;
	                a[i][j] = 0;
	            }
	        }
	        else if(x == 4)
	        {
	            if(a[i][j] == 0)
	            {
	                i--;
	            }
	            else
	            {
	                x = 1;
	                a[i][j] = 0;
	            }
	        }
	    }
	    if(i < 0)  i++;
	    else if(i >= m)  i--;
	    else if(j < 0)  j++;
	    else if(j >= n)  j--;
	    cout<<i<<" "<<j<<endl;
	}
	return 0;
}



// Leaders in an array

#include <iostream>
using namespace std;

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int a[n], b[n];
	    for(int i=0; i<n; i++)  cin>>a[i];
	    b[n-1] = a[n-1];
	    for(int i=n-2; i>=0; i--)
	    {
	        if(a[i] >= b[i+1])
	        {
	            b[i] = a[i];
	        }
	        else
	        {
	            b[i] = b[i+1];
	        }
	    }
	    for(int i=0; i<n-1; i++)
	    {
	        if(b[i] == a[i])  cout<<a[i]<<" ";
	    }
	    cout<<b[n-1]<<endl;
	}
	return 0;
}



// Travelling Salesman Problem

#include<bits/stdc++.h>
using namespace std;

int tsp(int mask, int pos, int dist[12][12], int n)
{   int visited_all = (1<<n)-1;
    if(mask == visited_all)  return dist[pos][0];
    
    int ans=INT_MAX;
    for(int city=0; city<n; city++)
    {
        if((mask&(1<<city))==0)
        {
            int newans = dist[pos][city]+tsp(mask|(1<<city),city,dist,n);
            ans = min(ans, newans);
        }
    }
    return ans;
}
int main()
 {
	int t;
	cin>>t;
	while(t--)
	{  
	    int n,i,j,x;
	    cin>>n;
	    int v[12][12];
	    for(i=0; i<n; i++)
	    {
	        for(j=0; j<n; j++)
	        {
	            cin>>v[i][j];
	        }
	    }
	    cout<<tsp(1,0,v,n)<<endl;
	}
	return 0;
}



// Factorial of Large Numbers

#include <bits/stdc++.h>
using namespace std;

void fact(int n)
{
    string s = "1";
    for(int i=1; i<=n; i++)
    {
        int carry = 0;
        for(int j=0; j<s.size(); j++)
        {
            int x = (s[j] - 48) * i + carry;
            s[j] = (x % 10) + 48;
            carry = x / 10;
        }
        while(carry)  
        {
            int d = carry % 10;
            s = s + char(d + 48);
            carry = carry / 10;
        }
    }
    for(int i=s.size()-1; i>=0; i--)
    {
        cout<<s[i];
    }
}

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    fact(n);
	    cout<<endl;
	}
	return 0;
}



// Is Binary Number Multiple of 3

#include <iostream>
using namespace std;

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    string s;
	    cin>>s;
	    int odd=0, even=0, flag=0;
	    for(int i=0; i<s.size(); i++)
	    {
	        if(flag == 0)
	        {
	            even += (s[i]-48);
	            flag = 1;
	        }
	        else
	        {
	            odd += (s[i]-48);
	            flag = 0;
	        }
	    }
	    if(abs(odd - even)%3 == 0)  cout<<1<<endl;
	    else  cout<<0<<endl;
	}
	return 0;
}



// Nodes at a given distance in Binary tree

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
    if(!root)  return;
    if(k == 0)
    {
        cout<<root->data<<" ";
        return;
    }
    printkdistanceNodeDown(root->left, k-1);
    printkdistanceNodeDown(root->right, k-1);
}

int distance(node *root, node *target, bool &dir)
{
    if(root == NULL)  return INT_MAX;
    if(root == target)  return 0;
    if(distance(root->left, target, dir) != INT_MAX)
    {
        int ans =  1 + distance(root->left, target, dir);
        dir = false;
        return ans;
    }
    if(distance(root->right, target, dir) != INT_MAX)
    {
        int ans = 1 + distance(root->right, target, dir);
        dir =true;
        return ans;
    }
    return INT_MAX;
}

void printkdist(node *root, node *target, int k)
{
    if(root==NULL)
        return;
    bool dir =false;
    int dist = distance(root,target,dir);
    if(dist==INT_MAX)
        return;
    if(dist==0)
    {
        printkdistanceNodeDown(root,k);
        return;
    }
    if(dist<k)
    {
        if(dir==false)
        {
            printkdist(root->left,target,k);
            printkdistanceNodeDown(root->right,(k-dist)-1);
        }
        else
        {
            printkdist(root->right,target,k);
            printkdistanceNodeDown(root->left,(k-dist)-1);
        }
    }
    else if(dist==k)
    {
        if(dir==false)
        {
            printkdist(root->left,target,k);
            cout<<root->data<<" ";
        }
        else
        {
            printkdist(root->right,target,k);
            cout<<root->data<<" ";
        }
    }
    else if(dist > k)
    {
        if(dir==false)  printkdist(root->left,target,k);
        else  printkdist(root->right,target,k);
    }
}

int printkdistanceNode(node* root, node* target , int k)
{
    printkdist(root,target,k);
}



// Shortest Source to Destination Path 

// Time Limit Exceeded

#include <iostream>
#include <queue>
using namespace std;

bool safe(int x, int y, int m, int n)
{
    return (x>=0 && y>=0 && x<m && y<n);
}

int path(int a[20][20], bool vis[20][20], int m, int n, int fx, int fy)
{
    if(a[0][0] == 0 || a[fx][fy] == 0)  return -1;
    queue<int> qx, qy;
    int dist = 0;
    qx.push(0);
    qy.push(0);
    qx.push(-1);
    qy.push(-1);
    while(!qx.empty() && !qy.empty())
    {
        int x = qx.front(), y = qy.front();
        qx.pop();
        qy.pop();
        if(x == fx && y == fy)  return dist;
        else if(x == -1 && y == -1)  
        {
            dist++;
            qx.push(-1);
            qy.push(-1);
        }
        else
        {
            int flag = 0;
            vis[x][y] = true;
            if(safe(x+1, y, m, n) && a[x+1][y])
            {
                if(vis[x+1][y] == false)
                {
                    vis[x+1][y] = true;
                    qx.push(x+1);
                    qy.push(y);
                }
                flag = 1;
            }
            if(safe(x-1, y, m, n) && a[x-1][y])
            {
                if(vis[x-1][y] == false)
                {
                    vis[x-1][y] = true;
                    qx.push(x-1);
                    qy.push(y);
                }
                flag = 1;
            }
            if(safe(x, y+1, m, n) && a[x][y+1])
            {
                if(vis[x][y+1] == false)
                {
                    vis[x][y+1] = true;
                    qx.push(x);
                    qy.push(y+1);
                }
                flag = 1;
            }
            if(safe(x, y-1, m, n) && a[x][y-1])
            {
                if(vis[x][y-1] == false)
                {
                    vis[x][y-1] = true;
                    qx.push(x);
                    qy.push(y-1);
                }
                flag = 1;
            }
            
            if(flag == 0)  return -1;
        }
    }
    return -1;
}

int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
        int m, n, fx, fy;
        cin>>m>>n;
        int a[20][20];
        bool vis[20][20];
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                cin>>a[i][j];
                vis[i][j] = false;
            }
        }
        cin>>fx>>fy;
        cout<<path(a, vis, m, n, fx, fy)<<endl;
    }
	return 0;
}


// Efficient

#include <bits/stdc++.h> 
using namespace std; 

struct Point 
{ 
	int x; 
	int y; 
}; 

struct queueNode 
{ 
	Point pt; 
	int dist; 
}; 

bool isValid(int row, int col, int m, int n) 
{ 
	return (row >= 0) && (row < m) && (col >= 0) && (col < n); 
} 

int rowNum[] = {-1, 0, 0, 1}; 
int colNum[] = {0, -1, 1, 0}; 
 
int BFS(int mat[20][20], Point src, Point dest, int m, int n) 
{ 
	if (!mat[src.x][src.y] || !mat[dest.x][dest.y]) 
		return -1; 

	bool visited[m][n]; 
	memset(visited, false, sizeof(visited)); 
	
	visited[src.x][src.y] = true; 

	queue<queueNode> q; 
	
	queueNode s = {src, 0}; 
	q.push(s); 

	while (!q.empty()) 
	{ 
		queueNode curr = q.front(); 
		Point pt = curr.pt; 

		if (pt.x == dest.x && pt.y == dest.y) 
			return curr.dist; 

		q.pop(); 

		for (int i = 0; i < 4; i++) 
		{ 
			int row = pt.x + rowNum[i]; 
			int col = pt.y + colNum[i]; 
			
			if (isValid(row, col, m, n) && mat[row][col] && !visited[row][col]) 
			{ 
				visited[row][col] = true; 
				queueNode Adjcell = { {row, col}, curr.dist + 1 }; 
				q.push(Adjcell); 
			} 
		} 
	} 
	return -1; 
} 

int main() 
{ 
	int t;
    cin>>t;
    while(t--)
    {
        int m, n, fx, fy;
        cin>>m>>n;
        int a[20][20];
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                cin>>a[i][j];
            }
        }
        cin>>fx>>fy;
        Point src = {0, 0};
        Point dest = {fx, fy};
        cout<<BFS(a, src, dest, m, n)<<endl;
    }
	return 0;
} 



// Nth Catalan Number


// Doesn't work for large numbers -- C++

#include <iostream>
using namespace std;

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    unsigned long long int a[n+1];
	    a[0] = 1;
	    for(int i=1; i<=n; i++)
	    {
	        unsigned long long int res = 0;
	        for(int j=1; j<=i; j++)
	        {
	            res += a[j-1]*a[i-j];
	        }
	        a[i] = res;
	    }
	    cout<<a[n]<<endl;
	}
	return 0;
}


// Works even for large numbers -- Python

t = int(input())

for _ in range(t):
    n = int(input())
    a = []
    a.append(1)
    for i in range(1, n+1):
        res = 0;
        for j in range(1, i+1):
            res = res + a[j-1]*a[i-j]
        a.append(res)
    print(a[n])



// Bell Numbers -- number of ways of partitioning a set with n numbers

#include <iostream>
using namespace std;

int bell(int n)
{
    int a[n+1][n+1];
    a[0][0] = 1;
    for(int i=1; i<=n; i++)
    {
        a[i][0] = a[i-1][i-1];
        for(int j=1; j<=i; j++)
        {
            a[i][j] = (a[i-1][j-1] + a[i][j-1]) % 1000000007;
        }
    }
    return a[n][0];
}

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    cout<<bell(n)<<endl;
	}
	return 0;
}




// nCr

#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007

int min(int a, int b)  {  return (a<b) ? a : b;  }

long long int fact(int n, int r)
{
    long long int a[n+1][r+1];
    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<=min(r, i); j++)
        {
            if(j == 0 || j == i)  a[i][j] = 1;
            else  a[i][j] = (a[i-1][j-1]%mod + a[i-1][j]%mod)%mod;
        }
    }
    return a[n][r];
}

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n, r;
	    cin>>n>>r;
	    cout<<fact(n, r)<<endl;
	}
	return 0;
}




// Ways To Tile A Floor

#include <iostream>
using namespace std;

long long int tile(int n)
{
    long long int a[n];
    a[0] = 1;
    a[1] = 2;
    for(int i=2; i<n; i++)
    {
        a[i] = a[i-1] + a[i-2];
    }
    return a[n-1];
}

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    cout<<tile(n)<<endl;
	}
	return 0;
}


 
// Friends Pairing Problem 

 #include <iostream>
using namespace std;

long long int friends(long long int n)
{
    long long int a[n];
    a[0] = 1;
    a[1] = 2;
    for(long long int i=2; i<n; i++)
    {
        a[i] = (a[i-1] + (i)*a[i-2]) % 1000000007;
    }
    return a[n-1];
}

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    long long int n;
	    cin>>n;
	    cout<<friends(n)<<endl;
	}
	return 0;
}



// Longest Repeating Subsequence

#include <iostream>
using namespace std;

int max(int a, int b)  {  return (a>b) ? a : b;  }

int lrs(string s, int n)
{
    int a[n+1][n+1];
    for(int i=0; i<=n; i++)
    {
        a[i][0] = 0;
        a[0][i] = 0;
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(s[i-1] == s[j-1] && i != j)  a[i][j] = 1 + a[i-1][j-1];
            else  a[i][j] = max(a[i-1][j], a[i][j-1]);
        }
    }
    return a[n][n];
}

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    string s;
	    cin>>n>>s;
	    cout<<lrs(s, n)<<endl;
	}
	return 0;
}



// LCS of three strings

#include <iostream>
using namespace std;

int max(int a, int b, int c)  
{  
    if(a>=b && a>=c)  return a;
    else if(b>=a && b>=c)  return b;
    else  return c;
    
}

int lcs3(string s1, string s2, string s3)
{
    int a[s1.length()+1][s2.length()+1][s3.length()+1];
    
    for(int i=0; i<=s1.length(); i++)
    {
        for(int j=0; j<=s2.length(); j++)
            a[i][j][0] = 0;
    }
    for(int i=0; i<=s2.length(); i++)
    {
        for(int j=0; j<=s3.length(); j++)
            a[0][i][j] = 0;
    }
    for(int i=0; i<=s3.length(); i++)
    {
        for(int j=0; j<=s1.length(); j++)
            a[j][0][i] = 0;
    }
    
    for(int i=1; i<=s1.length(); i++)
    {
        for(int j=1; j<=s2.length(); j++)
        {
            for(int k=1; k<=s3.length(); k++)
            {
                if(s1[i-1] == s2[j-1] && s2[j-1] == s3[k-1])  
                    a[i][j][k] = 1 + a[i-1][j-1][k-1];
                else  
                    a[i][j][k] = max(a[i-1][j][k], a[i][j-1][k], a[i][j][k-1]);
            }
        }
    }
    return a[s1.size()][s2.size()][s3.size()];
}

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n1, n2, n3;
	    string s1, s2, s3;
	    cin>>n1>>n2>>n3>>s1>>s2>>s3;
	    cout<<lcs3(s1, s2, s3)<<endl;
	}
	return 0;
}



// Dice throw

#include<bits/stdc++.h>
using namespace std;
# define mod 1000000007
long long int dp[55][55];
long long int rec (long long int face, long long int throws, long long int sum)
{
    if(sum == 0 && throws == 0)  return 1;
    if(sum < 0 || throws == 0)  return 0;
    if(dp[throws][sum] != -1)  return dp[throws][sum];
    
    long long int ans=0;
    for(long long int i=1; i<=face; i++)
        ans += rec(face, throws-1, sum-i);
    
    return dp[throws][sum] = ans;
}


int main()
 {
	long long int t;
	cin>>t;
	while(t--)
	{
	   long long int faces, throws, sum;
	   cin>>faces>>throws>>sum;
	   memset(dp, -1, sizeof dp);
	   cout<<rec(faces, throws, sum)<<endl;
	}
	return 0;
}



// Job Sequencing Problem

#include <iostream>
using namespace std;

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int id[n], deadline[n], profit[n];
	    for(int i=0; i<n; i++)
	    {
	        cin>>id[i]>>deadline[i]>>profit[i];
	    }
	    for(int i=0; i<n-1; i++)
	    {
	        for(int j=0; j<n-i-1; j++)
	        {
	            if(profit[j]<profit[j+1])
	            {
	                int t = profit[j+1];
	                profit[j+1] = profit[j];
	                profit[j] = t;
	                
	                t = deadline[j+1];
	                deadline[j+1] = deadline[j];
	                deadline[j] = t;
	                
	                t = id[j+1];
	                id[j+1] = id[j];
	                id[j] = t;
	            }
	        }
	    }
	    
	    int a[n] = { 0 }, c=0, p=0;
	    for(int i=0; i<n; i++)
	    {
	        if(a[deadline[i]-1] == 0)
	        {
	            p += profit[i];
	            c++;
	            a[deadline[i]-1] = 1;
	        }
	        else
	        {
	            for(int j=deadline[i]-1; j>=0; j--)
	            {
	                if(a[j] == 0)
	                {
	                    p += profit[i];
        	            c++;
        	            a[j] = 1;
        	            break;
	                }
	            }
	        }
	    }
	    cout<<c<<" "<<p<<endl;
	}
	return 0;
}



// Sum of dependencies in a graph

#include <iostream>
#include <vector>
using namespace std;

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n, e;
	    cin>>n>>e;
	    vector<int> a[n];
	    for(int i=0; i<e; i++)
	    {
	        int u, v;
	        cin>>u>>v;
	        a[u].push_back(v);
	    }
	    int sum = 0;
	    for(int i=0; i<n; i++)
	    {
	        sum += a[i].size();
	    }
	    cout<<sum<<endl;
	}
	return 0;
}




// X Total Shapes

#include <iostream>
using namespace std;

void shapes(char a[50][50], bool vis[50][50], int m, int n, int i, int j)
{
    if(i<0 || j<0 || i==m || j==n || vis[i][j] || a[i][j]=='O')  return;
    vis[i][j] = true;
    shapes(a, vis, m, n, i+1, j);
    shapes(a, vis, m, n, i-1, j);
    shapes(a, vis, m, n, i, j+1);
    shapes(a, vis, m, n, i, j-1);
}

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    int m, n;
	    cin>>m>>n;
	    char a[50][50];
	    bool vis[50][50];
	    for(int i=0; i<m; i++)
	    {
	        string s;
	        cin>>s;
	        for(int j=0; j<n; j++)
	        {
	            a[i][j] = s[j];
	            vis[i][j] = false;
	        }
	    }
	    int c=0;
	    for(int i=0; i<m; i++)
	    {
	        for(int j=0; j<n; j++)
	        {
	            if(!vis[i][j] && a[i][j] == 'X')
	            {
	                shapes(a, vis, m, n, i, j);
	                c++;
	            }
	        }
	    }
	    cout<<c<<endl;
	}
	return 0;
}




// Longest Increasing Subsequence

#include <bits/stdc++.h>
using namespace std;

int lis(int a[], int n)
{
    int v[n];
    for(int i=0; i<n; i++)  v[i] = 1;
    for(int i=1; i<n; i++)
    {
        for(int j=0; j<i; j++)
        {
            if(a[j] < a[i])
            {
                v[i] = max(v[i], 1+v[j]);
            }
        }
    }
    int m=INT_MIN;
    for(int i=0; i<n; i++)
    {
        m = max(m, v[i]);
    }
    return m;
}

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0; i<n; i++)
	    {
	        cin>>a[i];
	    }
	    cout<<lis(a, n)<<endl;
	}
	return 0;
}



// Count Pairs whose sum is equal to X

#include <bits/stdc++.h>
using namespace std;
struct Node
{
int data;
struct Node* next;
};
void append(struct Node** headRef, int newData)
{
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
	struct Node *last = *headRef;
	new_node->data = newData;
	new_node->next = NULL;
	if (*headRef == NULL)
	{
	    *headRef = new_node;
	    return;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = new_node;
	return;
}
void printList(struct Node* head){
    while(head){
        cout<<head->data<<' ';
        head = head->next;
    }
}
int countPairs(struct Node* head1, struct Node* head2,	int x);

int main()
{
    int T;
    cin>>T;
    while(T--){
        struct Node* head1 = NULL;
	    struct Node* head2 = NULL;
	    int n1, n2, tmp, x;
	    cin>>n1;
	    while(n1--){
	        cin>>tmp;
	        append(&head1, tmp);
	    }
	    cin>>n2;
	    while(n2--){
	        cin>>tmp;
	        append(&head2, tmp);
	    }
	    cin>>x;
	    cout<<countPairs(head1, head2, x)<<'
';
    }
	return 0;
}

int countPairs(struct Node* head1, struct Node* head2,	int x)
{
    unordered_set<int> s;
    Node *ptr = head1;
    while(ptr != NULL)
    {
        s.insert(x - ptr->data);
        ptr = ptr->next;
    }
    ptr = head2;
    int c = 0;
    while(ptr != NULL)
    {
        if(s.find(ptr->data) != s.end())  c++;
        ptr = ptr->next;
    }
    return c;
}



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



// Count ways to N'th Stair(Order does not matter)

#include<bits/stdc++.h>
using namespace std;
long long mod =1000000007;
long long countWays(int);
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int m;
        cin>>m;
        cout<<countWays(m)<<endl; 
    }
    return 0;
}

long long countWays(int m)
{
    // int a[m], x=1;
    // a[0] = 1;
    // for(int i=1; i<m; i++)
    // {
    //     if(i%2 == 1)  a[i] = ++x;
    //     else  a[i] = x;
    // }
    // return a[m-1];
    
    return m/2 + 1;
}



// Full Binary Tree

#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int key;
    struct Node *left, *right;
};
struct Node *newNode(char k)
{
    struct Node *node = (struct Node*)malloc(sizeof(struct Node));
    node->key = k;
    node->right = node->left = NULL;
    return node;
}
void insert(Node *root,int a1,int a2,char lr){
	if(root==NULL)
		return;
	if(root->key==a1){
		switch(lr){
			case 'L':root->left=newNode(a2);
			break;
			case 'R':root->right=newNode(a2);
			break;
		}
	}
	else{
		insert(root->left,a1,a2,lr);
		insert(root->right,a1,a2,lr);
	}
}
bool isFullTree (struct Node* root);
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		struct Node* root = NULL;
		while(n-->0){
				int a1,a2;
				char lr;
				cin>>a1>>a2>>lr;
				if(root==NULL){
					root=newNode(a1);
					switch(lr){
						case 'L':root->left=newNode(a2);
						break;
						case 'R':root->right=newNode(a2);
						break;
					}
				}
				else{
					insert(root,a1,a2,lr);
				}
			}
		if (isFullTree(root))
			cout<<"1
";
		else
			cout<<"0
";
	}
    return 0;
}

bool isFullTree (struct Node* root)
{
    if(!root->left && !root->right)  return true;
    
    if((root->left && !root->right) || (!root->left && root->right))
        return false;
    
    return (isFullTree(root->left) & isFullTree(root->right));
}



// Check if subtree

#include <cstring>
#include <iostream>
#include <map>
using namespace std;
#define MAX 1000

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
bool isSubtree(Node *T, Node *S);
void storeInorder(Node *, char[], int &);
void storePreOrder(Node *, char[], int &);

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        struct Node *child = NULL;
        map<int, Node *> m;
        int n;
        scanf(" %d
", &n);
        struct Node *t2 = NULL;
        while (n--) {
            Node *parent;
            char lr;
            int n1, n2;
            scanf("%d %d %c", &n1, &n2, &lr);
            if (m.find(n1) == m.end()) {
                parent = new Node(n1);
                m[n1] = parent;
                if (t2 == NULL) t2 = parent;
            } else
                parent = m[n1];
            child = new Node(n2);
            if (lr == 'L')
                parent->left = child;
            else
                parent->right = child;
            m[n2] = child;
        }
        struct Node *child1;
        map<int, Node *> m1;
        int nodes;
        scanf("%d
", &nodes);
        struct Node *t1 = NULL;
        while (nodes--) {
            Node *parent1;
            char lr1;
            int n3, n4;
            scanf("%d %d %c", &n3, &n4, &lr1);
            if (m1.find(n3) == m1.end()) {
                parent1 = new Node(n3);
                m1[n3] = parent1;
                if (t1 == NULL) t1 = parent1;
            } else
                parent1 = m1[n3];
            child = new Node(n4);
            if (lr1 == 'L')
                parent1->left = child;
            else
                parent1->right = child;
            m1[n4] = child;
        }
        cout << isSubtree(t1, t2);
        cout << endl;
    }
}
}

bool match(Node *n1, Node *n2)
{
    if(n1 == NULL && n2 == NULL)  return true;
    if((n1 == NULL || n2 == NULL) || (n1->data != n2->data))  
        return false;
    return (match(n1->left, n2->left) & match(n1->right, n2->right));
}

bool isSubtree(Node* T1, Node* T2) 
{
    if(T1 == NULL)  return false;
    if(T1->data == T2->data)
    {
        bool x = match(T1, T2);
        if(x == true)  return true;
    }
    bool x = isSubtree(T1->left, T2);
    bool y = isSubtree(T1->right, T2);
    return (x|y);
}



// Print Diagonally

#include <iostream>
using namespace std;

void diagonal(int a[20][20], int n)
{
    int p=0, q=0, flag=0;
    while(q < n)
    {
        int i=p, j=q;
        while(j >= 0)
        {
            cout<<a[i][j]<<" ";
            i++;
            j--;
        }
        q++;
    }
    q--;
    p++;
    while(p < n)
    {
        int i=p, j=q;
        while(i < n)
        {
            cout<<a[i][j]<<" ";
            i++;
            j--;
        }
        p++;
    }
}

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int a[20][20];
	    for(int i=0; i<n; i++)
	        for(int j=0; j<n; j++)
	            cin>>a[i][j];
	    diagonal(a, n);
	    cout<<endl;
	}
	return 0;
}



// Reach a given score

#include <iostream>
using namespace std;

int score(int n)
{
    int a[3] = {3, 5, 10};
    int m[4][n+1];
    for(int i=0; i<=n; i++)  m[0][i] = 0;
    for(int i=1; i<4; i++)  m[i][0] = 1;
    for(int i=1; i<4; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(j >= a[i-1])  m[i][j] = m[i-1][j] + m[i][j-a[i-1]];
            else  m[i][j] = m[i-1][j];
        }
    }
    return m[3][n];
}

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    cout<<score(n)<<endl;
	}
	return 0;
}



// Merge Sort for Linked List

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("
");
}
void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        a = mergeSort(a);
        printList(a);
    }
    return 0;
}  

int length(Node *n)
{
    int l = 0;
    while(n)
    {
        l++;
        n = n->next;
    }
    return l;
}

Node* merge(Node *p1, Node *p2)
{
    if(p1 == NULL)  return p2;
    if(p2 == NULL)  return p1;
    Node *res=NULL;
    if(p1->data < p2->data)
    {
        res = p1;
        res->next = merge(p1->next, p2);
    }
    else
    {
        res = p2;
        res->next = merge(p1, p2->next);
    }
    return res;
}

Node* mergeSort(Node* head) 
{
    if(head->next == NULL)  return head;
    int n = length(head), k;
    if(n%2 == 0)  k = n/2;
    else  k = n/2 + 1;
    Node *p1=head, *p2=head, *temp;
    while(k--)
    {
        temp = p2;
        p2 = p2->next;
    }
    temp->next = NULL;
    p1 = mergeSort(p1);
    p2 = mergeSort(p2);
    return merge(p1, p2);
}



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



// Palindromic Array

#include <iostream>
using namespace std;

int palindrome(int a[], int n)
{
    int i=0, j=n-1, m=0;
    while(i < j)
    {
        if(a[i] == a[j])
        {
            i++;
            j--;
        }
        else if(a[i] < a[j])
        {
            a[i+1] = a[i+1] + a[i];
            i++;
            m++;
        }
        else
        {
            a[j-1] = a[j-1] + a[j];
            j--;
            m++;
        }
    }
    return m;
}

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0; i<n; i++)  cin>>a[i];
	    cout<<palindrome(a, n)<<endl;
	}
	return 0;
}



// Kth Smallest Element

#include <iostream>
#include <climits>
using namespace std;

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n, k, min=INT_MAX, max=INT_MIN;
	    cin>>n;
	    int a[n];
	    for(int i=0; i<n; i++)
	    {
	        cin>>a[i];
	        if(a[i] < min)  min = a[i];
	        if(a[i] > max)  max = a[i];
	    }
	    cin>>k;
	    int x[max-min+1] = { 0 };
	    for(int i=0; i<n; i++)
	    {
	        x[a[i]-min]++;
	    }
	    for(int i=0; i<max-min+1; i++)
	    {
	        if(x[i])  k--;
	        if(k == 0)  
	        {
	            cout<<(min+i)<<endl;
	            break;
	        }
	    }
	}
	return 0;
}



// Leaves to DLL

#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	Node *left,*right;
};
struct Node* newNode(int data)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}
void insert(Node *root, int a1,int a2, char lr){
	if(root==NULL)
		return;
	if(root->data==a1){
		switch(lr){
			case 'L':root->left=newNode(a2);
			break;
			case 'R':root->right=newNode(a2);
			break;
		}
	}
	else{
		insert(root->left,a1,a2,lr);
		insert(root->right,a1,a2,lr);
	}
}

Node *convertToDLL(Node *root,Node **head_ref);
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		Node *root=NULL;
		while(n--){
			int a1,a2;
			char lr;
			cin>>a1>>a2;
			scanf(" %c",&lr);
			if(root==NULL){
				root=newNode(a1);
				switch(lr){
					case 'L':root->left=newNode(a2);
					break;
					case 'R':root->right=newNode(a2);
					break;
				}
			}
			else{
				insert(root,a1,a2,lr);
			}
		}
		Node *head=NULL;
		root=convertToDLL(root,&head);
		while(head->right!=NULL){
			cout<<head->data<<" ";
			head=head->right;
		}
		cout<<head->data<<endl;
		while(head!=NULL){
			cout<<head->data<<" ";
			head=head->left;
		}
		cout<<endl;
	}
}

Node *convertToDLL(Node *root,Node **head_ref)
{
    if(root == NULL)  return NULL;
    if(root->left == NULL && root->right == NULL)
    {
        if(*head_ref != NULL)
        {
            (*head_ref)->left = root;
            root->right = *head_ref;
        }
        *head_ref = root;
        return *head_ref;
    }
    convertToDLL(root->right, head_ref);
    convertToDLL(root->left, head_ref);
    return *head_ref;
}



// Count of strings that can be formed using a, b and c under given constraints

#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int t;
    cin>>t;
    
    while(t--)
    {
        long long int n;
        cin>>n;
        long long int b0c0= 1, b0c1= n, b0c2= n*(n-1)/2, b1c0= n, 
                      b1c1= n*(n-1), b1c2= n*(n-1)*(n-2)/2;
        
        cout << b0c0 + b0c1 + b0c2 + b1c0 + b1c1 + b1c2 << endl; 
    }
    return 0;
}



// Rod Cutting

#include <iostream>
using namespace std;

int max(int a, int b)  {  return (a>b) ? a : b;  }

int rod(int a[], int n)
{
    int m[n+1][n+1];
    for(int i=0; i<=n; i++)
    {
        m[i][0] = 0;
        m[0][i] = 0;
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(j >= i)  m[i][j] = max(m[i-1][j], m[i][j-i] + a[i-1]);
            else  m[i][j] = m[i-1][j];
        }
    }
    return m[n][n];
}

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0; i<n; i++)  cin>>a[i];
	    cout<<rod(a, n)<<endl;
	}
	return 0;
}



// Painting the Fence

#include <iostream>
using namespace std;

long long int paint(long long int n, long long int k)
{
    long long int a[n+1] = { 0 };
    a[1] = k;
    long long int s=0, d=k;
    for(int i=2; i<=n; i++)
    {
        s = d;
        d = a[i-1] * (k-1);
        d = d % 1000000007;
        a[i] = (d + s ) % 1000000007; 
    }
    return a[n];
}

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    long long int n, k;
	    cin>>n>>k;
	    cout<<paint(n, k)<<endl;
	}
	return 0;
}



// Maximum Width of Tree

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

int getMaxWidth(Node* root);

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
     scanf("%d",&n);
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
     cout << getMaxWidth(root) << endl;
  }
  return 0;
}

int getMaxWidth(Node* root)
{
    int m=0;
    queue<Node *> q;
    q.push(root);
    while(!q.empty())
    {
        int x = q.size();
        if(x > m)  m = x;
        while(x--)
        {
            Node *t = q.front();
            q.pop();
            if(t->left)  q.push(t->left);
            if(t->right)  q.push(t->right);
        }
    }
    return m;
}



// Delete keys in a Linked list

#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
};
void append(struct Node** head_ref, struct Node **tail_ref,
           int new_data)
{
    struct Node* new_node = new Node;
    new_node->data  = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL)
       *head_ref = new_node;
    else
       (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}

struct Node* deleteAllOccurances(struct Node *head,int );
void printList(Node *head)
{
   while (head != NULL)
   {
      cout << head->data << " ";
      head = head->next;
   }
   cout << "
";
}

int main()
{
  int T,i,n,l;
  for (int i=0; i<2000; i++);
    cin>>T;
    while(T--){
    struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        for(i=1;i<=n;i++)
        {
            cin>>l;
            append(&head, &tail, l);
        }
	int kk;
	cin>>kk;
    head =deleteAllOccurances(head,kk);
    printList(head);
    }
    return 0;
}

Node* deleteAllOccurances(Node *head, int x)
{
    while(head->data == x)
    {
        Node *t = head;
        head = head->next;
        delete t;
    }
    if(head)
    {
        Node *p = head->next, *q = head;
        while(p)
        {
            if(p->data == x)
            {
                q->next = p->next;
                Node *t = p;
                p = p->next;
                delete t;
            }
            else
            {
                q = p;
                p = p->next;
            }
        }
    }
    return head;
}



// Longest Palindrome in a String

#include <iostream>
using namespace std;

string palindrome(string s)
{
    int n=s.length(), m=1, start=0;
    string p;
    bool a[n][n] = { false };
    for(int i=0; i<n; i++)  a[i][i] = true;
    for(int i=0; i<n-1; i++)
    {
        if(s[i] == s[i+1])
        {
            m=2;
            if(start == 0)  start = i;
            a[i][i+1] = true;
        }
    }
    for(int i=2; i<n; i++)
    {
        for(int j=0; j<n-i; j++)
        {
            if(s[j] == s[j+i] && a[j+1][j+i-1])
            {
                if(m < i+1)
                {
                    m=i+1;
                    start = j;
                }
                a[j][j+i] = true;
            }
        }
    }
    string result = "";
    for(int i=start; i<start+m; i++)  result += s[i];
    return result;
}

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    string s;
	    cin>>s;
	    cout<<palindrome(s)<<endl;
	}
	return 0;
}



// Snake and Ladder Problem

#include <iostream>
#include <queue>
using namespace std;

int main() 
{
	int t;
	cin>>t;
	int a[30];
    bool vis[30];
	while(t--)
	{
	    int n;
	    cin>>n;
	    for(int i=0; i<30; i++)  
	    {
	        a[i] = i;
	        vis[i] = false;
	    }
	    for(int i=0; i<n; i++)
	    {
	        int x, y;
	        cin>>x>>y;
	        a[x-1] = y-1;
	    }
	    queue<int> q1, q2;
	    q1.push(0);
	    q2.push(0);
	    vis[0] = true;
	    while(q1.front() != 29)
	    {
	        int x = q1.front(), y = q2.front();
	        for(int i=1; i<=6; i++)
	        {
	            if(x+i < 30 && !vis[x+i])
	            {
	                q1.push(a[x+i]);
	                q2.push(y+1);
	                vis[x+i] = true;
	                vis[a[x+i]] = true;
	            }
	        }
	        q1.pop();
	        q2.pop();
	    }
	    cout<<q2.front()<<endl;
	}
	return 0;
}




