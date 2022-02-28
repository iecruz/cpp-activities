#include "stdafx.h"
#include <iostream>
#include <string>
#include <string.h>
#include <cstdlib>
#include <stdlib.h>
#include <time.h>
#include <ctime>
#include <iomanip>
using namespace std;


int main(){
	int min = 1, max, choice2;
	char choice, choice1;
	srand(time(0));
	cout << setw(50) << "Welcome to Project Raffle\n";
	cout << "Please Enter the Maximum Number of Entries: ";
	cin >> max;
	cout << "\n";
	cout << "Total No. of Entries is " << max << "\n\n" << "Would you like to add the entries now? [Y or N]: ";
	cin >> choice;
	cout << "\n";
	string name[100];
	string entry[100];
	string mobile[100];
	int i, g;
	if (choice == 'Y' || choice == 'y'){
		for (i = 1; i <= max; i++){
			cout << "Enter Name: ";
			cin >> name[i];
			cout << "Enter Raffle Entry: ";
			cin >> entry[i];
			cout << "Enter Mobile No.: ";
			cin >> mobile[i];

			cout << "\n";
			cout << "Do you want to enter the next entry? [Y or N]: ";
			cin >> choice1;
			cout << "\n";

			if (choice1 == 'N' || choice1 == 'n'){
				do{
					cout << "What would you like to do next?\n[1]Enter details for new entry\n[2]Edit details of previous entries\n[3]Proceed with the raffle\n[4]Exit\n\nEnter Here: ";
					cin >> choice2;
					cout << "\n";
					if (choice2 == 1){
						++max;
						continue;
					}
					else if (choice2 == 2){
						cout << "\n";
						g = i;
						for (i = 1; i <= g; i++){
							cout << "Name: " << name[i] << endl;
							cout << "Raffle Entry: " << entry[i] << endl;
							cout << "Mobile Number: " << mobile[i] << endl;
							cout << "\n";
						}
						++max;
					}
					else if (choice2 == 3)
						i = max;
					else{
						cout << "Program will End\n";
						system("pause");
						return 0;
					}
				} while (choice2 == 2);
			}
		}
		int x = (rand() % (max - min + 1) + min);
		cout << "The winning entry is: " << entry[x] << "\n";
		cout << "The winner is: " << name[x] << "\n";
		cout << "Contact Number: " << mobile[x] << "\n";
		system("pause");
		return 0;
	}
	else {
		cout << "Program will End\n";
		system("pause");
		return 0;
	}
}