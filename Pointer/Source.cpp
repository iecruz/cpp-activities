#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <cstring>
#include <string>
#include <cmath>
#include <cctype>
#include <iomanip>
#include <stdlib.h>
#include <Windows.h>
#include <algorithm>
#include "pH.h"

using namespace std;

COORD CursorPosition;

int sel = 0, sel1 = 0, itt = 0;

void title(string);
void input();
void fMenu();
void fInput();
void YN(int);
void gotoXY(int, int);

int main()
{
	char x[160], y[160], z;
	string menu[10] = { "PALINDROME", "VOWELS AND CONSONANT", "REVERSE", "INSERT", "TITLE CASE", "WORD COUNT", "CHARACTER FREQUENCY", "WORD SORTING", "FUNCTIONS", "EXIT" };
	while (true){
		system("cls");
		system("color 17");
		title("M A I N   M E N U");
		for (int i = 0; i < 10; i++){
			if (i == sel){
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 28);
				cout << "    >> ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 23);
				cout << menu[i] << endl << endl;
			}
			else{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 24);
				cout << "       " << menu[i] << endl << endl;
			}
		}
		system("pause>0");
		while (true){
			if (GetAsyncKeyState(VK_UP) != 0){
				sel -= 1;
				if (sel == -1)
					sel = 9;
				break;
			}
			else if (GetAsyncKeyState(VK_DOWN) != 0){
				sel += 1;
				if (sel == 10)
					sel = 0;
				break;
			}
			else if (GetAsyncKeyState(VK_RETURN) != 0){
				system("cls");
				switch (sel)
				{
				case 8: fMenu(); break;
				case 9: exit(1); break;
				default: input();
				}
			}
			break;
		}
	}
	system("pause>0");
	return 0;
}

void title(string x)
{
	/* srand(NULL);
	const int r = rand(); */
	for (int i = 0; i < 40; i++){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 75);
			cout << "+ ";
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 23);
	cout << endl;
	gotoXY(20, 2);
	cout << x << endl << endl;
	for (int i = 0; i < 40; i++){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 75);
			cout << "+ ";
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 24);
	cout << endl;
}

void input()
{
	
	char x[160],y[160];
	int pos = 0;
	string pad("     ");
	switch (sel)
	{
	case 0:
		title("P A L I N D R O M E");
		cout << "PURPOSE: To determine if the given word is a PALINDROME.\n\n"
			<< "PALINDROME: A sequence of characters which reads the same backward or forward.\n\n";
		cout << pad << "ENTER A WORD:\n\n" << pad << pad;
		gets_s(x);
		cout << endl;
		if (Plndrm(x) == 1)
			cout << pad << "THE WORD " << x << " IS A PALINDROME.";
		else
			cout << pad << "THE WORD " << x << " IS NOT A PALINDROME.";
		break;

	case 1:
		title("V O W E L    A N D   C O N S O N A N T");
		cout << "PURPOSE: To count the vowels, consonants within the given phrase.\n\n";
		cout << pad << "ENTER A PHRASE:\n\n" << pad << pad; gets_s(x);
		cout << endl << pad; VC(x);
		break;

	case 2:
		title("R E V E R S E");
		cout << "PURPOSE: To reverse the position of the character in the given phrase.\n\n";
		cout << pad << "ENTER A PHRASE:\n\n" << pad << pad; gets_s(x);
		cout << endl;
		cout << pad << "THE REVERSE OF THE PHRASE:\n\n" << pad << pad << Rev(x);
		break;

	case 3:
		title("I N S E R T");
		cout << "PURPOSE: To insert another phrase into the first given phrase.\n\n";
		if (itt == 1)
			cin.ignore();
		itt = 1;
		cout << pad << "ENTER THE FIRST PHRASE:\n\n" << pad << pad; gets_s(x);
		cout << endl << endl << pad << "ENTER THE SECOND PHRASE:\n\n" << pad << pad; gets_s(y);
		cout << endl << endl << pad << "ENTER POSITION: "; cin >> pos;
		cout << endl << endl << pad << "THE NEW PHRASE:\n\n" << pad << pad << Ins(x, y, pos);
		break;

	case 4:
		title("T I T L E   C A S E");
		cout << "PURPOSE: To capitalize the first letter of each word in the given phrase.\n\n";
		cout << pad << "ENTER THE PHRASE:\n\n" << pad << pad; gets_s(x);
		cout << endl << endl << pad << "THE PHRASE IN TITLE CASE FORM:\n\n" << pad << pad << tCas(x);
		break;

	case 5:
		title("W O R D   C O U N T");
		cout << "PURPOSE: To count the words within the given phrase.\n\n";
		cout << pad << "ENTER A PHRASE:\n\n" << pad << pad; gets_s(x);
		cout << endl << endl << pad << "TOTAL WORDS: " << wdCtr(x);
		break;

	case 6:
		title("C H A R A C T E R   F R E Q U E N C Y");
		cout << "PURPOSE: To determine the frequency of each character in the given phrase.\n\n";
		cout << pad << "ENTER A PHRASE: "; gets_s(x); cout << endl;
		Frqncy(x);
		break;

	case 7:
		title("S O R T I N G");
		cout << "PURPOSE: To sort the words within the given phrase in an ascending order.\n\n";
		cout << pad << "ENTER A PHRASE:\n\n" << pad << pad; gets_s(x);
		cout << endl << endl << pad << "THE WORDS IN ASCENDING ORDER:\n\n" << pad << pad; Srt(x);
		break;
	}
	system("pause>0");
	YN(0);
}

