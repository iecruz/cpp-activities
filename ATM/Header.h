#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <ctime>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <Windows.h>

using namespace std;
using std::ofstream;

COORD Cursor;
HANDLE hHandle = GetStdHandle(STD_OUTPUT_HANDLE);

void gotoxy(int x, int y){ Cursor = { x, y }; SetConsoleCursorPosition(hHandle, Cursor); }

void newline(){ char s; do{ cin.get(s); } while (s != '\n'); }

class design{
public:

	void title()
	{
		for (int i = 0; i < 3; i++){
			gotoxy(0, i);
			SetConsoleTextAttribute(hHandle, 71);
			cout << "										";
		}
	}

	int menu(string x[], int no_item, int clr, int clr_h, int start)
	{
		int sel = 0;
		SetConsoleTextAttribute(hHandle, clr);
		while (true){
			for (int i = 0; i < no_item; i++){
				if (i == sel){
					gotoxy(5, start + (i * 2));
					SetConsoleTextAttribute(hHandle, clr_h);
					cout << ">>";
					SetConsoleTextAttribute(hHandle, clr);
					gotoxy(8, start + (i * 2));
					cout << x[i];
				}
				else{
					gotoxy(5, start + (i * 2));
					cout << "  ";
					gotoxy(8, start + (i * 2));
					cout << x[i];
				}
			}
			system("pause>0");
			while (true){
				if (GetAsyncKeyState(VK_UP) != 0){
					sel -= 1;
					if (sel == -1)
						sel = no_item - 1;
					break;
				}
				else if (GetAsyncKeyState(VK_DOWN) != 0){
					sel += 1;
					if (sel == no_item)
						sel = 0;
					break;
				}
				else if (GetAsyncKeyState(VK_RETURN) != 0){
					return sel;
					break;
				}
			}
		}
	}

	void fill(int start, int up_to)
	{
		SetConsoleTextAttribute(hHandle, 71);
		for (int i = 0; i < up_to; i++){
			gotoxy(1, start + i);
			cout << "									       ";
		}

	}

	int yn(int y, int clr, int clr_h)
	{
		int sel = 0;
		gotoxy(5, y);
		SetConsoleTextAttribute(hHandle, clr);
		cout << "CONTINUE?";
		cout << "   YES   NO";
		while (true){
			if (sel == 0){
				gotoxy(15, y);
				SetConsoleTextAttribute(hHandle, clr_h);
				cout << ">";
				SetConsoleTextAttribute(hHandle, clr);
				gotoxy(21, y);
				cout << " ";
			}
			else{
				gotoxy(15, y);
				cout << " ";
				gotoxy(21, y);
				SetConsoleTextAttribute(hHandle, clr_h);
				cout << ">";
				SetConsoleTextAttribute(hHandle, clr);
			}
			gotoxy(25, y);
			system("pause>CS");
			while (true){
				if (GetAsyncKeyState(VK_LEFT) != 0){
					sel -= 1;
					if (sel == -1)
						sel = 1;
					break;
				}
				else if (GetAsyncKeyState(VK_RIGHT) != 0){
					sel += 1;
					if (sel == 2)
						sel = 0;
					break;
				}
				else if (GetAsyncKeyState(VK_RETURN) != 0){
					return sel;
				}
				break;
			}
		}
	}

	int pin_input()
	{
		int x = 0;
		int temp, ten = 1000;
		for (int i = 0; i < 5; i++){
			gotoxy(21, 8 + i);
			SetConsoleTextAttribute(hHandle, 71);
			cout << "					";
		}
		gotoxy(32, 9);
		cout << "Enter PIN here: ";
		gotoxy(34, 11);
		SetConsoleTextAttribute(hHandle, 240); cout << "	    ";
		gotoxy(37, 11);
		while (ten >= 1){
			temp = _getch() - 48;
			//cout << temp;
			if (temp < 0 || temp > 9)
				continue;
			cout << "*";
			x += temp * ten;
			ten = ten / 10;
		}
		return x;
	}

}ui;

class animation{
public:

