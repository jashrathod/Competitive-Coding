// CONVERT A TREE TO ITS MIRROR TREE

void mirror(Node* node) 
{
    if(node == NULL)  return;
    else if(node->left != NULL || node->right != NULL)
    {
        Node* temp;
        temp = node->left;
        node->left = node->right;
        node->right = temp;
        mirror(node->left);
        mirror(node->right);
    }
}