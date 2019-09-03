// CLASSROOM

/*

QUESTION:

There are 4 classrooms - Jupiter, Saturn, Mercury and Pluto with a capacity of 100, 60, 20 and 10 students each. 
Input no. of lectures and students in each lecture. 
Make a schedule by allotting the classroom with the minimum possible capacity, for each lecture. 
If no. of lectures is more than 4 or less than 1, print ERROR. 
If students can’t be accommodated, print NO

For example:

3
13 88 57
Mercury
Jupiter
Saturn
 
INPUT
No. of lectures followed by students in each lectures

OUTPUT
List of classrooms alloted line by line
 
SAMPLE INPUT
2 
57 20
 
SAMPLE OUTPUT
SATURN
MERCURY

TEST CASES
 
CASE 1:
5
ERROR
 
CASE 2:
3
83 47 99
NO

CASE 3:
4
47 5 19 33
SATURN
PLUTO
MERCURY
JUPITER

CASE 4:
3
99 5 19
JUPITER
PLUTO
MERCURY

*/


#include<iostream>
#include<string.h>
using namespace std; 

int main()
{
    int j=0, s=0, m=0, p=0, n;
    string str = "";
    cin>>n;
    if(n>=1 && n<=4)
    {
        int a[n];
        for(int i=0; i<n; i++)
            cin>>a[i];
        for(int i=0; i<n; i++)
        {
            if(a[i]>0 && a[i]<=10)
            {
                if((p == 1) && (m == 1) && (s == 1) && (j ==1))
                {
                    str = "NO";
                    break;
                }
                else if((p == 1) && (m == 0))
                {
                    m++;
                    str = str + "MERCURY\n";    
                }
                else if((p == 1) && (m == 1) && (s == 0))
                {
                    s++;
                    str = str + "SATURN\n";    
                }
                else if((p == 1) && (m == 1) && (s == 1) && (j == 0))
                {
                    j++;
                    str = str + "JUPITER\n";    
                }
                else
                {
                    p++;
                    str = str + "PLUTO\n"; 
                }   
            }
            else if(a[i]>10 && a[i]<=20)
            {
                if((m == 1) && (s == 1) && (j ==1))
                {
                    str = "NO";
                    break;
                }
                else if((m == 1) && (s == 0))
                {
                    s++;
                    str = str + "SATURN\n";
                }
                else if((m == 1) && (s == 1) && (j == 0))
                {
                    j++;
                    str = str + "JUPITER\n";
                }
                else
                {
                    m++;
                    str = str + "MERCURY\n";    
                }
            }
            else if(a[i]>20 && a[i]<=60)
            {
                if((s == 1) && (j ==1))
                {
                    str = "NO";
                    break;
                }
                else if((s == 1) && (j == 0))
                {
                    j++;
                    str = str + "JUPITER\n";
                }
                else
                {
                    s++;
                    str = str + "SATURN\n"; 
                }      
            }
            else if(a[i]>60 && a[i]<=100)
            {
                if(j == 1)
                {
                    str = "NO";
                    break;
                }
                else
                {
                    j++;
                    str = str + "JUPITER\n"; 
                }     
            }
            else
                str = "ERROR";
        }
    }
    else
        str = "ERROR";
    
    cout<<str;
    return 0;
}