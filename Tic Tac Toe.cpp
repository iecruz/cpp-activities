#include <iostream>
#include <conio.h>
#include <Windows.h>

using namespace std;

char t[3][3], win;
int x = 0, y = 0, scoreX = 0, scoreY = 0, rnd = 1, ctr = 0;

void load();
void display();
void move();
void initiate();
void UI();
void turn();
int check();

void gotoXY(int x, int y)
{
	COORD Position;
	Position = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Position);
}

void color(int fore, int back)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (back * 16 + fore));
}

int main()
{
	load();
	char repeat;
	do{
		system("color 10");
		x = 0; y = 0;
		system("cls");
		initiate();
		display();
		UI();
		while (ctr < 9){
			turn();
			system("pause>0");
			color(14, 4);
			gotoXY(32 + (x * 4 + 1), 5 + (y * 3 + 1));
			cout << " ";
			gotoXY(32 + (x * 4 + 3), 5 + (y * 3 + 1));
			cout << " ";
			move();
			gotoXY(32 + (x * 4 + 1), 5 + (y * 3 + 1));
			cout << '[';
			gotoXY(32 + (x * 4 + 3), 5 + (y * 3 + 1));
			cout << ']';
			gotoXY(32 + (x * 4 + 2), 5 + (y * 3 + 1));
			if (GetAsyncKeyState(VK_SPACE) != 0){
				if (t[x][y] == NULL){
					if ((ctr+rnd) % 2){
						t[x][y] = 'X';
						color(11, 4);
					}
					else{
						t[x][y] = 'O';
						color(13, 4);
					}
					cout << t[x][y];
					++ctr;
				}
				gotoXY(25, 18);
				color(14, 1);
				if (check() == 1){
					win = 'X';
					++scoreX;
					break;
				}
				else if (check() == -1){
					win = 'O';
					++scoreY;
					break;
				}
			}
		}
		color(14, 4);
		for (int row = 0; row < 5; row++)
			for (int col = 0; col < 26; col++){
			gotoXY(27 + col, 17 + row);
			cout << ' ';
			}
		if (!(check())){
			gotoXY(35, 18);
			cout << "D R A W !";
		}
		else{
			gotoXY(33, 18);
			cout << win << "   W I N S !";
		}
		gotoXY(29, 20);
		cout << "Continue (Y or N) ?: "; cin >> repeat; ctr = 0; ++rnd;
	} while (repeat == 'Y' || repeat == 'y');
	return 0;
}

void display()
{
	int line = 0, row=0, col=0;
	color(14, 4);
	//gotoXY(32, 4);
	//cout << "_______________";
	gotoXY(30, 4);
	//cout << "   ___ ___ ___   ";
	cout << "                 ";
	//color(13, 1);
	for (; row < 3; row++){
		gotoXY(30, 5 + (row * 3));
		cout << "      |   |      ";
		gotoXY(30, 5 + (row * 3 + 1));
		//cout << "  |";
		cout << "   ";
		for (col = 0; col < 3; col++){
			cout << " " << t[row][col] << " ";
			if (col < 2)
				cout << "|";
		}
		//cout << "|  ";
		cout << "   ";
		gotoXY(30, 5 + (row * 3 + 2));
		//cout << "  |___|___|___|  ";
		if (row < 2)
			cout << "   ___|___|___   ";
		else
			cout << "      |   |      ";
	}
	gotoXY(30, 14);
	cout << "		       ";
}

void UI()
{
	color(14, 4);
	gotoXY(0, 0);
	for (int row = 0; row < 3; row++)
		for (int col = 0; col < 80; col++)
					cout << ' ';
	gotoXY(28, 1);
	cout << "T I C   T A C   T O E";

	color(14, 2);
	for (int row = 0; row < 3; row++)
		for (int col = 0; col < 11; col++){
		gotoXY(7 + col, 5 + row);
		cout << ' ';
		}
	gotoXY(9, 6);
	cout << "ROUND " << rnd;

	color(14, 2);
	for (int row = 0; row < 9; row++)
		for (int col = 0; col < 16; col++){
		gotoXY(56 + col,5 + row);
		cout << ' ';
		}
	gotoXY(58, 7);
	cout << "SCOREEBOARD:";
	gotoXY(60, 9);
	cout << "X: " << scoreX;
	gotoXY(60, 11);
	cout << "O: " << scoreY;
}

void turn()
{
	if ((ctr + rnd) % 2)
		color(15, 3);
	else
		color(15, 5);
	for (int row = 0; row < 3; row++)
		for (int col = 0; col < 15; col++){
		gotoXY(7 + col, 10 + row);
		cout << ' ';
		}
	gotoXY(9, 11);
	if ((ctr + rnd) % 2)
		cout << "IT'S X TURN!";
	else
		cout << "IT'S O TURN!";
	gotoXY(32 + (x * 4 + 2), 5 + (y * 3 + 1));
}

void move()
{
	if (GetAsyncKeyState(VK_UP) != 0)
		--y;
	if (GetAsyncKeyState(VK_DOWN) != 0)
		++y;
	if (GetAsyncKeyState(VK_LEFT) != 0)
		--x;
	if (GetAsyncKeyState(VK_RIGHT) != 0)
		++x;

	if (y == -1)
		++y;
	if (x == -1)
		++x;
	if (y == 3)
		--y;
	if (x == 3)
		--x;
}

void initiate()
{
	for (int row = 0; row < 3; row++){
		for (int col = 0; col < 3; col++){
			t[row][col] = NULL;
		}
	}
}

int check()
{
	int i = 0;
	while (i < 3){
		if (t[i][1] == t[i][2] && t[i][0] == t[i][1] && t[i][1] != NULL){
			if (t[i][1] == 'X')
				return 1;
			else
				return -1;
			break;
		}
		if (t[1][i] == t[2][i] && t[0][i] == t[1][i] && t[1][i] != NULL){
			if (t[1][i] == 'X')
				return 1;
			else
				return -1;
			break;
		}
		++i;
	}
	if (t[0][0] == t[1][1] && t[0][0] == t[2][2] && t[1][1] != NULL){
		if (t[1][1] == 'X')
			return 1;
		else
			return -1;
	}
	if (t[0][2] == t[1][1] && t[0][2] == t[2][0] && t[1][1] != NULL){
		if (t[1][1] == 'X')
			return 1;
		else
			return -1;
	}
	return 0;
}

void load()
{
	gotoXY(31, 7);
	cout << "W E L C O M E";
	gotoXY(36, 9);
	cout << "T O";
	gotoXY(27, 11);
	color(12, 0); cout << "T I C   ";
	color(10, 0); cout << "T A C   ";
	color(9, 0); cout << "T O E";
	color(0, 8);
	for (int i = 0; i < 40; i++){
		gotoXY(18 + i, 16);
		cout << ' ';
	}
	color(0, 1);
	for (int i = 0; i < 40; i++){
		gotoXY(18 + i, 16);
		cout << ' ';
		if (i == 18)
			Sleep(900);
		else if (i == 29)
			Sleep(1500);
		else
			Sleep(100);
	}
	gotoXY(22, 18);
	color(7, 0);
	system("pause");
}