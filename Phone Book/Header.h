#include <iostream>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <cctype>
#include <cstdlib>
#include <string>
#include <ctime>
#include <Windows.h>
#include <conio.h>

using namespace std;

COORD CursorPosition;
HANDLE hHandle = GetStdHandle(STD_OUTPUT_HANDLE);

int ctr = 0;

struct Birthday{
	string month;
	int day;
	int year;
};

struct Contact{
	char Lname[15];
	char Fname[15];
	Birthday birth;
	char Cno[12];
	int Tno;
	string email;
	
} contact[30];

void newLine()
{
	char s;
	do { cin.get(s); } while (s != '\n');
}

void gotoXY(int x, int y)
{
	CursorPosition.X = x;
	CursorPosition.Y = y;
	SetConsoleCursorPosition(hHandle, CursorPosition);
}

void BM()
{
	int pick = 0;
	bool run = true;
	string months[12] = { "JANUARY", "FEBRUARY", "MARCH", "APRIL", "MAY", "JUNE", "JULY", "AUGUST", "SEPTEMBER", "OCTOBER", "NOVEMBER", "DECEMBER" };
	while (run){
		cout << setiosflags(ios::left);
		cout << setw(9) << setfill(' ');
		gotoXY(20, 5);
		for (int i = 0; i < 12; i++)
		{
			if (pick == i)
				cout << months[i];
		}
		system("pause > 0");
		while (true){
			if (GetAsyncKeyState(VK_UP) != 0)
			{
				pick -= 1;
				if (pick == -1)
					pick = 11;
				break;
			}
			else if (GetAsyncKeyState(VK_DOWN) != 0)
			{
				pick += 1;
				if (pick == 12)
					pick = 0;
				break;
			}
			else if (GetAsyncKeyState(VK_RETURN) != 0)
			{
				contact[ctr].birth.month = months[pick];
				run = false;
				break;
			}
		}		
	}
	cout << setiosflags(ios::right);
}

void add()
{
	gotoXY(8, 1);
	printf("A D D   C O N T A C T");
	newLine();
	cout << endl;
	cout << setw(20) << "First Name: "; gets_s(contact[ctr].Fname);
	cout << setw(20) << "Last Name: "; gets_s(contact[ctr].Lname);
	cout << setw(20) << "Month of Birth: "; BM(); cout << endl;
	cout << setw(20) << "Day of Birth: "; cin >> contact[ctr].birth.day;
	cout << setw(20) << "Year of Birth: "; cin >> contact[ctr].birth.year;
	cout << setw(20) << "Cellphone Number: "; newLine(); gets_s(contact[ctr].Cno);
	cout << setw(20) << "Telephone Number: "; cin >> contact[ctr].Tno;
	cout << setw(20) << "E-Mail Address: "; cin >> contact[ctr].email;
}

void view()
{
	gotoXY(8, 1);
	printf("V I E W   C O N T A C T");
	cout << endl;
	cout << setw(20) << "First Name: "; cout << contact[0].Fname << endl;
	cout << setw(20) << "Last Name: "; cout << contact[ctr].Lname << endl;
	cout << setw(20) << "Month of Birth: "; cout << contact[ctr].birth.month << endl;
	cout << setw(20) << "Day of Birth: "; cout << contact[ctr].birth.day << endl;
	cout << setw(20) << "Year of Birth: "; cout << contact[ctr].birth.year << endl;
	cout << setw(20) << "Cellphone Number: "; cout << contact[ctr].Cno << endl;
	cout << setw(20) << "Telephone Number: "; cout << contact[ctr].Tno << endl;
	cout << setw(20) << "E-Mail Address: "; cout << contact[ctr].email;
}

