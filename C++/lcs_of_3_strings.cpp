// LCS of three strings

#include <iostream>
using namespace std;

int max(int a, int b, int c)  
{  
    if(a>=b && a>=c)  return a;
    else if(b>=a && b>=c)  return b;
    else  return c;
    
}

int lcs3(string s1, string s2, string s3)
{
    int a[s1.length()+1][s2.length()+1][s3.length()+1];
    
    for(int i=0; i<=s1.length(); i++)
    {
        for(int j=0; j<=s2.length(); j++)
            a[i][j][0] = 0;
    }
    for(int i=0; i<=s2.length(); i++)
    {
        for(int j=0; j<=s3.length(); j++)
            a[0][i][j] = 0;
    }
    for(int i=0; i<=s3.length(); i++)
    {
        for(int j=0; j<=s1.length(); j++)
            a[j][0][i] = 0;
    }
    
    for(int i=1; i<=s1.length(); i++)
    {
        for(int j=1; j<=s2.length(); j++)
        {
            for(int k=1; k<=s3.length(); k++)
            {
                if(s1[i-1] == s2[j-1] && s2[j-1] == s3[k-1])  
                    a[i][j][k] = 1 + a[i-1][j-1][k-1];
                else  
                    a[i][j][k] = max(a[i-1][j][k], a[i][j-1][k], a[i][j][k-1]);
            }
        }
    }
    return a[s1.size()][s2.size()][s3.size()];
}

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n1, n2, n3;
	    string s1, s2, s3;
	    cin>>n1>>n2>>n3>>s1>>s2>>s3;
	    cout<<lcs3(s1, s2, s3)<<endl;
	}
	return 0;
}