void fMenu()
{
	string menu[10] = { "STRING LENGTH", "STRING COPY", "STRING COMPARE", "STRING CONCATENATE", "STRING REVERSE", "UPPER CASE", "LOWER CASE", "TITLE CASE", "TOGGLE CASE", "BACK" };
	while (true){
		system("cls");
		title("F U N C T I O N");
		cout << "          " << "PRE-DEFINED BASED USER DEFINED FUNCTIONS\n\n";
		for (int i = 0; i < 10; i++){
			if (i == 5){
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 23);
				cout << endl << "          " << "USER DEFINED FUNCTIONS\n\n";
			}
			if (i == 9)
				cout << endl;
			if (i == sel1){
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 28);
				cout << "    >> ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 23);
				cout << menu[i] << endl << endl;
			}
			else{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 24);
				cout << "       " << menu[i] << endl << endl;
			}
		}
		system("pause>0");
		while (true){
			if (GetAsyncKeyState(VK_UP) != 0){
				sel1 -= 1;
				if (sel1 == -1)
					sel1 = 9;
			}
			else if (GetAsyncKeyState(VK_DOWN) != 0){
				sel1 += 1;
				if (sel1 == 10)
					sel1 = 0;
			}
			else if (GetAsyncKeyState(VK_RETURN) != 0){
				system("cls");
				switch (sel1)
				{
				case 9: main(); break;
				default: fInput(); break;
				}
			}
			break;
		}
	}
}

