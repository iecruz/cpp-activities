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
#include "Contact.h"

using namespace std;

int sel = 0;

void output();

int main()
{
	string menu[5] = { "ADD CONTACTS", "EDIT CONTACTS", "VIEW CONTACTS", "DELETE CONTACTS", "EXIT" };
	while (true){
		system("cls");
		gotoXY(8, 1);
		printf("P R O J E C T   C O N T A C T");
		
		for (int i = 0; i < 10; i+=2){
			if (sel*2 == i){
				gotoXY(3, i + 4);
				cout << ">> " << menu[i/2];
			}
			else{
				gotoXY(6, i + 4);
				cout << menu[i/2];
			}
		}
		//_getch();
		while (true){
			if (GetAsyncKeyState(VK_UP) != 0){
				sel -= 1;
				if (sel == -1)
					sel = 4;
			}
			else if (GetAsyncKeyState(VK_DOWN) != 0)
			{
				sel += 1;
				if (sel == 5)
					sel = 0;
			}
			else if (GetAsyncKeyState(VK_RETURN) != 0)
			{
				system("cls");
				output();
			}
			break;
			Sleep(100);
		}
	}
	return 0;
}

void output()
{
	switch (sel)
	{
	case 0:
		add();
		system("pause > 0");
		break;
	case 4:
		exit(1);
	}
}