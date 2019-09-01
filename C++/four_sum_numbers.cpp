// FIND ALL FOUR SUM NUMBERS


// Brute - Force

#include <bits/stdc++.h>
using namespace std;

void fn(vector<int> &v, int a, int b, int i1, int i2, int i3, int i4, set<string> &s)
{
    if(i1 == i2 || i1 == i3 || i1 == i4 || i2 == i3 || i2 == i4 || i3 == i4 || 
       i1 >= i2 || i2 >= i3 || i3 >= i4 || i4 >= a)
    {
        return;
    }
    int y = v[i1] + v[i2] + v[i3] + v[i4];
    if(b == y)
    {
        string s1 = to_string(v[i1]) + " ";
        s1 = s1 + to_string(v[i2]);
        s1 = s1 + " ";
        s1 = s1 + to_string(v[i3]);
        s1 = s1 + " ";
        s1 = s1 + to_string(v[i4]);
        s1 = s1 + " $";
        if(s.find(s1) == s.end())  
        {
            cout<<s1;
            s.insert(s1);
        }
    }
    if(i4+1 != a)  fn(v, a, b, i1, i2, i3, i4+1, s);
    if(i3+1 != i4)  fn(v, a, b, i1, i2, i3+1, i4, s);
    if(i2+1 != i3)  fn(v, a, b, i1, i2+1, i3, i4, s);
    if(i1+1 != i2)  fn(v, a, b, i1+1, i2, i3, i4, s);
}

int main() 
{
	int t, a, b, x;
	cin>>t;
	while(t--)
	{
	    cin>>a>>b;
	    int flag = 0;
	    vector<int> v;
	    for(int i=0; i<a; i++)  
	    {
	        cin>>x;
	        v.push_back(x);
	    }
	    if(a<4)  cout<<-1;
	    else
	    {
	        set<string> s;
	        sort(v.begin(), v.end());
    	    fn(v, a, b, 0, 1, 2, 3, s);
    	    if(!s.empty())
    	    {
    	       // set<string> :: iterator it;
        	   // for(auto it:s)
        	   //     cout<<it;
        	    flag = 1;
    	    }
	    }
	    if(flag == 0)  cout<<-1;
	    cout<<endl;
	}
	return 0;
}


// Efficient

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,i,j,k,l;
    cin>>t;
    while(t--)
    {
        int n,sum;
        cin>>n>>sum;
        int a[n];
        for(i=0;i<n;i++)
          cin>>a[i];
        sort(a,a+n);  
        int p=0;
        unordered_map<string,int>mp;
        for(i=0;i<n-3;i++)
        {
            for(j=i+1;j<n-2;j++)
            {
                for(k=j+1;k<n-1;k++)
                {
                    for(l=k+1;l<n;l++)
                    {
                       if(a[i]+a[j]+a[k]+a[l]==sum)
                       {
                       string x="";
                       x=to_string(a[i])+to_string(a[j])+to_string(a[k])+to_string(a[l]); 
                       if(mp[x]==0)
                       {
                          cout<<a[i]<<" "<<a[j]<<" "<<a[k]<<" "<<a[l]<<" "<<"$";
                          mp[x]++;
                       }
                       }
                    }
                }
            }
        }
        if(mp.size()==0)
          cout<<"-1";
        cout<<endl;
    }
}
