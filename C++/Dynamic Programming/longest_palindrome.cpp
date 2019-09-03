// Longest Palindrome in a String


// 1

#include <bits/stdc++.h> 
using namespace std; 

void printSubStr( string str, int low, int high ) 
{ 
	for( int i = low; i <= high; ++i ) 
		cout << str[i]; 
} 

int longestPalSubstr(string str) 
{ 
	int n = str.size(); 
	bool table[n][n]; 
	
	memset(table, 0, sizeof(table)); 

	int maxLength = 1; 
	
	for (int i = 0; i < n; ++i) 
		table[i][i] = true; 

	int start = 0; 
	for (int i = 0; i < n-1; ++i) 
	{ 
		if (str[i] == str[i+1]) 
		{ 
			table[i][i+1] = true; 
			start = i; 
			maxLength = 2; 
		} 
	} 

	for (int k = 3; k <= n; ++k) 
	{ 
		for (int i = 0; i < n-k+1 ; ++i) 
		{ 
			int j = i + k - 1; 

			if (table[i+1][j-1] && str[i] == str[j]) 
			{ 
				table[i][j] = true; 

				if (k > maxLength) 
				{ 
					start = i; 
					maxLength = k; 
				} 
			} 
		} 
	} 

    cout << "Longest palindrome substring is: "; 
    printSubStr( str, start, start + maxLength - 1 ); 
	
	return maxLength; 
} 

int main() 
{ 
	string str = "forgeeksskeegfor"; 
	cout << "\nLength is: " << longestPalSubstr( str ); 
	return 0; 
} 


// 2

#include <iostream>
using namespace std;

string palindrome(string s)
{
    int n=s.length(), m=1, start=0;
    string p;
    bool a[n][n] = { false };
    for(int i=0; i<n; i++)  a[i][i] = true;
    for(int i=0; i<n-1; i++)
    {
        if(s[i] == s[i+1])
        {
            m=2;
            if(start == 0)  start = i;
            a[i][i+1] = true;
        }
    }
    for(int i=2; i<n; i++)
    {
        for(int j=0; j<n-i; j++)
        {
            if(s[j] == s[j+i] && a[j+1][j+i-1])
            {
                if(m < i+1)
                {
                    m=i+1;
                    start = j;
                }
                a[j][j+i] = true;
            }
        }
    }
    string result = "";
    for(int i=start; i<start+m; i++)  result += s[i];
    return result;
}

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    string s;
	    cin>>s;
	    cout<<palindrome(s)<<endl;
	}
	return 0;
}