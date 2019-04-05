//BINARY ADDITION AND SUBTRACTION USING SIGN MAGNITUDE REPRESENTATION

#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;

string add(string str1, string str2);
string sub(string str1, string str2);

int main()
{
    string str1, str2, str3;
    cout<<"Input 2 signed binary numbers: ";
    cin>>str1>>str2;
    cout<<"Addition: ";
    if((str1[0]=='1' && str2[0]=='1') || (str1[0]=='0' && str2[0]=='0'))
        str3 = add(str1, str2);
    else if((str1[0]=='0' && str2[0]=='1') || (str1[0]=='1' && str2[0]=='0'))
        str3 = sub(str1, str2);
    cout<<str3;
}

string add(string str1, string str2)
{
    int l1=str1.length(), l2=str2.length(), carry = 0, temp;
    string result = "", str3;
    char ch;
    if(l1>l2)
    {
        str3 = str2[0];
        for(int i=0; i<l1-l2; i++)
            str3 = str3 + '0';
        for(int i=1; i<l2; i++)
            str3 = str3 + str2[i];
        str2 = str3;
    }
    else
    {
        str3 = str1[0];
        for(int i=0; i<l2-l1; i++)
            str3 = str3 + '0';
        for(int i=1; i<l1; i++)
            str3 = str3 + str1[i];
        str1 = str3;
    }
    str3="";
    for(int i = l1-1; i>0; i--)
    {
        temp = str1[i] + str2[i] + carry - 96;
        carry = temp / 2;
        temp = temp % 2;
        ch = temp + 48;
        str3 = ch + str3;
    }
    if(carry != 0)
        str3 = '1' + str3;
    str3 = str1[0] + str3;
    return str3;
}

string sub(string str1, string str2)
{
    int l1=str1.length(), l2=str2.length(), carry = 0, temp;
    string result = "", str3, str4;
    char ch;
    if(l1>l2)
    {
        str3 = str2[0];
        for(int i=0; i<l1-l2; i++)
            str3 = str3 + '0';
        for(int i=1; i<l2; i++)
            str3 = str3 + str2[i];
        str2 = str3;
    }
    else
    {
        str3 = str1[0];
        for(int i=0; i<l2-l1; i++)
            str3 = str3 + '0';
        for(int i=1; i<l1; i++)
            str3 = str3 + str1[i];
        str1 = str3;
    }
    str3 = str2;
    for(int i = l1-1; i>0; i--)
    {
        if(str3[i] == '0')
            str3[i] = '1';
        else
            str3[i] = '0';
    }
    str4 = str3[0] + '1';
    str4 = add(str3, str4);
    result = add(str3, str4);
    if(str4.length() > l1)
    {
        str4 = "";
        for(int i = l1; i>1; i--)
            str4 = result[i] + str4;
        str4 = result[0] + str4; 
    }
    else
    {
        for(int i = l1-1; i>0; i--)
        {
            if(result[i] == '0')
                result[i] = '1';
            else
                result[i] = '0';
        }
        str4 = str3[0] + '1';
        str4 = add(result, str4);
    }
    return str4;
}