// Find Number of Islands

#include <bits/stdc++.h>
using namespace std;

int main() {
    
	int T;
	cin>>T;
	while(T--)
	{
		int N,M;
		cin>>N>>M;
		vector<int> A[N];
		for(int i=0;i<N;i++){
		    vector<int> temp(M);
		    A[i] = temp;
		    for(int j=0;j<M;j++){
		        cin>>A[i][j];
		    }
		}
		cout<<findIslands(A,N,M)<<endl;
	}
	return 0;
}

void fn(vector<int> a[], bool b[50][50], int n, int m, int i, int j)
{
    if(i<0 || j<0 || i>=n || j>=m || a[i][j] == 0 || b[i][j] == true)  return;
    b[i][j] = true;
    fn(a, b, n, m, i-1, j-1);
    fn(a, b, n, m, i-1, j);
    fn(a, b, n, m, i-1, j+1);
    fn(a, b, n, m, i, j-1);
    fn(a, b, n, m, i, j+1);
    fn(a, b, n, m, i+1, j-1);
    fn(a, b, n, m, i+1, j);
    fn(a, b, n, m, i+1, j+1);
}

int findIslands(vector<int> a[], int n, int m)
{
    bool b[50][50] = { false };
    int count = 0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(b[i][j] == false && a[i][j] == 1)
            {
                count++;
                fn(a, b, n, m, i, j);
            }
        }
    }
    return count;
}