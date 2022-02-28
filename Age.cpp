#include <iostream>
#include <ctime>

using namespace std;

int main() {
	srand((int)time(0));
	int tries = 0;
	int age = rand() % 100;
	int temp = 0;

	cout << "Enter number of tries: ";
	cin >> tries;

	for (int i = 0; i < tries; i++) {
		cout << "\nTrial (" << i + 1 << "/" << tries << "): ";
		cin >> temp;
		if (temp == age) {
			cout << "You got it! The age is " << temp << endl;
			break;
		}
		else if (temp > age)
			cout << "The age is lower than " << temp << endl;
		else if (temp < age)
			cout << "The age is higher than " << temp << endl;
		if (i == tries - 1)
			cout << "\nSorry! You didn't make it! The age is " << age;
	}
	system("pause>0");
	return 0;
}
