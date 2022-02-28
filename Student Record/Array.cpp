#include <iostream>
#include <iomanip>
#include <cstring>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include <Windows.h>

using namespace std;

int ctr=0, rec=0;

void input();
void output();

struct Student{
	int id;
	string Lname;
	char Fname[30];
	int quiz[3];
	double ave;
	string remark;
} stud[30];

void newLine()
{
	char s;
	do { cin.get(s); } while (s != '\n');
}

int main()
{
	cout << setw(40) << "STUDENT RECORD\n\n";
	cout << setw(30) << "Enter the Number of Record: "; cin >> ctr;
	cout << endl;
	while (rec < ctr){
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
		cout << setw(10) << "RECORD #" << rec + 1 << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		input();
		cout << endl << endl;
		++rec;
	}
	system("pause>0");
	system("cls");
	output();
	system("pause>0");
	return 0;
}

void input()
{
	int sum = 0;
	newLine();
	cout << setprecision(2);
	cout.setf(ios::fixed);
start:
	cout << setw(13) << "ID Number: "; cin >> stud[rec].id;
	if (stud[rec].id > 9999 || stud[rec].id < 1000){
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		cout << setw(20) << "Please try again!\n";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		goto start;
	}
	for (int i = 0; i < rec; i++)
		if (stud[rec].id == stud[i].id){
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		cout << setw(48) << "ID Number is already taken. Please try again!\n";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		goto start;
		}
	cout << setw(13) << "Last Name: "; cin >> stud[rec].Lname; newLine();
	cout << setw(13) << "First Name: "; gets_s(stud[rec].Fname);
	cout << endl;
	for (int i = 0; i < 3; i++){
		cout << setw(8) << "Quiz #" << i + 1 << ": "; cin >> stud[rec].quiz[i];
		if (stud[rec].quiz[i] > 100 || stud[rec].quiz[i] < 0){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
			cout << setw(20) << "Please try again!\n";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			--i;
			continue;
		}
		sum += stud[rec].quiz[i];
	}
	stud[rec].ave = sum / 3.00;
	cout << endl << setw(10) << "Average: " << stud[rec].ave << endl;
	if (stud[rec].ave >= 75)
		stud[rec].remark = "PASSED";
	else
		stud[rec].remark = "FAILED";
	cout << setw(10) << "Remarks: ";
	if (stud[rec].remark == "PASSED")
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	else
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	cout << stud[rec].remark;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	
}

void output()
{
	int pass = 0, fail = 0;
	cout << setw(47) << "STUDENT RECORD RESULT\n";
	cout << setw(10) << "RECORD #"
		<< setw(11) << "ID"
		<< setw(18) << "NAME"
		<< setw(19) << "AVERAGE"
		<< setw(15) << "REMARKS" << endl;
	for (int i = 0; i < ctr; i++){
		cout << setw(6) << i + 1
			<< setw(16) << stud[i].id
			<< setw(19) << stud[i].Lname << ", " << stud[i].Fname[0]
			<< setw(13) << setprecision(2) << stud[i].ave;
		if (stud[i].remark == "PASSED")
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		else
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		cout << setw(15) << stud[i].remark << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	}
	cout << endl;
	for (int i = 0; i < ctr; i++){
		if (stud[i].remark == "PASSED")
			++pass;
		else
			++fail;
	}
	cout << setw(25) << "Number of Passed: ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	cout << pass;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cout << setw(35) << "Number of Failed: ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	cout << fail;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}