// Number Formation - (INCOMPLETE)

#include <iostream>
using namespace std;

long long int numform(int x, int y, int z)
{
    long long int m[x+1][y+1][z+1] = { 0 };
    for(int i=0; i<=x; i++)
    {
        for(int j=0; j<=y; j++)
        {
            for(int k=0; k<=z; k++)
            {
                if(k != 0)  m[i][j][k] = m[i][j][k] + 10*m[i][j][k-1] + 6;
                if(j != 0)  m[i][j][k] = m[i][j][k] + 10*m[i][j-1][k] + 5;
                if(i != 0)  m[i][j][k] = m[i][j][k] + 10*m[i-1][j][k] + 4;
            }
        }
    }
    long long int sum=0;
    for(int i=0; i<=x; i++)
    {
        for(int j=0; j<=y; j++)
        {
            for(int k=0; k<=z; k++)
            {
                sum = sum + m[i][j][k];
                // cout<<m[i][j][k]<<" ";
            }
        }
    }
    return sum+15;
}

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    int x, y, z;
	    cin>>x>>y>>z;
	    cout<<numform(x, y, z)<<endl;
	}
	return 0;
}