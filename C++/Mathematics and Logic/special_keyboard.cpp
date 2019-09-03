// SPECIAL KEYBOARD

#include <bits/stdc++.h>
using namespace std;

int special(int N) 
{ 
	if (N <= 6) 
		return N; 

	int screen[N];
	int b; 
	int n; 
	
	for (n = 1; n <= 6; n++) 
		screen[n - 1] = n; 
		
	for (n = 7; n <= N; n++) 
	{ 
		screen[n - 1] = 0; 
		for (b = n - 3; b >= 1; b--) 
		{ 
			int curr = (n - b - 1) * screen[b - 1]; 
			if (curr > screen[n - 1]) 
				screen[n - 1] = curr; 
		} 
	} 
	return screen[N - 1]; 
} 

int main() 
{ 
	int t, n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<special(n)<<endl; 
    } 
} 
