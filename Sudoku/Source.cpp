#include <iostream>
#include <Windows.h>
#include <conio.h>

HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

using namespace std;

int sdk[9][9] ={ 
		{ 5, 3, 0, 0, 7, 0, 0, 0, 0 },
		{ 6, 0, 0, 1, 9, 5, 0, 0, 0 },
		{ 0, 9, 8, 0, 0, 0, 0, 6, 0 },
		{ 8, 0, 0, 0, 6, 0, 0, 0, 3 },
		{ 4, 0, 0, 8, 0, 3, 0, 0, 1 },
		{ 7, 0, 0, 0, 2, 0, 0, 0, 6 },
		{ 0, 6, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 4, 1, 9, 0, 0, 5 },
		{ 0, 0, 0, 0, 8, 0, 0, 7, 9 } },
		key[9][9] = {
				{ 5, 3, 4, 6, 7, 8, 9, 1, 2 },
				{ 6, 7, 2, 1, 9, 5, 3, 4, 8 },
				{ 1, 9, 8, 3, 4, 2, 5, 6, 7 },
				{ 8, 5, 9, 7, 6, 1, 4, 2, 3 },
				{ 4, 2, 6, 8, 5, 3, 7, 9, 1 },
				{ 7, 1, 3, 9, 2, 4, 8, 5, 6 },
				{ 9, 6, 1, 5, 3, 7, 2, 8, 4 },
				{ 2, 8, 7, 4, 1, 9, 6, 3, 5 },
				{ 3, 4, 5, 2, 8, 6, 1, 7, 9 } };
int x = 0, y = 0;
bool k[9][9], check[9][9], win = false;

void truth();
void display();
void select(int);
void valid();
bool valid2();

void gotoxy(int x, int y)
{
	CursorPosition = { x, y };
	SetConsoleCursorPosition(handle, CursorPosition);
}

void color(int x, int y)
{
	SetConsoleTextAttribute(handle, (x * 16 + y));
}

void bg(){
	for (int i = 0; i < 18; i++){
		for (int a = 0; a < 9; a++){
			if (i < 12 && i > 6){
				if (a < 6 && a > 2)
					color(8, 0);
				else
					color(7, 0);
			}
			else
				if (a < 6 && a > 2)
					color(7, 0);
				else
					color(8, 0);
			gotoxy(25 + a*3, 3 + i);
			cout << "   ";
		}
	}
}

int main()
{
	int in;
	truth();
	//bg();
	display();
	while (k[y][x]){
		x++;
		if (x == 10){
			x = 0;
			y++;
		}
	}
	gotoxy(26 + x + (x * 2), 4 + (y * 2));
	cout << '_';
	gotoxy(26 + x + (x * 2), 4 + (y * 2));
	while (true){
		in = _getch();
		if (in == 13){
			system("cls");
			valid();
			display();
			for (int row = 0; row < 9; row++){
				for (int col = 0; col < 9; col++){
					if (check[row][col])
						win = true;
					else{
						win = false;
						break;
					}
				}
				if (!(win))
					break;
			}
			if (win && valid2()){
				gotoxy(16, 23);
				color(0, 11);
				cout << "C O N G R A T U L A T I O N S !  Y O U   W O N !";
				break;
			}
		}
		else if (in < 60 && in > 48){
			sdk[y][x] = in - 48;
			cout << in - 48;
		}
		else if (in == 72 || in == 75 || in == 77 || in == 80){
			if (sdk[y][x] == 0){
				gotoxy(26 + x + (x * 2), 4 + (y * 2));
				color(0, 4);
				cout << '*';
				color(0, 11);
			}
			select(in);
			if (sdk[y][x] == 0){
				gotoxy(26 + x + (x * 2), 4 + (y * 2));
				cout << '_';
			}
		}
		gotoxy(26 + x + (x * 2), 4 + (y * 2));
	}
	system("pause>0");
	return 0;
}

void truth()
{
	for (int row = 0; row < 9; row++){
		for (int col = 0; col < 9; col++){
			if (sdk[row][col] == 0){
				k[row][col] = false;
				check[row][col] = false;
			}
			else{
				k[row][col] = true;
				check[row][col] = true;
			}
		}
	}
}

void display()
{
	int clr;
	gotoxy(33, 1);
	color(0, 11);
	cout << "S U D O K U";
	for (int row = 0; row < 9; row++){
		gotoxy(25, 4 + row * 2);
		for (int col = 0; col < 9; col++){
				{
					if (row < 3 || row >5){
						if (col < 6 && col > 2)
							clr = 9;
						else
							clr = 3;
					}
					else{
						if (col < 6 && col > 2)
							clr = 3;
						else
							clr = 9;
					}
				}

			if (sdk[row][col] == 0){
				//color(0, 15);
				//cout << " ";
				color(0, 4);
				cout << " * ";
				//color(0, 15);
				//cout << " ";
			}
			else{
				if (k[row][col])
					color(0, clr);
				else{
					if (check[row][col])
						color(0, 10);
					else
						color(0, 12);
				}
				cout << " " << sdk[row][col] << " ";
			}
		}
		/*if (row == 2 || row == 6){
			gotoxy(25, 4 + row * 2 + 1);
			for (int i = 0; i < 9; i++)
				cout << "   ";
		}*/
	}
	color(0, 11);
}

void select(int sel)
{
		switch (sel){
		case 75:
			do{
				x--;
			} while (k[y][x]);
			break;
		case 77:
			do{
				x++;
			} while (k[y][x]);
			break;
		case 72:
			do{
				y--;
			} while (k[y][x]);
			break;
		case 80:
			do{
				y++;
			} while (k[y][x]);
			break;
		}
		
		if (x >= 9){
			do{
				x--;
			} while (k[y][x]);
		}
		if (x <= -1){
			do{
				x++;
			} while (k[y][x]);
		}
		if (y >= 9){
			do{
				y--;
			} while (k[y][x]);
		}
		if (y <= -1){
			do{
				y++;
			} while (k[y][x]);
		}
	}

void valid()
{
	for (int row = 0; row < 9; row++){
		for (int col = 0; col < 9; col++){
			if (!(k[row][col])){
				for (int i = 0; i < 9; i++){
					if (i == col)
						continue;
					if (sdk[row][col] == sdk[row][i]){
						check[row][col] = false;
						break;
					}
					else
						check[row][col] = true;
				}
				if (check[row][col] == false)
					break;
				for (int i = 0; i < 9; i++){
					if (i == row)
						continue;
					if (sdk[row][col] == sdk[i][col]){
						check[row][col] = false;
						break;
					}
					else
						check[row][col] = true;
				}
			}
		}
	}
}

bool valid2()
{
	for (int row = 0; row < 3; row++)
		for (int col = 0; col < 3; col++)
			for (int rk = 0; rk < 3; rk++)
				for (int ck = 0; ck < 3; ck++)
					for (int rv = 0; rv < 3; rv++)
						for (int cv = 0; cv < 3; cv++){
		if (rk == rv && ck == cv)
			continue;
		else
			if (sdk[rk + (row * 3)][ck + (col * 3)] == sdk[rv + (row * 3)][cv + (col * 3)])
				return false;

						}
	return true;
}