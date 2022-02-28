#include <iostream>
#include <stdlib.h> //necessary for using rand function
#include <ctime>

using namespace std;

int main()
{
	srand(time(NULL)); //srand - initialize random generator
	int rand_num[100]; //array that contains the random numbers generated
	int N, sort_out = 0, index_high; // sort_out - holds the highest value & index_high - holds the index of rand_num that contains the higest value
	cout << "Number Count: "; cin >> N;
	cout << "\nGenerated Numbers are: ";

	for (int i = 0; i < N; i++) // generates the random numbers and put it in array "rand_num"
	{
		rand_num[i] = rand() % 100; // % - modulo (used to pick numbers 0 - 99 only)
		cout << rand_num[i] << " "; // prints the number after it is generated
	}

	cout << "\n\nBucket 1 (00 - 19): ";
	for (int i = 0; i < N; i++)
		if (rand_num[i] >= 0 && rand_num[i] <= 19)
			cout << rand_num[i] << " ";

	cout << "\nBucket 2 (20 - 39): ";
	for (int i = 0; i < N; i++)
		if (rand_num[i] >= 20 && rand_num[i] <= 39)
			cout << rand_num[i] << " ";

	cout << "\nBucket 3 (40 - 59): ";
	for (int i = 0; i < N; i++)
		if (rand_num[i] >= 40 && rand_num[i] <= 59)
			cout << rand_num[i] << " ";

	cout << "\nBucket 4 (60 - 79): ";
	for (int i = 0; i < N; i++)
		if (rand_num[i] >= 60 && rand_num[i] <= 79)
			cout << rand_num[i] << " ";

	cout << "\nBucket 5 (80 - 99): ";
	for (int i = 0; i < N; i++)
		if (rand_num[i] >= 80 && rand_num[i] <= 99)
			cout << rand_num[i] << " ";

	cout << "\n\nSorted: ";
	for (int i = 0, j = 0; i < N; i++)
	{
		for (; j < N; j++) //sort_out will take the highest value in rand_num array that isn't printed yet
			if (sort_out < rand_num[j]) //compares if sort_out (which holds the highest value) with other number in rand_num
			{
			sort_out = rand_num[j];
			index_high = j; //gets the index of the number in rand_num with the highest value 
			}
		cout << sort_out << " ";
		rand_num[index_high] = 0; //prevents the highest number from being included in the loop by setting it the lowest value
		sort_out = 0;
		j = 0;
	}
	system("pause>0");
	return 0;
}