void fInput()
{
	char x[160], y[160];
	string pad("     ");
	switch (sel1)
	{
	case 0:
		title("S T R I N G   L E N G T H");
		cout << "FUNCTION: To count the characters of the given string (strlen(x)).\n\n";
		cout << pad << "ENTER A STRING:\n\n" << pad << pad; gets_s(x);
		cout << endl;
		cout << pad << "TOTAL CHARACTERS: " << Len(x);
		break;
		
	case 1:
		title("S T R I N G   C O P Y");
		cout << "FUNCTION: To copy a string from one variable to another (strcpy(x,y)).\n\n";
		cout << pad << "ENTER FIRST STRING:\n\n" << pad << pad; gets_s(x);
		cout << endl;
		cout << pad << "ENTER SECOND STRING:\n\n" << pad << pad; gets_s(y);
		cout << endl;
		cout << pad << "OUTPUT:\n\n" << pad << pad; Cpy(x, y); cout << x;
		break;

	case 2:
		title("S T R I N G   C O M P A R E");
		cout << "FUNCTION: To compare the two given strings (strcmp(x,y)).\n\n";
		cout << pad << "ENTER FIRST STRING:\n\n" << pad << pad; gets_s(x);
		cout << endl;
		cout << pad << "ENTER SECOND STRING:\n\n" << pad << pad; gets_s(y);
		cout << endl;
		cout << pad << "OUTPUT: " << Cmp(x, y);
		break;

	case 3:
		title("S T R I N G   C O N C A T E N A T E");
		cout << "FUNCTION: To concatenate the two given string (strcat(x,y)).\n\n";
		cout << pad << "ENTER FIRST STRING:\n\n" << pad << pad; gets_s(x);
		cout << endl;
		cout << pad << "ENTER SECOND STRING:\n\n" << pad << pad; gets_s(y);
		cout << endl;
		cout << pad << "OUTPUT:\n\n" << pad << pad; Cat(x, y); cout << x;
		break;

	case 4:
		title("S T R I N G   R E V E R S E");
		cout << "FUNCTION: To reverse the given string (strrev(x)).\n\n";
		cout << pad << "ENTER A STRING:\n\n" << pad << pad; gets_s(x);
		cout << endl;
		cout << pad << "OUTPUT:\n\n" << pad << pad << Rev(x);
		break;

	case 5:
		title("U P P E R   C A S E");
		cout << "FUNCTION: To print out all characters in upper case form.\n\n";
		cout << pad << "ENTER A STRING:\n\n" << pad << pad; gets_s(x);
		cout << endl;
		cout << pad << "OUTPUT:\n\n" << pad << pad << uprC(x);
		break;

	case 6:
		title("L O W E R   C A S E");
		cout << "FUNCTION: To print out all characters in lower case form.\n\n";
		cout << pad << "ENTER A STRING:\n\n" << pad << pad; gets_s(x);
		cout << endl;
		cout << pad << "OUTPUT:\n\n" << pad << pad << lwrC(x);
		break;

	case 7:
		title("T I T L E   C A S E");
		cout << "FUNCTION: To print out the given string in title case form.\n\n";
		cout << pad << "ENTER A STRING:\n\n" << pad << pad; gets_s(x);
		cout << endl;
		cout << pad << "OUTPUT:\n\n" << pad << pad << tCas(x);
		break;

	case 8:
		title("T O G G L E   C A S E");
		cout << "FUNCTION: To toggle the case of each character in the given string.\n\n";
		cout << pad << "ENTER A STRING:\n\n" << pad << pad; gets_s(x);
		cout << endl;
		cout << pad << "OUTPUT:\n\n" << pad << pad << tC(x);
		break;
	}
	system("pause>0");
	YN(1);
}

void YN(int x)
{
	int ch = 0;
	string c[2] = { "YES", "NO" };
	cout << "\n\n     CONTINUE?";
	while (true){
		for (int i = 0; i < 2; i++){
			if (ch == i){
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 28);
				cout << "   > ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 23);
				cout << c[i];
			}
			else{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 24);
				cout << "     " << c[i];
			}
		}
		system("pause>CS");
		while (true){
			if (GetAsyncKeyState(VK_LEFT) != 0){
				ch -= 1;
				if (ch == -1)
					ch = 1;
				break;
			}
			else if (GetAsyncKeyState(VK_RIGHT) != 0){
				ch += 1;
				if (ch == 2)
					ch = 0;
				break;
			}
			else if (GetAsyncKeyState(VK_RETURN) != 0){
				// cin.ignore();
				system("cls");
				switch (ch)
				{
				case 0: 
					if (x == 0)
						input();
					else
						fInput();
					break;
				case 1: main();
				}
			}
			break;
		}
		cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
	}
}

void gotoXY(int x, int y)
{
	CursorPosition.X = x;
	CursorPosition.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CursorPosition);
}