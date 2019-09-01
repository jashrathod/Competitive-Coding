// BOOLEAN MATRIX

#include <bits/stdc++.h> 
using namespace std; 

int main() 
{ 
	int t;
	cin>>t;
    while(t--)
    {
        int R, C;
        cin>>R>>C;
        int mat[R][C];
        for(int i=0; i<R; i++)
        {
            for(int j=0; j<C; j++)
                cin>>mat[i][j];
        } 
        
        bool row[R]; 
    	bool col[C]; 
    	int i, j; 
    	for (i = 0; i < R; i++) 
        	row[i] = 0; 
    
    	for (i = 0; i < C; i++) 
        	col[i] = 0; 
    
        for (i = 0; i < R; i++) 
    	{ 
    		for (j = 0; j < C; j++) 
    		{ 
    			if (mat[i][j] == 1) 
    			{ 
    				row[i] = 1; 
    				col[j] = 1; 
    			} 
    		} 
    	} 
    	for (i = 0; i < R; i++) 
    	{ 
    		for (j = 0; j < C; j++) 
    		{ 
    			if ( row[i] == 1 || col[j] == 1 )  mat[i][j] = 1; 
    		} 
    	} 
    	for (i = 0; i < R; i++) 
    	{ 
    		for (j = 0; j < C; j++) 
    			cout << mat[i][j] << " "; 
    		cout << endl; 
    	} 
    }
	return 0; 
} 
