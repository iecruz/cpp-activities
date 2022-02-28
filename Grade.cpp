#include "stdafx.h"
#include <iostream>
#include <conio.h>
using namespace std;
int main(){
	int  Q, sum, ave, x;
	int grade[100];
	char repeat;
	do{
		system("cls");
		sum = 0;
		cout << "Enter Number of Quizzes: ";
		cin >> Q;
		for (int i = 1; i <= Q; i++){
			cout << "Grade for Quiz #" << i << ": ";
			cin >> grade[i];
			sum = sum + grade[i];
		}
		ave = sum / Q;
		cout << "Average of all Quizzes: " << ave << "\n";
		if (ave < 75){
			cout << "You have Failed the grade of:" << ave << "\n";
		}
		else {
			cout << "You have Passed with the Grade of: " << ave << "\n";
		}
		cout << "Scores from Highest to Lowest:\n";
		for (int i = 1; i <= Q; i++){
			for (int y = 1; y <= Q; y++){
				if (grade[i] < grade[i + y]){
					x = grade[i + y];
					grade[i + y] = grade[i];
					grade[i] = x;
				}
			}
		}
		for (int i = 1; i <= Q; i++){
			cout << grade[i] << "\n";
		}
		cout << "Do you want to try again? [Y/N]: ";
		cin >> repeat;
	} while ((repeat != 'N') && (repeat != 'n'));
	return 0;
}