	void card()
	{
		char name[9];
		int n = 0;
		int loop = 0;
		strcpy_s(name, "SCHUBERT");
		system("cls");
		system("color 80");
		ui.title();
		gotoxy(16, 1);
		SetConsoleTextAttribute(hHandle, 79);
		cout << "P L E A S E   I N S E R T   Y O U R   C A R D";
		ui.fill(4, 20);
		gotoxy(22, 6); SetConsoleTextAttribute(hHandle, 0);
		gotoxy(20, 5);
		cout << "					  ";
		gotoxy(20, 6); cout << "  ";
		gotoxy(56, 6); cout << "  ";
		gotoxy(20, 7);
		cout << "					  ";
		gotoxy(22, 6); SetConsoleTextAttribute(hHandle, 16);
		cout << "					 ";
		gotoxy(3, 22);
		//system("pause>0");
		while (loop < 1){
			for (int x = 0; x < 44; x++){
				for (int i = 0; i <= 21; i++){
					if (21 - x + i < 6)
						continue;
					gotoxy(23, 21 - x + i);
					SetConsoleTextAttribute(hHandle, 159);
					if (i == 0 || i == 20){
						SetConsoleTextAttribute(hHandle, 240);
						cout << "					";
					}
					else{
						SetConsoleTextAttribute(hHandle, 159);
						cout << "					";
						if (i > 1 && (i % 2) == 0 && n < 9){
							gotoxy(25, 21 - x + i);
							cout << name[n];
							n++;
						}
					}
					if (i == 21){
						gotoxy(23, 21 - x + i);
						SetConsoleTextAttribute(hHandle, 64);
						cout << "					";
					}
					if (21 - x + i > 21)
						break;
				}
				if (x == 35){
					SetConsoleTextAttribute(hHandle, 0);
					gotoxy(20, 7);
					cout << "					  ";
				}
				else if (x == 36){
					gotoxy(22, 6); SetConsoleTextAttribute(hHandle, 16);
					cout << "					 ";
				}
				Sleep(50);
				n = 0;
			}
			++loop;
		}
		//system("pause>0");
	}

