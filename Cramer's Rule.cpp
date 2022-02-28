// Cramer's Rule.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	string label[] {"first", "second", "third"};
	float x[3], y[3], z[3], k[3];
	cout << setw(45) << "Cramer's Rule\n\n";
	cout << "NOTE:\nThe maximum number of equations is 3 and only up to 3 variables.\n\n";
	cout << "INSTRUCTION:\nEnter the 'A', 'B', 'C, and 'k' of the equation (A)x + (B)y + (C)z = k.\n\n";
	for (int a = 0; a < 3; a++){
		cout << "Enter the numerical coefficients and constant of the " << label[a] << " equation: \n";
		cout << "A: "; cin >> x[a];
		cout << "B: "; cin >> y[a];
		cout << "C: "; cin >> z[a];
		cout << "k: "; cin >> k[a];
		cout << "\n";
	}

	float d, dx, dy, dz, xval, yval, zval ;
	d = ((x[0] * y[1] * z[2]) + (x[1] * y[2] * z[0]) + (x[2] * y[0] * z[1])) - ((x[2] * y[1] * z[0]) + (x[0] * y[2] * z[1]) + (x[1] * y[0] * z[2]));
	dx = ((k[0] * y[1] * z[2]) + (k[1] * y[2] * z[0]) + (k[2] * y[0] * z[1])) - ((k[2] * y[1] * z[0]) + (k[0] * y[2] * z[1]) + (k[1] * y[0] * z[2]));
	dy = ((x[0] * k[1] * z[2]) + (x[1] * k[2] * z[0]) + (x[2] * k[0] * z[1])) - ((x[2] * k[1] * z[0]) + (x[0] * k[2] * z[1]) + (x[1] * k[0] * z[2]));
	dz = ((x[0] * y[1] * k[2]) + (x[1] * y[2] * k[0]) + (x[2] * y[0] * k[1])) - ((x[2] * y[1] * k[0]) + (x[0] * y[2] * k[1]) + (x[1] * y[0] * k[2]));
	xval = dx / d;
	yval = dy / d;
	zval = dz / d;
	cout << "\nThe determinant is: " << d << "\n";
	cout << "\nThe determinant of x is: " << dx;
	cout << "\nThe determinant of y is: " << dy;
	cout << "\nThe determinant of z is: " << dz << "\n";
	cout << "\nThe value of x is: " << xval;
	cout << "\nThe value of y is: " << yval;
	cout << "\nThe value of z is: " << zval << "\n\n";
	system("pause");
	cout << "Thank you for using the Cramer's Rule";
	return 0;
}

