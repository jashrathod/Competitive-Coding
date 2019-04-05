// BINARY TO DECIMAL AND DECIMAL TO BINARY

#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;

void convert_to_binary(string number);
void convert_to_decimal(string number);

int main()
{
    string number;
    int option;
    do
    {
        cout<<"\n1. Convert to Binary\n2. Convert to Decimal\n3. Exit\nEnter choice: ";
        cin>>option;
        if(option == 1)
        {
            cout<<"Input Decimal number: ";
            cin>>number;
            convert_to_binary(number);
        }
        if(option == 2)
        {
            cout<<"Input Binary number: ";
            cin>>number;
            convert_to_decimal(number);
        }
        cout<<endl; 
    }while((option == 1) || (option == 2));
}

void convert_to_binary(string number)
{
    int l = number.length();
    long decimal_number = 0;
    char ch;
    string result = "";
    for(int i=l-1; i>=0; i--)
    {
        int temp = number[i];
        temp = temp-48;
        decimal_number = decimal_number + temp * pow(10, l-i-1);
    }
    int t = decimal_number;
    if(t == 0)
        result = "0";
    while(t != 0)
    {
        ch = (t%2) + 48;
        t = t/2;
        result = ch + result;
    }
    cout<<"Binary value of "<<decimal_number<<" is "<<result;
}

void convert_to_decimal(string number)
{
    int l = number.length();
    long decimal_number = 0;
    for(int i=l-1; i>=0; i--)
    {
        int temp = number[i];
        temp = temp-48;
        decimal_number = decimal_number + temp * pow(2, l-i-1);
    }
    cout<<"Decimal value of "<<number<<" is "<<decimal_number;
}