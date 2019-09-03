// BOTTOM VIEW OF BINARY TREE

void printBottomViewUtil(Node * root, int curr, int hd, map <int, pair <int, int>> & m) 
{ 
    if (root == NULL)  return; 
    if (m.find(hd) == m.end())  
    {
        m[hd] = make_pair(root -> data, curr); 
    }
    else 
    { 
        pair < int, int > p = m[hd]; 
        if (p.second <= curr) 
        { 
            m[hd].second = curr; 
            m[hd].first = root -> data; 
        } 
    } 
    printBottomViewUtil(root -> left, curr + 1, hd - 1, m); 
    printBottomViewUtil(root -> right, curr + 1, hd + 1, m); 
} 

void bottomView(Node *root)
{
    map <int, pair<int, int>> m; 
    printBottomViewUtil(root, 0, 0, m); 
      
    map < int, pair < int, int > > ::iterator it; 
    for (it = m.begin(); it != m.end(); ++it) 
    { 
        pair < int, int > p = it -> second; 
        cout << p.first << " "; 
    } 
}
