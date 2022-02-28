// Winning Number.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	int x, win[3], z[3];
	int y = 0;
	int i = 100;
	win[0] = 1; win[1] = 2;win[2]= 3;
	cout << "Enter Number: ";
	cin >> x;
	for (int j = 0; j < 3; j++){
		z[j] = x / i;
		x = x - z[j]*i;
		i = i / 10;
	}
	for (int i = 0; i < 3; i++){
		if (z[i] == win[i])
			++y;
	}
	cout << "The Winning Numbers is: 123" << "\n";
	cout << "The Number of digit matched: " << y << "\n";
	system("pause");
	return 0;
}

