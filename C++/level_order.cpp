// Level Order Traversal

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
