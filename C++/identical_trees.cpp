// IDENTICAL TREES

bool isIdentical(Node *r1, Node *r2)
{
    if(r1 == NULL && r2 == NULL)  return true;
    if((r1->data != r2->data) || 
       (r1->left == NULL && r2->left != NULL) || 
       (r1->left != NULL && r2->left == NULL) || 
       (r1->right == NULL && r2->right != NULL) || 
       (r1->right != NULL && r2->right == NULL) )
        return false;
    else
    {
        return ( isIdentical(r1->left, r2->left) & 
                 isIdentical(r1->right, r2->right) );
    }
}