	void money(int v, int w, int x, int y, int z)
	{
		int loop = 0;
		system("cls");
		system("color 80");
		ui.title();
		gotoxy(18, 1);
		SetConsoleTextAttribute(hHandle, 79);
		cout << "C L A I M   Y O U R   M O N E Y   H E R E";
		ui.fill(4, 20);
		//gotoxy(22, 6); 
		SetConsoleTextAttribute(hHandle, 0);
		gotoxy(12, 5);
		cout << "							  ";
		gotoxy(12, 6); cout << "  ";
		gotoxy(64, 6); cout << "  ";
		gotoxy(12, 7);
		cout << "							  ";
		gotoxy(14, 6); SetConsoleTextAttribute(hHandle, 128);
		cout << "							";
		gotoxy(15, 22); SetConsoleTextAttribute(hHandle, 0);
		cout << "						       ";
		while (loop < z){
			for (int i = 0; i < 26; i++){
				if (i == 0){
					gotoxy(14, 6); SetConsoleTextAttribute(hHandle, 128);
					cout << "							";
					Sleep(50);
					continue;
				}
				for (int j = 0; j <= 10; j++){
					if (6 + i - j < 6)
						continue;
					else if (i > 11 && j == 10){
						gotoxy(16, 6 + i - j);
						SetConsoleTextAttribute(hHandle, 64);
						cout << "					      ";
					}
					else if (i > 15)
						continue;
					else{
						gotoxy(16, 6 + i - j);
						SetConsoleTextAttribute(hHandle, 63);
						if (j == 8)
							cout << " 1 0 0 0				      ";
						else if (j == 1)
							cout << "				      1 0 0 0 ";
						else
							cout << "					      ";
					}
				}
				if (i == 10){
					gotoxy(14, 6); SetConsoleTextAttribute(hHandle, 128);
					cout << "							";
				}
				else if (i >= 11){
					gotoxy(14, 6); SetConsoleTextAttribute(hHandle, 128);
					cout << "							";
					gotoxy(12, 7); SetConsoleTextAttribute(hHandle, 0);
					cout << "							  ";
				}
				Sleep(50);
			}
			++loop;
		}
		loop = 0;
		while (loop < y){
			for (int i = 0; i < 26; i++){
				if (i == 0){
					gotoxy(14, 6); SetConsoleTextAttribute(hHandle, 128);
					cout << "							";
					Sleep(50);
					continue;
				}
				for (int j = 0; j <= 10; j++){
					if (6 + i - j < 6)
						continue;
					else if (i > 11 && j == 10){
						gotoxy(16, 6 + i - j);
						SetConsoleTextAttribute(hHandle, 64);
						cout << "					      ";
					}
					else if (i > 15)
						continue;
					else{
						gotoxy(16, 6 + i - j);
						SetConsoleTextAttribute(hHandle, 96);
						if (j == 8)
							cout << "  5 0 0 				      ";
						else if (j == 1)
							cout << "				       5 0 0  ";
						else
							cout << "					      ";
					}
				}
				if (i == 10){
					gotoxy(14, 6); SetConsoleTextAttribute(hHandle, 128);
					cout << "							";
				}
				else if (i >= 11){
					gotoxy(14, 6); SetConsoleTextAttribute(hHandle, 128);
					cout << "							";
					gotoxy(12, 7); SetConsoleTextAttribute(hHandle, 0);
					cout << "							  ";
				}
				Sleep(50);
			}
			++loop;
		}
		loop = 0;
		while (loop < x){
			for (int i = 0; i < 26; i++){
				if (i == 0){
					gotoxy(14, 6); SetConsoleTextAttribute(hHandle, 128);
					cout << "							";
					Sleep(50);
					continue;
				}
				for (int j = 0; j <= 10; j++){
					if (6 + i - j < 6)
						continue;
					else if (i > 11 && j == 10){
						gotoxy(16, 6 + i - j);
						SetConsoleTextAttribute(hHandle, 64);
						cout << "					      ";
					}
					else if (i > 15)
						continue;
					else{
						gotoxy(16, 6 + i - j);
						SetConsoleTextAttribute(hHandle, 31);
						if (j == 8)
							cout << "  1 0 0 				      ";
						else if (j == 1)
							cout << "				       1 0 0  ";
						else
							cout << "					      ";
					}
				}
				if (i == 10){
					gotoxy(14, 6); SetConsoleTextAttribute(hHandle, 128);
					cout << "							";
				}
				else if (i >= 11){
					gotoxy(14, 6); SetConsoleTextAttribute(hHandle, 128);
					cout << "							";
					gotoxy(12, 7); SetConsoleTextAttribute(hHandle, 0);
					cout << "							  ";
				}
				Sleep(50);
			}
			++loop;
		}
		loop = 0;
		while (loop < w){
			for (int i = 0; i < 26; i++){
				if (i == 0){
					gotoxy(14, 6); SetConsoleTextAttribute(hHandle, 128);
					cout << "							";
					Sleep(50);
					continue;
				}
				for (int j = 0; j <= 10; j++){
					if (6 + i - j < 6)
						continue;
					else if (i > 11 && j == 10){
						gotoxy(16, 6 + i - j);
						SetConsoleTextAttribute(hHandle, 64);
						cout << "					      ";
					}
					else if (i > 15)
						continue;
					else{
						gotoxy(16, 6 + i - j);
						SetConsoleTextAttribute(hHandle, 192);
						if (j == 8)
							cout << "  5 0   				      ";
						else if (j == 1)
							cout << "				         5 0  ";
						else
							cout << "					      ";
					}
				}
				if (i == 10){
					gotoxy(14, 6); SetConsoleTextAttribute(hHandle, 128);
					cout << "							";
				}
				else if (i >= 11){
					gotoxy(14, 6); SetConsoleTextAttribute(hHandle, 128);
					cout << "							";
					gotoxy(12, 7); SetConsoleTextAttribute(hHandle, 0);
					cout << "							  ";
				}
				Sleep(50);
			}
			++loop;
		}
		loop = 0;
		while (loop < v){
			for (int i = 0; i < 26; i++){
				if (i == 0){
					gotoxy(14, 6); SetConsoleTextAttribute(hHandle, 128);
					cout << "							";
					Sleep(50);
					continue;
				}
				for (int j = 0; j <= 10; j++){
					if (6 + i - j < 6)
						continue;
					else if (i > 11 && j == 10){
						gotoxy(16, 6 + i - j);
						SetConsoleTextAttribute(hHandle, 64);
						cout << "					      ";
					}
					else if (i > 15)
						continue;
					else{
						gotoxy(16, 6 + i - j);
						SetConsoleTextAttribute(hHandle, 80);
						if (j == 8)
							cout << "  2 0   				      ";
						else if (j == 1)
							cout << "				         2 0  ";
						else
							cout << "					      ";
					}
				}
				if (i == 10){
					gotoxy(14, 6); SetConsoleTextAttribute(hHandle, 128);
					cout << "							";
				}
				else if (i >= 11){
					gotoxy(14, 6); SetConsoleTextAttribute(hHandle, 128);
					cout << "							";
					gotoxy(12, 7); SetConsoleTextAttribute(hHandle, 0);
					cout << "							  ";
				}
				Sleep(50);
			}
			++loop;
		}
		loop = 0;
		Sleep(100);
	}

}an;

