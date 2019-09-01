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
