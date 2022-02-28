#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


int main()
{
	int month, day;
	char nxt;
	do{
		system("cls");
		cout << setw(40) << "Zodiac" << endl;
		cout << "Enter Month of Birth: ";
		cin >> month;
		cout << "Enter Day of Birth: ";
		cin >> day;
		switch (month)
		{
		case 1:
			if (day >= 1 && day <= 19)
			{
				cout << "The Zodiac Sign for January " << day << " is Capricorn";
				cout << "\nWould you like to enter again? [Y or N] ";
				cin >> nxt;
			}
			else if (day >= 20 && day <= 31)
			{
				cout << "The Zodiac Sign for January " << day << " is Aquarius";
				cout << "\nWould you like to enter again? [Y or N] ";
				cin >> nxt;
			}
			else
			{
				cout << "Invalid Date. Please Try Again.\n";
				system("pause");
				nxt = 'y'; continue;
			}
			break;
		case 2:
			if (day >= 1 && day <= 18)
			{
				cout << "The Zodiac Sign for February " << day << " is Aquarius";
				cout << "\nWould you like to enter again? [Y or N] ";
				cin >> nxt;
			}
			else if (day >= 19 && day <= 29)
			{
				cout << "The Zodiac Sign for February " << day << " is Pisces";
				cout << "\nWould you like to enter again? [Y or N] ";
				cin >> nxt;
			}
			else
			{
				cout << "Invalid Date. Please Try Again.\n";
				system("pause");
				nxt = 'y'; continue;
			}
			break;
		case 3:
			if (day >= 1 && day <= 20)
			{
				cout << "The Zodiac Sign for March " << day << " is Pisces";
				cout << "\nWould you like to enter again? [Y or N] ";
				cin >> nxt;
			}
			else if (day >= 21 && day <= 31)
			{
				cout << "The Zodiac Sign for March " << day << " is Aries";
				cout << "\nWould you like to enter again? [Y or N] ";
				cin >> nxt;
			}
			else
			{
				cout << "Invalid Date. Please Try Again.\n";
				system("pause");
				nxt = 'y'; continue;
			}
			break;
		case 4:
			if (day >= 1 && day <= 19)
			{
				cout << "The Zodiac Sign for April " << day << " is Aries";
				cout << "\nWould you like to enter again? [Y or N] ";
				cin >> nxt;
			}
			else if (day >= 20 && day <= 30)
			{
				cout << "The Zodiac Sign for April " << day << " is Taurus";
				cout << "\nWould you like to enter again? [Y or N] ";
				cin >> nxt;
			}
			else
			{
				cout << "Invalid Date. Please Try Again.\n";
				system("pause");
				nxt = 'y'; continue;
			}
			break;
		case 5:
			if (day >= 1 && day <= 20)
			{
				cout << "The Zodiac Sign for May " << day << " is Taurus";
				cout << "\nWould you like to enter again? [Y or N] ";
				cin >> nxt;
			}
			else if (day >= 21 && day <= 31)
			{
				cout << "The Zodiac Sign for May " << day << " is Gemini";
				cout << "\nWould you like to enter again? [Y or N] ";
				cin >> nxt;
			}
			else
			{
				cout << "Invalid Date. Please Try Again.\n";
				system("pause");
				nxt = 'y'; continue;
			}
			break;
		case 6:
			if (day >= 1 && day <= 20)
			{
				cout << "The Zodiac Sign for June " << day << " is Gemini";
				cout << "\nWould you like to enter again? [Y or N] ";
				cin >> nxt;
			}
			else if (day >= 21 && day <= 30)
			{
				cout << "The Zodiac Sign for June " << day << " is Cancer";
				cout << "\nWould you like to enter again? [Y or N] ";
				cin >> nxt;
			}
			else
			{
				cout << "Invalid Date. Please Try Again.\n";
				system("pause");
				nxt = 'y'; continue;
			}
			break;
		case 7:
			if (day >= 1 && day <= 22)
			{
				cout << "The Zodiac Sign for July " << day << " is Cancer";
				cout << "\nWould you like to enter again? [Y or N] ";
				cin >> nxt;
			}
			else if (day >= 23 && day <= 31)
			{
				cout << "The Zodiac Sign for July " << day << " is Leo";
				cout << "\nWould you like to enter again? [Y or N] ";
				cin >> nxt;
			}
			else
			{
				cout << "Invalid Date. Please Try Again.\n";
				system("pause");
				nxt = 'y'; continue;
			}
			break;
		case 8:
			if (day >= 1 && day <= 22)
			{
				cout << "The Zodiac Sign for August " << day << " is Leo";
				cout << "\nWould you like to enter again? [Y or N] ";
				cin >> nxt;
			}
			else if (day >= 23 && day <= 31)
			{
				cout << "The Zodiac Sign for August " << day << " is Virgo";
				cout << "\nWould you like to enter again? [Y or N] ";
				cin >> nxt;
			}
			else
			{
				cout << "Invalid Date. Please Try Again.\n";
				system("pause");
				nxt = 'y'; continue;
			}
			break;
		case 9:
			if (day >= 1 && day <= 22)
			{
				cout << "The Zodiac Sign for September " << day << " is Virgo";
				cout << "\nWould you like to enter again? [Y or N] ";
				cin >> nxt;
			}
			else if (day >= 23 && day <= 30)
			{
				cout << "The Zodiac Sign for September " << day << " is Libra";
				cout << "\nWould you like to enter again? [Y or N] ";
				cin >> nxt;
			}
			else
			{
				cout << "Invalid Date. Please Try Again.\n";
				system("pause");
				nxt = 'y'; continue;
			}
			break;
		case 10:
			if (day >= 1 && day <= 22)
			{
				cout << "The Zodiac Sign for October " << day << " is Libra";
				cout << "\nWould you like to enter again? [Y or N] ";
				cin >> nxt;
			}
			else if (day >= 23 && day <= 31)
			{
				cout << "The Zodiac Sign for October " << day << " is Scorpio";
				cout << "\nWould you like to enter again? [Y or N] ";
				cin >> nxt;
			}
			else
			{
				cout << "Invalid Date. Please Try Again.\n";
				system("pause");
				nxt = 'y'; continue;
			}
			break;
		case 11:
			if (day >= 1 && day <= 21)
			{
				cout << "The Zodiac Sign for November " << day << " is Scorpio";
				cout << "\nWould you like to enter again? [Y or N] ";
				cin >> nxt;
			}
			else if (day >= 22 && day <= 30)
			{
				cout << "The Zodiac Sign for November " << day << " is Sagittarius";
				cout << "\nWould you like to enter again? [Y or N] ";
				cin >> nxt;
			}
			else
			{
				cout << "Invalid Date. Please Try Again.\n";
				system("pause");
				nxt = 'y'; continue;
			}
			break;
		case 12:
			if (day >= 1 && day <= 21)
			{
				cout << "The Zodiac Sign for December " << day << " is Sagittarius";
				cout << "\nWould you like to enter again? [Y or N] ";
				cin >> nxt;
			}
			else if (day >= 22 && day <= 31)
			{
				cout << "The Zodiac Sign for December " << day << " is Capricorn";
				cout << "\nWould you like to enter again? [Y or N] ";
				cin >> nxt;
			}
			else
			{
				cout << "Invalid Date. Please Try Again.\n";
				system("pause");
				nxt = 'y'; continue;
			}
			break;
		default:
		{
			cout << "Invalid Date. Please Try Again.\n";
			system("pause");
			nxt = 'y'; continue;
		}
			break;
		}
	} while (nxt == 'Y' || nxt == 'y');
	return 0;
}