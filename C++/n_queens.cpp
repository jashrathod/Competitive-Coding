// N-Queens Problem

#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool safe(int r, int c, int row[])
{
    for(int i=0; i<c; i++)
    {
        if (row[i] == r || (abs(row[i] - r) == abs(i - c)))  
            return false;
    }
    return true;
}

void backtrack(int c, int n, int row[])
{
    if (c > n-1)
    {
        cout << "[";
        for(int i=0; i<n; i++)
            cout << row[i] + 1 << " ";
        cout << "] ";
    }
    for(int r=0; r<n; r++)
    { 
        if (safe(r,c,row))
        {
            row[c] = r;
            backtrack(c+1, n, row);
        }
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int row[n];
        memset(row, 0, sizeof(row));
        if (n == 3 || n == 2)  cout << "-1";
        else  backtrack(0,n,row);
        cout<<endl;
    }
	return 0;
}