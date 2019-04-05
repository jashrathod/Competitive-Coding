// QUESTION MARKS

/*

QUESTION: 

Take an input string and determine if exactly x question marks exist between every pair of consecutive numbers that add up to y. 
If so, print YES. Otherwise print NO. 
Input x and y from the user. 
Print ERROR if there are no question marks at all.
 
INPUT
One string and two integers
 
OUTPUT
YES/NO

SAMPLE INPUT
DJ3?DJ??SHAR?ANAM9??BHAJE??BHAJE3
4
12

SAMPLE OUTPUT
YES

EXPLANATION
There are exactly 4 question marks between every pair of consecutive numbers that add to 12

CONSTRAINTS
X should be positive. Consider only single digit numbers

TEST CASES

CASE 1:
Arrb6???4xxbl5??bb?eee5
3
10
YES

CASE 2:
THE DJ IS HERE
5
25
ERROR

CASE 3:
Acc?7??s?ss?5rr1??????5?ef??ef?7
4
12
YES

CASE 4:
5??aaaaaaaaaaaaaaaaaaa?5?5
3
10
NO

*/


#include<iostream>
#include<string.h>
using namespace std;

int main()
{
    string str;
    int x, y, a, b, count = 0, flag;
    getline(cin, str);
    cin>>x>>y;
    for(int i=0; i<str.length(); i++)
    {
        if(str[i] == '?')
        {
            flag = 0;
            break;
        }
        else 
            flag = 2;
    }
    if(flag != 2)
    {
        for(int i=0; i<str.length(); i++)
        {
            if((str[i]>=48 && str[i]<=57) && flag == 0)
            {
                a = str[i] - 48;
                flag = 1;
            }
            else if((str[i]>=48 && str[i]<=57) && flag == 1)
            {
                b = str[i] - 48;
                if(a+b == y)
                {
                    flag = 0;
                    if(count != x)
                    {
                        flag = 3;
                        break;
                    }
                }
                a = b;
                flag = 1;
                count = 0;
            }
            else if(str[i] == '?' && flag == 1)
                count++;
        }
    }
    
    if(flag == 2)
        cout<<"ERROR\n";
    else if(flag == 3)
        cout<<"NO\n";
    else
        cout<<"YES\n";
}