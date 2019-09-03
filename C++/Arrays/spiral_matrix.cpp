// Spirally traversing a matrix

#include <iostream>
using namespace std;

void spiral()
{
    int m1, m2;
    cin>>m1>>m2;
    int arr[m1][m2];
    for(int i=0; i<m1; i++)
    {
        for(int j=0; j<m2; j++)
            cin>>arr[i][j];
    }
    int i=0, dir=0, n=m1*m2, k;
    int T=0, B=m1-1, L=0, R=m2-1;
    while(T<=B && L<=R)
    {
        if(dir==0)
        {
            for(k=L ; k<=R ; k++)
                printf("%d ",arr[T][k]);
            T++;
        }
        else if(dir==1)
        {
            for(k=T ; k<=B ; k++)
                printf("%d ",arr[k][R]);
            R--;
        }
        else if(dir==2)
        {
            for(k=R ; k>=L ; k--)
                printf("%d ",arr[B][k]);
            B--;
        }
        else if(dir==3)
        {
            for(k=B ; k>=T ; k--)
                printf("%d ",arr[k][L]);
            L++;
        }
        dir=(dir+1)%4;
    }
    cout<<endl;
}

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    spiral();
	}
	return 0;
}