class transaction{
public:

	struct account{
		bool open = false;
		int pin = 0;
		int account_no;
		char Fname[20];
		char Mname[20];
		char Lname[20];
		int balance = 0;
		string last_trans;
		int time[2];
		string am_pm;
		int date[3];
	} acc[70];

	void user(int x)
	{
		int choice;
		char close;
		double temp;
		string user_menu[3] = { "WITHDRAW", "DEPOSIT", "EXIT" };
	user_menu:
		if (acc[x].balance != 0){
			system("cls");
			system("color 80");
			ui.title();
			gotoxy(20, 1);
			cout << "WELCOME BACK ";
			SetConsoleTextAttribute(hHandle, 79);
			cout << acc[x].Fname << " " << acc[x].Mname[0] << ". " << acc[x].Lname;
			ui.fill(4, 15);
			gotoxy(5, 5);
			cout << "CURRENT BALANCE: P " << acc[x].balance << ".00";
			gotoxy(5, 7);
			cout << "LAST TRANSACTION: " << acc[x].last_trans << " [" << month(x) << " " << acc[x].date[1] << " " << acc[x].date[2] << " (";

			if (acc[x].time[0] < 10)
				cout << 0;
			cout << acc[x].time[0] << ":";
			if (acc[x].time[1] < 10)
				cout << 0;
			cout << acc[x].time[1] << " " << acc[x].am_pm;
			cout << ")]";
			gotoxy(5, 16);
			cout << "ACCOUNT NUMBER: ";
			cout << "1000-1000-";
			if (acc[x].account_no < 10)
				cout << "000";
			else if (acc[x].account_no < 100)
				cout << "00";
			else if (acc[x].account_no < 1000)
				cout << 0;
			cout << acc[x].account_no;
			choice = ui.menu(user_menu, 3, 71, 79, 9);
			switch (choice)
			{
			case 0:
				acc[x].last_trans = "WITHDRAW";
				withdraw(x);
				clock(x);
				save();
				//an.money();
				goto user_menu;
				break;
			case 1:
				acc[x].last_trans = "DEPOSIT";
				deposit(x);
				clock(x);
				save();
				goto user_menu;
				break;
			}
		}
	}

	void admin()
	{
		int choice;
		string admin_menu[5] = { "CREATE NEW ACCOUNT", "VIEW ACCOUNTS", "REACTIVATE AN ACCOUNT", "FORMAT ALL ATM ACCOUNTS", "EXIT" };
	admin_menu:
		system("cls");
		system("color 80");
		ui.title();
		gotoxy(26, 1);
		cout << "A D M I N   A C C O U N T";
		ui.fill(4, 11);
		choice = ui.menu(admin_menu, 5, 71, 79, 5);
		system("cls");
		switch (choice)
		{
		case 0:
			create();
			save();
			goto admin_menu;
			break;
		case 1:
			view();
			goto admin_menu;
			break;
		case 2:
			reactivate();
			save();
			goto admin_menu;
			break;
		case 3:
			format();
			load();
			goto admin_menu;
			break;
		}
	}

	void save()
	{
		ofstream file("ATM.txt", ios::out);
		file.flush();
		file << "Total: " << total << endl << endl;
		for (int i = 0; i < total; i++){
			file << "Account # " << i + 1 << endl;
			file << "First Name: " << acc[i].Fname << endl;
			file << "Middle Name: " << acc[i].Mname << endl;
			file << "Last Name: " << acc[i].Lname << endl;
			file << "Status: " << acc[i].open << endl;
			file << "PIN: " << acc[i].pin << endl;
			file << "Account Number: " << acc[i].account_no << endl;
			file << "Balance: " << acc[i].balance << endl;
			file << "Last Transaction: " << acc[i].last_trans << endl;
			file << "Time: ";
			if (acc[i].time[0] < 10)
				file << 0;
			file << acc[i].time[0] << ":";
			if (acc[i].time[1] < 10)
				file << 0;
			file << acc[i].time[1] << " " << acc[i].am_pm << endl;
			file << "Date: " << acc[i].date[0] << "/" << acc[i].date[1] << "/" << acc[i].date[2] << endl;
			file << endl;
		}
		file.close();
	}

