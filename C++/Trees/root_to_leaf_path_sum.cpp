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