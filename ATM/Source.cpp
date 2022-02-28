#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <conio.h>
#include <Windows.h>
#include "Header.h"

int boot();

void user_menu();

void admin_menu();

int main()
{
	//an.money(1,1,1);
	atm.load();
	srand(time(NULL));
	cout << setprecision(2) << setiosflags(ios::fixed);
boot_menu:
	//system("cls");
	switch (boot()){
	case 0:
		admin_menu();
		goto boot_menu;
	case 1:
		user_menu();
		goto boot_menu;
	}
	return 0;
}

int boot()
{
	int loop = 0;
	system("color 0a");
	system("cls");
	/*while (loop < 4444){
		cout << rand();
		++loop;
	}
	Sleep(300);
	system("cls");*/
	string main_menu[3] = { "ADMINISTRATOR", "USER", "EXIT" };
	//ui.title();
	//ui.fill(6, 7);
	SetConsoleTextAttribute(hHandle, 10);
	gotoxy(29, 2);
	cout << "B O O T   M E N U";
	return ui.menu(main_menu, 3, 10, 10, 7);
}

void user_menu()
{
	int pin_enter;
	bool acc_exist = false;
start_menu:
	system("cls"); 
	an.card();
	system("cls");
	system("color 80");
	ui.title();
	gotoxy(12, 1);
	cout << "S C H U B E R T   I N T E R N A T I O N A L   B A N K\n\n";
	pin_enter = ui.pin_input();
	if (pin_enter == 0){
		SetConsoleTextAttribute(hHandle, 140);
		gotoxy(30, 14);
		cout << "ATM is now closing!"; system("pause > 0");
		//exit(1);
	}
	else{
		for (int i = 0; i < 30; i++){
			if (pin_enter == atm.acc[i].pin){
				if (atm.acc[i].open){
					acc_exist = true;
					atm.user(i);
				}
				else{
					SetConsoleTextAttribute(hHandle, 140);
					gotoxy(24, 14);
					cout << "Sorry! Your account is closed!";
					gotoxy(3, 16);
					cout << "Please visit Schubert International Bank for reactivation of your account.";
					system("pause > 0");
				}
				goto start_menu;
			}
			else
				acc_exist = false;
		}
		if (!(acc_exist)){
			SetConsoleTextAttribute(hHandle, 140);
			gotoxy(19, 14);
			cout << "Account doesn't exist. Please try again.";
			system("pause>0"); 
			goto start_menu;
		}
	}
}

void admin_menu()
{
	system("cls");
	system("color 80");
	ui.title();
	gotoxy(27, 1);
	cout << "A D M I N I S T R A T O R";
	if (ui.pin_input() == 1234) // admin_pass
		atm.admin();
}