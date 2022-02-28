// Chinese Zodiac.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	int month, day, year;
	int cz;
	string czod;
	cout << setw(40) << "Zodiac" << endl;
	cout << "Enter Month of Birth: ";
	cin >> month;
	cout << "Enter Day of Birth: ";
	cin >> day;
	cout << "Enter Year of Birth: ";
	cin >> year;
	cz = year % 12;
	switch (cz)
	{
	case 0:
		czod = "Monkey"; break;
	case 1: 
		czod = "Rooster"; break;
	case 2:
		czod = "Dog"; break;
	case 3:
		czod = "Pig"; break;
	case 4:
		czod = "Rat"; break;
	case 5:
		czod = "Ox"; break;
	case 6:
		czod = "Tiger"; break;
	case 7:
		czod = "Rabbit"; break;
	case 8:
		czod = "Dragon"; break;
	case 9:
		czod = "Snake"; break;
	case 10:
		czod = "Horse"; break;
	case 11:
		czod = "Sheep"; break;
	default:
		czod = "Unknown"; break;
	}
	cout << "\nYou belong to the Year of the " << czod;
	system("pause");
	return 0;
}