	void load()
	{
		fstream file("ATM.txt", ios::in);
		if (!(file)){
			/*system("cls"); system("color 4f");
			gotoxy(5, 5);
			cout << "NOTE: Please create the file \"ATM.txt\" in the same folder of your \"Source.cpp\"!";
			system("pause>0");*/
			ofstream create("ATM.txt", ios::out);
			create.close();
			total = 0;
		}
		else{
			file.ignore(7);
			file >> total;
			if (total == -858993460){
				total = 0;
				file << flush;
			}
			else{
				for (int i = 0; i < total; i++){
					file.ignore(1);
					if (i > 9)
						file.ignore(14);
					else
						file.ignore(13);
					file.ignore(12); file.getline(acc[i].Fname, 20);
					file.ignore(13); file.getline(acc[i].Mname, 20);
					file.ignore(11); file.getline(acc[i].Lname, 20);
					file.ignore(8); file >> acc[i].open;
					file.ignore(5); file >> acc[i].pin;
					file.ignore(16); file >> acc[i].account_no;
					file.ignore(9); file >> acc[i].balance;
					file.ignore(18); file >> acc[i].last_trans;
					file.ignore(6); file >> acc[i].time[0];
					file.ignore(1); file >> acc[i].time[1];
					file.ignore(1); file >> acc[i].am_pm;
					file.ignore(6); file >> acc[i].date[0]; file.ignore(1); file >> acc[i].date[1]; file.ignore(1); file >> acc[i].date[2];
				}
			}
			file.close();
		}
	}

private:

	int total;
	int temp;

	void create()
	{
		int invalid1 = false, invalid2 = false, invalid3 = false;
		system("color 80");
		ui.title();
		gotoxy(20, 1);
		cout << "C R E A T I N G   N E W   A C C O U N T";
		ui.fill(4, 20);
		newline();
		SetConsoleTextAttribute(hHandle, 79); gotoxy(1, 5);
		cout << setw(14) << "FIRST NAME: ";
		SetConsoleTextAttribute(hHandle, 240); cout << "					"; gotoxy(16, 5);
		gets_s(acc[total].Fname);
		SetConsoleTextAttribute(hHandle, 79); gotoxy(1, 7);
		cout << setw(14) << "MIDDLE NAME: ";
		SetConsoleTextAttribute(hHandle, 240); cout << "					"; gotoxy(16, 7);
		gets_s(acc[total].Mname);
		SetConsoleTextAttribute(hHandle, 79); gotoxy(1, 9);
		cout << setw(14) << "LAST NAME: ";
		SetConsoleTextAttribute(hHandle, 240); cout << "					"; gotoxy(16, 9);
		gets_s(acc[total].Lname);
		SetConsoleTextAttribute(hHandle, 79); gotoxy(1, 12);
		cout << setw(14) << "PIN: ";
		//SetConsoleTextAttribute(hHandle, 240); cout << "      ";
		do{
			gotoxy(15, 12);
			SetConsoleTextAttribute(hHandle, 240); cout << "      ";
			gotoxy(16, 12);
			cin >> acc[total].pin;
			if (acc[total].pin > 9999 || acc[total].pin < 1){
				gotoxy(5, 14);
				SetConsoleTextAttribute(hHandle, 74);
				cout << "PIN must have 4 digits. Please try again!";
				invalid1 = true;
			}
			else{
				invalid1 = false;
				for (int i = 0; i < total; i++){
					if (acc[total].pin == acc[i].pin){
						invalid2 = true;
						break;
					}
					else
						invalid2 = false;
				}
				if (invalid2){
					gotoxy(5, 14);
					SetConsoleTextAttribute(hHandle, 74);
					cout << "PIN is already taken. Please try again!  ";
				}
			}
		} while (invalid1 || invalid2);
		gotoxy(5, 14);
		SetConsoleTextAttribute(hHandle, 74);
		cout << "Initial Deposit must be at least P 1,000.00";
		gotoxy(6, 16);
		SetConsoleTextAttribute(hHandle, 79);
		cout << "Enter Initial Deposit: P ";
		do{
			gotoxy(31, 16);
			SetConsoleTextAttribute(hHandle, 240); cout << "			";
			gotoxy(32, 16);
			cin >> acc[total].balance;
			if (acc[total].balance < 1000 || acc[total].balance % 50 != 0 && acc[total].balance % 50 != 20 && acc[total].balance % 50 != 40){
				gotoxy(5, 18);
				SetConsoleTextAttribute(hHandle, 74);
				cout << "Please try again!";
			}
		} while (acc[total].balance < 1000 || acc[total].balance % 50 != 0 && acc[total].balance % 50 != 20 && acc[total].balance % 50 != 40);
		acc[total].open = true;
		acc[total].last_trans = "DEPOSIT";
		clock(total);
		do{
			acc[total].account_no = rand() % 1001;
			for (int i = 0; i < total; i++){
				if (acc[i].account_no == acc[total].account_no){
					invalid3 = true;
					break;
				}
				else
					invalid3 = false;
			}
		} while (invalid3);
		gotoxy(5, 18);
		SetConsoleTextAttribute(hHandle, 74);
		cout << "Account is successfully created!";
		gotoxy(5, 20);
		cout << "Your Account Number will be: ";
		SetConsoleTextAttribute(hHandle, 79);
		cout << "1000-1000-";
		if (acc[total].account_no < 10)
			cout << "000";
		else if (acc[total].account_no < 100)
			cout << "00";
		else if (acc[total].account_no < 1000)
			cout << 0;
		cout << acc[total].account_no;
		system("pause>0");
		++total;
	}

