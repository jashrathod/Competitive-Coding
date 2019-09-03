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
