// DETECT A LOOP IN A LINKED LIST

#include <bits/stdc++.h>

bool detectLoop(struct Node* h) 
{ 
    unordered_set<Node*> s; 
    while (h != NULL) { 
        if (s.find(h) != s.end()) 
            return true; 
        s.insert(h); 
        h = h->next; 
    }
    return false; 
} 