	void reactivate()
	{
		int pin_temp, bal_temp;
		bool invalid = false;
		bool acc_exist = false;
	react:
		system("cls");
		system("color 80");
		ui.title();
		gotoxy(20, 1);
		cout << "A C C O U N T   R E A C T I V A T I O N";
		pin_temp = ui.pin_input();
		if (pin_temp == 0){
			gotoxy(28, 14);
			SetConsoleTextAttribute(hHandle, 140);
			cout << "Account doesn't exist!"; system("pause>0");
			system("pause>0");
			goto react;
		}
		else{
			for (int i = 0; i < 30; i++){
				if (pin_temp == acc[i].pin){
					if (acc[i].open){
						gotoxy(26, 14);
						SetConsoleTextAttribute(hHandle, 140);
						cout << "Account is already active!"; system("pause>0");
						system("pause>0");
					}
					else{
						system("cls");
						user_info(i);
					}
					invalid = false;
					break;
				}
				else
					invalid = true;
			}
			if (invalid){
				gotoxy(28, 14);
				SetConsoleTextAttribute(hHandle, 140);
				cout << "Account doesn't exist!"; system("pause>0");
				system("pause>0");
				goto react;
			}
		}
	}

	void view(){
		system("color 47");
		cout << setprecision(2) << setiosflags(ios::fixed);
		ui.title();
		gotoxy(10, 1);
		cout << "S C H U B E R T   I N T E R N A T I O N A L   A C C O U N T S\n\n";
		gotoxy(0, 3);
		SetConsoleTextAttribute(hHandle, 63);
		cout << "										";
		gotoxy(6, 3); cout << "PIN";
		gotoxy(24, 3); cout << "NAME";
		gotoxy(46, 3); cout << "BALANCE";
		gotoxy(64, 3); cout << "STATUS";
		cout << endl << endl;
		for (int i = 0; i < total; i++){
			if (i % 2 == 0){
				gotoxy(0, 4 + i);
				SetConsoleTextAttribute(hHandle, 112);
				cout << "										";
			}
			else{
				gotoxy(0, 4 + i);
				SetConsoleTextAttribute(hHandle, 128);
				cout << "										";
			}

			gotoxy(6, 4 + i);
			if (acc[i].pin < 10)
				cout << "000" << acc[i].pin;
			else if (acc[i].pin < 100)
				cout << "00" << acc[i].pin;
			else if (acc[i].pin < 1000)
				cout << 0 << acc[i].pin;
			else
				cout << acc[i].pin;
			gotoxy(18, 4 + i); cout << acc[i].Fname << " " << acc[i].Mname[0] << ". " << acc[i].Lname;
			gotoxy(44, 4 + i); cout << "P " << setw(7) << acc[i].balance << ".00";
			gotoxy(65, 4 + i);
			if (i % 2 == 0){
				if (acc[i].open){
					SetConsoleTextAttribute(hHandle, 121);
					cout << "OPEN";
				}
				else{
					SetConsoleTextAttribute(hHandle, 124);
					cout << "CLOSED";
				}
			}
			else{
				if (acc[i].open){
					SetConsoleTextAttribute(hHandle, 137);
					cout << "OPEN";
				}
				else{
					SetConsoleTextAttribute(hHandle, 140);
					cout << "CLOSED";
				}
			}
		}
		SetConsoleTextAttribute(hHandle, 112);
		system("pause>0");
	}

