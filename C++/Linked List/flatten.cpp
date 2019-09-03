// FLATTEN

/*This is a function problem.You only need to complete the function given below*/
/* Node structure  used in the program
struct Node{
	int data;
	struct Node * next;
	struct Node * bottom ;
}; */
/*  Function which returns the  root of the flattened linked list. */
// Node *flatten(Node *root)
// {
//    Node *m=root, *p=root;
    
// }

Node* merge( Node* a, Node* b ) 
{ 
    if (a == NULL)  return b; 
    if (b == NULL)  return a; 
    Node* result; 
    if (a->data < b->data) 
    { 
        result = a; 
        result->down = merge( a->down, b ); 
    } 
    else
    { 
        result = b; 
        result->down = merge( a, b->down ); 
    }   
    return result; 
} 

Node* flatten (Node* root) 
{ 
    if (root == NULL || root->right == NULL) 
        return root; 
    return merge( root, flatten(root->right) ); 
} 
