// Grade Computation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	double Q1, Q2, A1, A2, LE, FE;
	double Q, A, LG;
	cout << setw(40) << "Enter value for Quiz 1: ";
	cin >> Q1;
	cout << setw(40) << "Enter value for Quiz 2: ";
	cin >> Q2;
	cout << setw(40) << "Enter value for Assignment 1: ";
	cin >> A1;
	cout << setw(40) << "Enter value for Assignment 2: ";
	cin >> A2;
	cout << setw(40) << "Enter value for Long Exam: ";
	cin >> LE;
	cout << setw(40) << "Enter value for Final Exam: ";
	cin >> FE;
	cout << "\n";
	Q = (Q1 + Q2) / 2;
	A = (A1 + A2) / 2;
	Q *=0.25;
	A *= .1;
	LE *= .25;
	FE *= .4;
	LG = Q + A + LE + FE;
	cout << setw(40) << fixed << setprecision(2) << "Quiz Percentage: " << Q << "%" << endl;
	cout << setw(40) << fixed << setprecision(2) << "Assignment Percentage: " << A << "%" << endl;
	cout << setw(40) << fixed << setprecision(2) << "Long Exam Percentage: " << LE << "%" << endl;
	cout << setw(40) << fixed << setprecision(2) << "Final Exam Percentage: " << FE << "%" << endl;
	cout << "\n";
	cout << setw(40) << fixed << setprecision(2) << "Lecture Grade: " << LG << "%" << endl;
	cout << "\n";
	system("pause");
	return 0;
}

