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

using namespace std;

//Functions

int Len(char *x)
{
	int ctr = 0;
	while (*x++ != NULL)
		++ctr;
	return ctr;
}

int Cmp(char *x, char *y)
{
	int l(Len(x));
	const int lY(Len(y)), lX(Len(x));
	if (l > Len(y))
		l = Len(y);
	if (lX > lY)
		return 1;
	else if (lX < lY)
		return -1;
	else{
		for (int i = 0; i < l; i++, *x++, *y++){
			if (*x > *y){
				return 1;
				break;
			}
			else if (*x < *y){
				return -1;
				break;
			}
			else
				continue;
		}
		return 0;
	}
}

char *Rev(char *x)
{
	char *y, *z;
	int len = Len(x);
	y = new char[160];
	z = y;
	while (*++x != NULL);
	*--x;
	for (int i = 0; i < len; *y++, *x--, i++)
		*y = *x;
	*y = NULL;
	y = z;
	return y;
}

char *lwrC(char *x)
{
	char *y, *z;
	const int len(Len(x));
	y = new char[160];
	z = y;
	for (int i = 0; i < len; i++, *x++, *y++){
		if ((int)*x >= 65 && (int)*x <= 90)
			*y = (int)*x + 32;
		else
			*y = *x;
	}
	*y = NULL;
	y = z;
	return y;
}

char *uprC(char *x)
{
	const int len(Len(x));
	char *y, *z;
	y = new char[160];
	z = y;
	for (int i = 0; i < len; i++, *x++, *y++){
		if ((int)*x >= 97 && (int)*x <= 122)
			*y = (int)*x - 32;
		else
			*y = *x;
	}
	*y = NULL;
	y = z;
	return y;
}

void Cpy(char *x, char *y)
{
	while (*x++ = *y++);
}

void Cat(char *x, char *y)
{
	while (*x != NULL)
		*++x;
	while (*x++ = *y++);

}

//Programs

int wdCtr(char *x)
{
	int ctr = 0;
	const int len(Len(x));
	for (int i = 0; i < len; i++, *x++){
		if (!((int)*x == 32 || *x == NULL)){
			++ctr;
			break;
		}
	}
	for (int i = 0; i < len; i++, *x++){
		if ((int)*x == 32 && (int)*(x + 1) != 32)
			++ctr;
	}
	return ctr;
}

string Ins(char *x, char *y, int pos)
{
	string z;
	char n = NULL;
	const int lY = Len(y), lX(Len(x));
	for (int i = 0; i < pos; i++, *x++)
		z += *x;
	for (int i = 0; i < lY; i++, *y++)
		z += *y;
	for (int i = 0; i < lX - pos; i++, *x++)
		z += *x;
	z += n;
	return z;
}

char *tCas(char *x)
{
	char *z;
	z = x;
	const int len(Len(x));
	for (int i = 0; i < len; i++, *x++){
		if ((int)*x >= 65 && (int)*x <= 90)
			*x = ((int)*x + 32);
	}
	x = z;
	if ((int)*x >= 97 && (int)*x <= 122)
		*x = ((int)*x - 32);
	*x++;
	for (int i = 1; i < len; i++, *x++){
		if ((int)*(x - 1) == 32)
			if ((int)*x != 32)
				*x = (int)*x - 32;
			/* if ((int)*(x + 1) != 32)
				*(x + 1) = (int)*(x + 1) - 32; */
	}
	x = z;
	return x;
}

char *tC(char *x)
{
	char *s;
	const int lX(Len(x));
	s = x;
	for (int i = 0; i < lX; i++, *x++){
		if ((int)*x >= 65 && (int)*x <= 90)
			*x = (int)*x + 32;
		else if ((int)*x >= 97 && (int)*x <= 122)
			*x = (int)*x - 32;
	}
	*x = NULL;
	x = s;
	return x;
}

