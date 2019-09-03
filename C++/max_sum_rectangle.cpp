// Maximum Sum Rectangle

#include<bits/stdc++.h>
using namespace std;
int kadane(int arr[],int n)
{
    int max_ending_here=0;
    int max_so_far=0;
    int i,j,k,count=0,min=INT_MAX;
    for(i=0; i<n; i++)
    {   
        if(arr[i]<0)
            count++;
        if(arr[i]<min)
            min=arr[i];
        
        max_ending_here += arr[i];
        
        if(max_ending_here<0)
            max_ending_here=0;
        if(max_so_far<max_ending_here)
            max_so_far=max_ending_here;
    }
    if(count==n)
        return min;
    else
        return max_so_far;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int rows,columns,ans=INT_MIN;
        int i,j,k,l,r;
        cin>>rows>>columns;
        int mat[rows][columns];
        for(i=0;i<rows;i++)
        {
            for(j=0;j<columns;j++)
                cin>>mat[i][j];
        }
        int arr[rows];
        for(l=0;l<columns;l++)
        {
            memset(arr,0,sizeof(arr));
            for(r=l;r<columns;r++)
            {
                for(i=0; i<rows; i++)
                    arr[i]+=mat[i][r];
                ans=max(ans,kadane(arr,rows));
            }
        }
        cout<<ans<<endl;
    }
}