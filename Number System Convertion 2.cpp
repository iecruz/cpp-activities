// Number System Convertion 2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

void binary(int);
void octal(int);
void hexadecimal(int);

int _tmain(int argc, _TCHAR* argv[])
{
	int x;
	cout << "Enter a Decimal: "; 
	cin >> x;
	cout << endl;
	cout << "Binary: ";
	binary(x);
	cout << endl;
	cout << "Octal: ";
	octal(x);
	cout << endl;
	cout << "Hexadecimal: ";
	hexadecimal(x);
	cout << endl;
	system("pause > 0");
	return 0;
}

void binary(int x)
{
	if (x != 0){
		binary(x / 2);
		cout << x % 2;
	}
}

void octal(int x)
{
	if (x != 0){
		octal(x / 8);
		cout << x % 8;
	}
}

void hexadecimal(int x)
{
	if (x != 0){
		hexadecimal(x / 16);
		switch (x)
		{
		case 15: cout << "F"; break;
		case 14: cout << "E"; break;
		case 13: cout << "D"; break;
		case 12: cout << "C"; break;
		case 11: cout << "B"; break;
		case 10: cout << "A"; break;
		default: cout << x % 8;
		}
	}
}
