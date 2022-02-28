// Number System Convertion.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	int n, x, y, z;
	int bin[30], oct[30], hex[30];
	char hexa[30];
	cout << setw(40) << "Number System Conversion\n\n";
	cout << "Decimal: ";
	cin >> n;
	x = n;
	y = n;
	z = n;
	for (int a = 0; a < 30; a++){
		bin[a] = x % 2;
		x = x / 2;
	}
	for (int a = 0; a < 30; a++){
		oct[a] = y % 8;
		y = y / 8;
	}
	for (int a = 0; a < 30; a++){
		hex[a] = z % 16;
		z = z / 16;
	}

	cout << "\n" << setw(20) << "Binary: ";
	for (int a = 29; a >= 0; a--){
		if (bin[a] != 0){
			for (a; a >= 0; a--)
				cout << bin[a];
			break;
		}
	}
	cout << "\n" << setw(20) << "Octal: ";
	for (int a = 29; a >= 0; a--){
		if (oct[a] != 0){
			for (a; a >= 0; a--)
				cout << oct[a];
			break;
		}
	}
	cout << "\n" << setw(20) << "Hexadecimal: ";
	for (int a = 29; a >= 0; a--){
		if (hex[a] != 0){
			for (a; a >= 0; a--){
				if (hex[a] > 9)
					switch (hex[a]){
					case 10: cout << 'A'; continue;
					case 11: cout << 'B'; continue;
					case 12: cout << 'C'; continue;
					case 13: cout << 'D'; continue;
					case 14: cout << 'E'; continue;
					case 15: cout << 'F'; continue;
				}
				cout << hex[a];
			}
			break;
		}
	}
	cout << "\n\n";
	system("pause");
	return 0;
}

