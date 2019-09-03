// Shortest Source to Destination Path 

// Time Limit Exceeded

#include <iostream>
#include <queue>
using namespace std;

bool safe(int x, int y, int m, int n)
{
    return (x>=0 && y>=0 && x<m && y<n);
}

int path(int a[20][20], bool vis[20][20], int m, int n, int fx, int fy)
{
    if(a[0][0] == 0 || a[fx][fy] == 0)  return -1;
    queue<int> qx, qy;
    int dist = 0;
    qx.push(0);
    qy.push(0);
    qx.push(-1);
    qy.push(-1);
    while(!qx.empty() && !qy.empty())
    {
        int x = qx.front(), y = qy.front();
        qx.pop();
        qy.pop();
        if(x == fx && y == fy)  return dist;
        else if(x == -1 && y == -1)  
        {
            dist++;
            qx.push(-1);
            qy.push(-1);
        }
        else
        {
            int flag = 0;
            vis[x][y] = true;
            if(safe(x+1, y, m, n) && a[x+1][y])
            {
                if(vis[x+1][y] == false)
                {
                    vis[x+1][y] = true;
                    qx.push(x+1);
                    qy.push(y);
                }
                flag = 1;
            }
            if(safe(x-1, y, m, n) && a[x-1][y])
            {
                if(vis[x-1][y] == false)
                {
                    vis[x-1][y] = true;
                    qx.push(x-1);
                    qy.push(y);
                }
                flag = 1;
            }
            if(safe(x, y+1, m, n) && a[x][y+1])
            {
                if(vis[x][y+1] == false)
                {
                    vis[x][y+1] = true;
                    qx.push(x);
                    qy.push(y+1);
                }
                flag = 1;
            }
            if(safe(x, y-1, m, n) && a[x][y-1])
            {
                if(vis[x][y-1] == false)
                {
                    vis[x][y-1] = true;
                    qx.push(x);
                    qy.push(y-1);
                }
                flag = 1;
            }
            
            if(flag == 0)  return -1;
        }
    }
    return -1;
}

int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
        int m, n, fx, fy;
        cin>>m>>n;
        int a[20][20];
        bool vis[20][20];
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                cin>>a[i][j];
                vis[i][j] = false;
            }
        }
        cin>>fx>>fy;
        cout<<path(a, vis, m, n, fx, fy)<<endl;
    }
	return 0;
}


// Efficient

#include <bits/stdc++.h> 
using namespace std; 

struct Point 
{ 
	int x; 
	int y; 
}; 

struct queueNode 
{ 
	Point pt; 
	int dist; 
}; 

bool isValid(int row, int col, int m, int n) 
{ 
	return (row >= 0) && (row < m) && (col >= 0) && (col < n); 
} 

int rowNum[] = {-1, 0, 0, 1}; 
int colNum[] = {0, -1, 1, 0}; 
 
int BFS(int mat[20][20], Point src, Point dest, int m, int n) 
{ 
	if (!mat[src.x][src.y] || !mat[dest.x][dest.y]) 
		return -1; 

	bool visited[m][n]; 
	memset(visited, false, sizeof(visited)); 
	
	visited[src.x][src.y] = true; 

	queue<queueNode> q; 
	
	queueNode s = {src, 0}; 
	q.push(s); 

	while (!q.empty()) 
	{ 
		queueNode curr = q.front(); 
		Point pt = curr.pt; 

		if (pt.x == dest.x && pt.y == dest.y) 
			return curr.dist; 

		q.pop(); 

		for (int i = 0; i < 4; i++) 
		{ 
			int row = pt.x + rowNum[i]; 
			int col = pt.y + colNum[i]; 
			
			if (isValid(row, col, m, n) && mat[row][col] && !visited[row][col]) 
			{ 
				visited[row][col] = true; 
				queueNode Adjcell = { {row, col}, curr.dist + 1 }; 
				q.push(Adjcell); 
			} 
		} 
	} 
	return -1; 
} 

int main() 
{ 
	int t;
    cin>>t;
    while(t--)
    {
        int m, n, fx, fy;
        cin>>m>>n;
        int a[20][20];
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                cin>>a[i][j];
            }
        }
        cin>>fx>>fy;
        Point src = {0, 0};
        Point dest = {fx, fy};
        cout<<BFS(a, src, dest, m, n)<<endl;
    }
	return 0;
}