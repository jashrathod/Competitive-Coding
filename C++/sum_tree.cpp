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