// Taxi Fare.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;
int x;


int taxi()
{
	
	float fare, dist;
	cout << "Enter Distance in kilometer: ";
	cin >> dist;
	fare = 40;
	if (dist > 4){
		fare = ((dist - 4) * 10) + fare;
		cout << "The fare is: " << fare;
	}
	else{
		cout << "The fare is: " << fare;
	}
	cout << "\n";
	cout << "Do you want to continue? (Y=1 or N=0) ";
	cin >> x;
	return 0;
}

int main(){
	taxi();
	while (x != 0){
		system("cls");
		taxi();
		cin.clear();
		cin.get();
	}
		

}