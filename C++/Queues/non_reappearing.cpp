// NON REAPPEARING ELEMENT

#include <bits/stdc++.h> 
using namespace std; 
int main() 
{
    int MAX_CHAR = 26; 
    int t, n;
    cin>>t;
    for(int k=0; k<t; k++)
    {
        cin>>n;
        char str[n];
        for(int j=0; j<n; j++)
            cin>>str[j];
        queue<char> q; 
        int charCount[MAX_CHAR] = {0};
        for (int i = 0; i<n; i++) 
        { 
            q.push(str[i]); 
            charCount[str[i] - 'a']++; 
            while (!q.empty()) 
            { 
                if (charCount[q.front() - 'a'] > 1)  q.pop(); 
                else 
                { 
                    cout << q.front() << " "; 
                    break; 
                } 
            }
            if (q.empty())  cout << -1 << " "; 
        } 
        cout << endl; 
    }
    return 0; 
} 
