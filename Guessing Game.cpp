// Guessing Game.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "stdlib.h"
#include "ctime"

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	int x, att;
	srand(time(NULL));
	int num = (rand() % 99) + 1;
	att = 7;
	cout << "MECHANICS: Pick a number from 1 to 100. You are given 7 chances." << endl;
	do{
	cout << endl << "You have "<< att << " more attempts left.\n" << "Enter your guess: ";
	cin >> x;
	if (x > (num + 25)){
		if (att == 1)
			cout << "It's lower than that!";
		else
			cout << "It is high. Pick a lower one.";
	}
	else if (x < (num - 25)){
		if (att == 1)
			cout << "It's higher than that!";
		else
			cout << "It is low. Pick a higher one.";
	}
	else if (x > (num + 10)){
		if (att == 1)
			cout << "It's a bit lower than that!";
		else
			cout << "It's a bit high. Pick a bit lower one.";
	}
	else if (x < (num - 10)){
		if (att == 1)
			cout << "It's a bit higher than that!";
		else
			cout << "It is a bit low. Pick a bit higher one.";
	}
	else if (x > num){
		if (att == 1)
			cout << "You are so close!";
		else
			cout << "You are so close! Pick a little bit lower one.";
	}
	else if (x < num){
		if (att == 1)
			cout << "You are so close!";
		else
			cout << "You are so close! Pick a little bit higher one.";
	}
	--att;
	cout << endl;
	} while (num != x && att > 0);

	if (x == num)
		cout << "Congratulations! You have got the correct number." << endl << endl;
	else
		cout << endl << "Sorry! You have no attempts left. The correct number is " << num << "." << endl << endl;
	system("pause");
	return 0;
}

