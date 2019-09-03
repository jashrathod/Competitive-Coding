// NESTED STRUCTURES

#include<iostream>
#include<string.h>
#include<stack>
using namespace std;

int main()
{
    struct DOB {
        int day;
	    int month;
        int year;
    };
    
    struct student {
        int roll_no;
        char name[100];
        float fees;
        struct DOB date;
    };

    struct student stud1;
	cout << "\n Enter the roll number : ";
	cin >> stud1.roll_no;
	cout << "\n Enter the name : ";
	cin >> stud1.name;
	cout << "\n Enter the fees : ";
	cin >> stud1.fees;
	cout << "\n Enter the DOB : ";
	cin >> stud1.date.day >> stud1.date.month >> stud1.date.year;
	
	cout << "\n ********STUDENT'S DETAILS *******";
    
    cout << "\n ROLL No. = " << stud1.roll_no << "\n NAME = " << stud1.name << "\n FEES = " << stud1.fees;
	cout << "\n DOB = " << stud1.date.day << " - " << stud1.date.month << " - " << stud1.date.year << endl;
	return  0;
}
