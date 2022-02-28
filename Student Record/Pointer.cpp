#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <cmath>
#include <cctype>
#include <cstdlib>
#include <Windows.h>

using namespace std;

int ctr = 0, rec = 0;

struct Student{
	int id;
	string Lname;
	char Fname[20];
	char midE;
	int quiz[3];
	double ave;
	string remark;
} *stud;

void input();
void output();

void newLine()
{
	char s;
	do { cin.get(s); } while (s != '\n');
}

int main()
{
	stud = new Student[30];
	cout << setw(40) << "STUDENT RECORD" << endl << endl;
	cout << setw(30) << "Enter the number of records: "; 
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	cin >> ctr;
	cout << endl;
	while (rec < ctr){
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
		cout << setw(10) << "RECORD #" << rec + 1 << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		input();
		cout << endl << endl;
		++rec;
	}
	system("pause > 0");
	rec = 0;
	system("cls");
	output();
	system("pause > 0");
	return 0;
}

void input()
{
	int sum = 0;
	newLine();
	cout << setprecision(2);
	cout << setiosflags(ios::fixed);
start:
	cout << setw(13) << "ID Number: "; cin >> (stud+rec)->id; //newLine();
	if ((stud + rec)->id > 9999 || (stud + rec)->id <= 999){
		cout << setw(20) << "Please try again!\n";
		goto start;
	}
	for (int i = 0; i < rec; i++)
		if ((stud + rec)->id == (stud + i)->id){
		cout << setw(20) << "Please try again!\n";
		goto start;
		}
	cout << setw(13) << "Last Name: "; cin >> ((stud + rec)->Lname); newLine();
	cout << setw(13) << "First Name: "; cin.getline((stud + rec)->Fname, 20); //newLine();
	// cout << setw(13) << "Middle Initial: "; cin.get((stud + rec)->midE); //newLine();
	cout << endl;
	for (int i = 0; i < 3; i++){
		cout << setw(8) << "Quiz #" << i + 1 << ": "; cin >> (stud + rec)->quiz[i];
		if ((stud + rec)->quiz[i] > 100 || (stud + rec)->quiz[i] < 0){
			cout << setw(20) << "Please try again!";
			system("pause>0");
			cout << endl;
			--i;
			continue;
		}
		sum += (stud + rec)->quiz[i];
	}
	cout << endl;
	(stud+rec)->ave = sum / 3.00;
	cout << setw(10) << "Average: " << (stud + rec)->ave;
	cout << endl;
	cout << setw(10) << "Remarks: ";
	if ((stud + rec)->ave >= 75){
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		(stud + rec)->remark = "PASSED";
	}
	else{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		(stud + rec)->remark = "FAILED";
	}
	cout << (stud + rec)->remark;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

void output()
{
	int pass = 0, fail = 0;
	cout << setw(48) << "STUDENT RECORD RESULT" << endl;
	//cout << setiosflags(ios::left);
	cout << setw(10) << "RECORD #"
		<< setw(11) << "ID"
		<< setw(18) << "NAME"
		<< setw(19) << "AVERAGE"
		<< setw(15) << "REMARKS" << endl;
	//cout << setiosflags(ios::right);
	for (int i = 0; i < ctr; i++){
		cout << setw(6) << i+1;
		cout << setw(16) << (stud+i)->id;
		cout << setw(17) << (stud+i)->Lname << ", " << (stud+i)->Fname[0];
		cout << setw(15) << setprecision(2) << (stud+i)->ave;
		if ((stud + i)->remark == "PASSED")
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		else
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		cout << setw(15) << (stud+i)->remark;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

		cout << endl;
	}
	cout << endl;
	for (int i = 0; i < ctr; i++){
		if ((stud + i)->remark == "PASSED")
			++pass;
		else
			++fail;
	}
	//cout << setiosflags(ios::left);
	cout << setw(25) << "Number of Passed: ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); 
	cout << pass;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cout << setw(35) << "Number of Failed: ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	cout << fail;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}