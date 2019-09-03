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
