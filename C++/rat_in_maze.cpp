// Rat in a Maze

#include <bits/stdc++.h>
using namespace std;
#define MAX 100
vector<string> printPath(int m[MAX][MAX], int n);
int main() 
{
	int t;
	cin>>t;
	while(t--)
    {
        int n;
        cin>>n;
        
        int m[100][100];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                cin>>m[i][j];
        }
        vector<string> res = printPath(m,n);
        for(int i=0;i<res.size();i++)
        cout<<res[i]<<" ";
        cout<<endl;
    }
	return 0;
}

void fn(int i, int j, int m[MAX][MAX], int n, string s, vector<string> &r)
{
    if(i < 0 || j < 0 || i >= n || j >= n || m[i][j] == 0 || m[i][j] == 2)  return ;
    else if(i == n-1 && j == n-1)
    {
        r.push_back(s);
        return ;
    }
    else
    {
        m[i][j] = 2;
        fn(i+1, j, m, n, s+'D', r);
        fn(i-1, j, m, n, s+'U', r);
        fn(i, j+1, m, n, s+'R', r);
        fn(i, j-1, m, n, s+'L', r);
        m[i][j]=1;
    }
}

vector<string> printPath(int m[MAX][MAX], int n)
{   
    vector<string> r;
    fn(0,0,m,n,"",r);
    sort(r.begin(), r.end());
    return r;
}