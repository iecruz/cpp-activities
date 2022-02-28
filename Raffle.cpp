#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <time.h>
#include <ctime>
using namespace std;
int main(){
	int min, max;
	srand(time(0));
	cout << "Enter the Lowest number for your Range: ";
	cin >> min;
	cout << "Enter the Highest number for your Range: ";
	cin >> max;
	if (min > max){
		int a = min;
		min = max;
		max = a;
	}
	for (int i = 0; i < 15; i++){
		int a = (rand() % (max - min + 1) + min);
		cout << "And the winning number is: " << a << "\n";
		system("pause");
	}
}