int Plndrm(char *x)
{
	const int len(Len(x));
	char *s, *sS, *y, *z;
	s = new char[160];
	int a = 0;
	sS = s;
	while (a < len){
		if (*x == 32){
			*x++;
			continue;
		}
		else
			*s = *x;
		*s++; *x++; a++;
	}
	*s = NULL;
	s = sS;
	z = (uprC(s));
	y = Rev(z);
	for (int i = 0; i < len; i++, *y++, *z++){
		if (*z != *y){
			return 0;
			break;
		}
		else if (i + 1 == len)
			return 1;
	}
}

void VC(char *x)
{
	int vwl = 0, cnsnt = 0;
	const int len = Len(x);
	for (int i = 0; i < len; i++, *x++){
		if ((int)*x >= 65 && (int)*x <= 90 || (int)*x >= 97 && (int)*x <= 122){
			if ((int)*x == 65 || (int)*x == 69 || (int)*x == 73 || (int)*x == 79 || (int)*x == 85)
				++vwl;
			if ((int)*x == 97 || (int)*x == 101 || (int)*x == 105 || (int)*x == 111 || (int)*x == 117)
				++vwl;
			else
				++cnsnt;
		}
	}
	cout << "Vowel: " << vwl << "     " << "Consonant: " << cnsnt;
}

void Frqncy(char *x)
{
	int lC[26], uC[26], num[10], ctr = 0, space = 0;
	char c1, c2, c3;
	const int len(Len(x));
	for (int i = 0; i < 26; i++){
		lC[i] = 0;
		uC[i] = 0;
	}
	for (int i = 0; i < 10; i++){
		num[i] = 0;
	}
	for (int b = 0; b < len; b++, *x++){
		if ((int)*x >= 65 && (int)*x <= 90 || (int)*x >= 97 && (int)*x <= 122){
			for (int a = 0; a < 26; a++){
				if ((int)*x == 65 + a)
					uC[a] += 1;
				else if ((int)*x == 97 + a)
					lC[a] += 1;
			}
		}
		else if ((int)*x >= 48 && (int)*x <= 57){
			for (int i = 0; i < 10; i++){
				if ((int)*x == 48 + i)
					num[i] += 1;
			}
		}
		else if ((int)*x == 32)
			++space;
		else
			++ctr;
	}
	int t = 0;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 23);
	cout << "			" << "A L P H A B E T\n\n";
	for (int a = 0; a < 4; a++, t){
		for (int b = 0; b < 8; b++, t++){
			if (uC[t] + lC[t] != 0)
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 28);
			else
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 24);
			cout << "     " << (char)(65 + t) << ": " << uC[t] + lC[t];
			if (t + 1 == 26)
				break;
		}
		cout << endl;
	}
	t = 0;  cout << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 23);
	cout << "			" << "N U M B E R S\n\n";
	for (int a = 0; a < 2; a++, t){
		for (int b = 0; b < 8; b++, t++){
			if (t > 9){
				if ((t == 10 && space != 0) || (t == 11 && ctr != 0))
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 28);
				else
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 24);
				if (t == 10)
					cout << "\n\n     " << "Spaces: " << space;
				if (t == 11)
					cout << "\n     " << "Other: " << ctr;
			}
			else{
				if (num[t] != 0)
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 28);
				else
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 24);
				cout << "     " << t << ": " << num[t];
			}
		}
		cout << endl;
	}
}

void Srt(char *x)
{
	string y[160], temp;
	char n(NULL);
	const int len(Len(x)), wrd(wdCtr(x));
	for (int a = 0; a < wrd; a++){
		for (int b = 0; b < len; b++, *x++){
			if ((int)*x == 32 || *x == NULL){
				*x++;
				break;
			}
			else
				y[a] += *x;
		}
	}

	for (int a = 0; a < wrd; a++){
		for (int b = 0; b < len; b++){
			if (y[a] < y[b]){
				temp = y[a];
				y[a] = y[b];
				y[b] = temp;
			}
		}
	}
	for (int a = 0; a < wrd; a++){
		cout << y[a] << " ";
	}
}
