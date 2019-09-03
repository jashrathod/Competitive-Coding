// Find median in stream


// Not efficient

#include <iostream>
using namespace std;

void med_fn(int a[], int n)
{
    for(int i=0; i<n; i++)
    {
        int j = i-1, key = a[i];
        
        while(j>=0 && a[j]>key) 
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
        
        if(i/2 == (i+1)/2)  cout<<a[i/2]<<endl;
        else  cout<<((a[i/2] + a[(i+1)/2])/2)<<endl;
    }
}

int main() 
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];
    med_fn(a, n);
	return 0;
}


// Efficient

#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int n;
	priority_queue<int> q1;
	priority_queue<int, vector<int>, greater<int>> q2;
	cin>>n;
	while(n--)
	{
	    int x;
	    cin>>x;
	    if(q1.empty() && q2.empty())
	    {
	        q1.push(x);
	        cout<<q1.top();
	    }
	    else if(q2.empty() && !q1.empty())
	    {
	        if(x > q1.top())  q2.push(x);
	        else 
	        {
	            q2.push(q1.top());
	            q1.pop();
	            q1.push(x);
	        }
	        cout<<(q1.top() + q2.top())/2;
	    }
	    else
	    {
	        if(x > q1.top())  q2.push(x);
	        else  q1.push(x);
	        
	        if(q2.size() - q1.size() == 2)
	        {
	            q1.push(q2.top());
	            q2.pop();
	        }
	        else if(q1.size() - q2.size() == 2)
	        {
	            q2.push(q1.top());
	            q1.pop();
	        }
	        
	        if(q1.size() == q2.size())
	            cout<<(q1.top() + q2.top())/2;
	        else if(q1.size() > q2.size())
	            cout<<q1.top();
	        else
	            cout<<q2.top();
	    }
	    cout<<endl;
	}
	return 0;
}