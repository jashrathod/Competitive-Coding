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