	void format()
	{
		int fmt, pin_enter;
		system("color 80");
		ui.title();
		gotoxy(18, 1);
		cout << "F O R M A T T I N G   A T M   A C C O U N T S";
		ui.fill(4, 20);
		SetConsoleTextAttribute(hHandle, 71);
		gotoxy(5, 5);
		cout << "WARNING: Formating all ATM accounts will clear all user records.";
		gotoxy(5, 7);
		cout << "THIS IS AN IRREVERSIBLE ACTION!";
		fmt = ui.yn(9, 79, 71);
		if (!(fmt)){
			gotoxy(5, 11);
			cout << "PLEASE ENTER THE MASTER PIN: ";
			SetConsoleTextAttribute(hHandle, 240); cout << "      ";
			gotoxy(35, 11);
			cin >> pin_enter;
			SetConsoleTextAttribute(hHandle, 79);
			if (pin_enter == 1234){
				ofstream file("ATM.txt", ios::out);
				file.flush();
				file.close();
				total = 0;
				load();
				gotoxy(5, 13);
				cout << "All Accounts are successfully deleted!";
				system("pause > 0");
			}
			else{
				gotoxy(5, 13);
				cout << "INVALID MASTER PIN!";
				system("pause > 0");
			}
		}
		else{
			gotoxy(5, 11);
			SetConsoleTextAttribute(hHandle, 79);
			cout << "Formatting cancelled...";
			system("pause > 0");
		}
	}

	void user_info(int x)
	{
		system("color 80");
		ui.title();
		gotoxy(23, 1);
		cout << "U S E R   I N F O R M A T I O N";
		ui.fill(4, 20);
		SetConsoleTextAttribute(hHandle, 71);
		gotoxy(1, 5);
		cout << setw(14) << "FIRST NAME: " << acc[x].Fname;
		gotoxy(1, 7);
		cout << setw(14) << "MIDDLE NAME: " << acc[x].Mname;
		gotoxy(1, 9);
		cout << setw(14) << "LAST NAME: " << acc[x].Lname;
		gotoxy(5, 12);
		cout << "To reactivate this account, you must deposit at least P 1,000.00.";
		gotoxy(6, 14);
		//SetConsoleTextAttribute(hHandle, 79);
		cout << "Enter Initial Deposit: P ";
		do{
			gotoxy(31, 14);
			SetConsoleTextAttribute(hHandle, 240); cout << "			";
			gotoxy(32, 14);
			cin >> acc[x].balance;
			if (acc[x].balance < 1000){
				gotoxy(5, 16);
				SetConsoleTextAttribute(hHandle, 73);
				cout << "Please try again!";
			}
		} while (acc[x].balance < 1000);
		acc[x].open = true;
		acc[x].last_trans = "DEPOSIT";
		clock(x);
		gotoxy(5, 16);
		SetConsoleTextAttribute(hHandle, 74);
		cout << "Account is successfully created!"; system("pause>0");
	}

