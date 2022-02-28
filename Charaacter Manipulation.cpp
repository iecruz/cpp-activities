#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;

int main()
{
	char x[30], ltr;
	char title[30], toggle[30];
	int space = 0;
	cout << "Enter String: "; gets_s(x); cout << endl;

	for (int i = 0; i < strlen(x); i++)
		title[i] = tolower(x[i]);

	for (int i = 0; i < strlen(x); i++){

		title[0] = toupper(x[0]);

		if (isspace(x[i])){
			title[i + 1] = toupper(x[i + 1]);
			if (!(isspace(i+1)))
				++space;
		}

		if (isupper(x[i]))
			toggle[i] = tolower(x[i]);

		else
			toggle[i] = toupper(x[i]);

	}
	cout << "Number of Words: " << ++space;
	cout << "\nTitle Case: ";
	for (int i = 0; i < strlen(x); i++){
		cout << title[i];
	}
	cout << "\nToggle Case: ";
	for (int i = 0; i < strlen(x); i++)
		cout << toggle[i];
	system("pause>0");
	return 0;
}

