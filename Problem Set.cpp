// Problem 1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;


int p1()
{
	int myInput, mySum=0;
	float myAverage;
	cout << "Enter 10 Numbers: \n";
	for (int a = 0; a < 10; a++){
		cin >> myInput;
		mySum += myInput;
	}
	myAverage = mySum / 10;
	cout << "The Average: " << myAverage << endl;
	system("pause");
	return 0;
}

int p2()
{
	int x, y, gen, sum = 0;
	cout << "Enter first number: ";
	cin >> x;
	cout << "Enter second number: ";
	cin >> y;
	cout << "Enter numbers to be generated: ";
	cin >> gen;
	cout << "Output: " << x << " " << y << " ";
	for (int a = 0; a < (gen-2); a++){
		sum = x + y;
		cout << sum << " ";
		x = y;
		y = sum;
	}
	cout << endl;
	system("pause");
	return 0;
}

int p3()
{
	int x, y, gen, sum = 0, total = 0;
	cout << "Enter first number: ";
	cin >> x;
	cout << "Enter second number: ";
	cin >> y;
	cout << "Enter numbers to be generated: ";
	cin >> gen;
	total = total + x + y;
	cout << "Output: " << x << " " << y << " ";
	for (int a = 0; a < (gen - 2); a++){
		sum = x + y;
		cout << sum << " ";
		x = y;
		y = sum;
		total += sum;
	}
	cout << "\nSum: " << total;
	cout << endl;
	system("pause");
	return 0;
}

int p4()
{
	int num, x[4];
	cout << "Input: ";
	cin >> num;
	int div = 1000, sum = 0;
	for (int a = 0; a < 4; a++){
		x[a] = num / div;
		num = num - x[a] * div;
		div = div / 10;
		sum += x[a];
	}
	cout << "Output: " << sum << endl;
	system("pause");
	return 0;
}

int p5()
{
	int num, x[5];
	cout << "Input: ";
	cin >> num;
	int div = 10000;
	for (int a = 0; a < 5; a++){
		x[a] = num / div;
		num = num - x[a] * div;
		div = div / 10;
	}
	
	cout << "Output: ";
	for (int a = 4; a >= 0; a--){
		cout << x[a];
	}
	cout << endl;
	system("pause");
	return 0;
}

int p6()
{
	int num, bin[7];
	cout << "Input: ";
	cin >> num;
	cout << "Output: ";
	for (int a = 0; a < 7; a++){
		bin[a] = num % 2;
		num = num / 2;
	}
	for (int a = 6; a >= 0; a--)
		cout << bin[a];
	cout << endl;
	system("pause");
	return 0;
}

int p7()
{
	// Start with Capital Letter
	string color;
	int r = 0, g = 0, b = 0;
	cout << "Input: \n";
	do{
		cin >> color;
		if (color == "Red" || color == "red")
			++r;
		else if (color == "Green" || color == "green")
			++g;
		else if (color == "Blue" || color == "blue")
			++b;
	} while (color != "End");
	cout << endl;
	cout << "Blue is " << b << " times.\n";
	cout << "Green is " << g << " times.\n";
	cout << "Red is " << r << " times.\n";
	cout << endl;
	system("pause");
	return 0;
}

int p8()
{
	int num, two, three, five, sum = 0;
	num = 1;
	for (int a = 1; a <= 1500; a++, num++){
		two = num % 2;
		three = num % 3;
		five = num % 5;
		if (two == 0 && three == 0 && five == 0){
			sum += num;
			continue;
		}
		if (two == 0 && three == 0){
			sum += num;
			continue;
		}
		if (two == 0 && five == 0){
			sum += num;
			continue;
		}
		if (three == 0 && five == 0){
			sum += num;
			continue;
		}
		if (two == 0){
			sum += num;
			continue;
		}
		if (three == 0){
			sum += num;
			continue;
		}
		if (five == 0){
			sum += num;
			continue;
		}
	}
	cout << "Sum: " << sum << endl;
	system("pause");
	return 0;
}

int p9()
{
	int num, mod;
	cout << "Input: ";
	cin >> num;
	cout << "Output: " << num << " ";
	do{
		mod = num % 2;
		if (mod == 0)
			num = num / 2;
		else if (mod == 1)
			num = num * 3 + 1;
		cout << num << " ";
	} while (num != 1);
	cout << endl;
	system("pause");
	return 0;
}

int p10()
{
	int num, x[2], pro;
	cout << "Input: ";
	cin >> num;
	int div = 10;
	for (int a = 0; a < 2; a++){
		x[a] = num / div;
		num = num - x[a] * div;
		div = div / 10;
	}
	pro = x[0] * x[1];
	cout << "Output: " << pro << endl;
	system("pause");
	return 0;
}

int main()
{
	int ch1;
	cout << "Problem Set 1: Looping Problem\n\n";
	cout << "Enter the Problem Number: ";
	cin >> ch1;
	switch (ch1)
	{
	case 1:
		system("cls");
		p1();
		system("cls");
		main();
		break;
	case 2:
		system("cls");
		p2();
		system("cls");
		main();
		break;
	case 3:
		system("cls");
		p3();
		system("cls");
		main();
		break;
	case 4:
		system("cls");
		p4();
		system("cls");
		main();
		break;
	case 5:
		system("cls");
		p5();
		system("cls");
		main();
		break;
	case 6:
		system("cls");
		p6();
		system("cls");
		main();
		break;
	case 7:
		system("cls");
		p7();
		system("cls");
		main();
		break;
	case 8:
		system("cls");
		p8();
		system("cls");
		main();
		break;
	case 9:
		system("cls");
		p9();
		system("cls");
		main();
		break;
	case 10:
		p10();
		system("cls");
		main();
		break;
	default:
		cout << "\nProgram will now end!\n\n";
		system("pause");
	}
	return 0;
}