	void withdraw(int x)
	{
		bool invalid = false;
		int close, m1000, m500, m100, m50, m20, r1000, r500, r100, r50, r20;
	w_start:
		system("cls");
		system("color 80");
		ui.title();
		gotoxy(30, 1);
		cout << "W I T H D R A W";
		ui.fill(4, 20);
		SetConsoleTextAttribute(hHandle, 71);
		gotoxy(5, 5);
		cout << "CURRENT BALANCE: P " << acc[x].balance << ".00";
		gotoxy(5, 7);
		cout << "HOW MUCH WOULD YOU LIKE TO WITHDRAW?";
		gotoxy(6, 9);
		cout << "Enter amount to withdraw: P ";
		do{
			gotoxy(34, 9);
			SetConsoleTextAttribute(hHandle, 240); cout << "			";
			gotoxy(35, 9);
			cin >> temp;
			r1000 = temp % 1000; m1000 = temp / 1000;
			r500 = r1000 % 500; m500 = r1000 / 500;
			r100 = r500 % 100;  m100 = r500 / 100;
			if (r100 % 20 < 10){
				r20 = r100 % 20;  m20 = r100 / 20;
				r50 = 0; m50 = 0;
			}
			else{
				r50 = r100 % 50;  m50 = r100 / 50;
				r20 = r50 % 20;  m20 = r50 / 20;
			}
			SetConsoleTextAttribute(hHandle, 74);
			if (acc[x].balance - temp == 0){
				gotoxy(5, 11);
				cout << "There will be no balance left in your account.";
				gotoxy(5, 13);
				cout << "This will lead to the closure of your account.";
				close = ui.yn(15, 71, 79);
				if (!(close)){
					acc[x].balance -= temp;
					gotoxy(5, 17);
					cout << "Your transaction is successful! Your account will now close.";
					system("pause > 0");
					acc[x].open = false;
				}
				else{
					gotoxy(5, 17);
					cout << "Your transaction is cancelled!";
					system("pause>0");
				}
				invalid = false;
			}
			else if (acc[x].balance - temp < 0 || temp < 20){
				gotoxy(5, 11);
				cout << "Invalid input! Please try again.";
				system("pause>0");
				invalid = true;
			}
			else{
				acc[x].balance -= temp - r20;
				gotoxy(5, 11);
				cout << "Your transaction is successful!";
				if (r20 != 0){
					gotoxy(5, 13);
					cout << "P "<< r20 << " cannot be withdrawn from ATM!";
				}
				system("pause>0");
				invalid = false;
			}
		} while (invalid);
		temp = 0;
		//cout << m20 << " " << m50 << " " << m100 << " " << m500 << " " << m1000; system("pause>0");
		an.money(m20, m50, m100, m500, m1000);
	}

	void deposit(int x)
	{
	d_start:
		system("cls");
		system("color 80");
		ui.title();
		gotoxy(30, 1);
		cout << "D E P O S I T";
		ui.fill(4, 20);
		SetConsoleTextAttribute(hHandle, 71);
		gotoxy(5, 5);
		cout << "CURRENT BALANCE: P " << acc[x].balance << ".00";
		gotoxy(5, 7);
		cout << "HOW MUCH WOULD YOU LIKE TO DEPOSIT?";
		gotoxy(6, 9);
		cout << "Enter amount to deposit: P ";
		take:
		gotoxy(34, 9);
		SetConsoleTextAttribute(hHandle, 240); cout << "			";
		gotoxy(35, 9);
		cin >> temp;
		SetConsoleTextAttribute(hHandle, 74);
		gotoxy(5, 11);
		if (temp % 20 != 0){
			cout << "This ATM do not accept coins.";
			goto take;
		}
		else{
			acc[x].balance += temp;
			cout << "Your transaction is successful!";
		}
		system("pause>0");
		temp = 0;
	}

	void clock(int x)
	{
		SYSTEMTIME t;
		GetLocalTime(&t);
		acc[x].time[1] = t.wMinute;
		if (t.wHour < 12){
			if (t.wHour == 0)
				acc[x].time[0] = 12;
			else
				acc[x].time[0] = t.wHour;
			acc[x].am_pm = "AM";
		}
		else{
			if (t.wHour == 12)
				acc[x].time[0] = 12;
			else
				acc[x].time[0] = t.wHour - 12;
			acc[x].am_pm = "PM";
		}
		acc[x].date[0] = t.wMonth;
		acc[x].date[1] = t.wDay;
		acc[x].date[2] = t.wYear;
	}

	string month(int x)
	{
		string name;
		switch (acc[x].date[0])
		{
		case 1: name = "JANUARY"; break;
		case 2: name = "FEBRUARY"; break;
		case 3: name = "MARCH"; break;
		case 4: name = "APRIL"; break;
		case 5: name = "MAY"; break;
		case 6: name = "JUNE"; break;
		case 7: name = "JULY"; break;
		case 8: name = "AUGUST"; break;
		case 9: name = "SEPTEMBER"; break;
		case 10: name = "OCTOBER"; break;
		case 11: name = "NOVEMBER"; break;
		case 12: name = "DECEMBER"; break;
		}
		return name;
	}

}atm;

