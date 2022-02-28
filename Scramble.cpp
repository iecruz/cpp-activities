#include <iostream>
#include <string.h>
#include <ctime>
#include <algorithm>

#define _CRT_SECURE_NO_WARNINGS

using namespace std;

struct Word {
	char correct[30];
	char scrambled[30];
}word[30];

void newline() {
	char s;
	do { cin.get(s); } while (s != '\n');
}

int main() {
	srand((int)time(0));
	int wordCount = 0;
	cout << "Enter number of words: ";
	cin >> wordCount;
	cout << "Enter " << wordCount << " words: \n\n";
	newline();
	for (int i = 0; i < wordCount; i++) {
		cout << "Word # " << i + 1 << ": ";
		gets_s(word[i].correct);
		strcpy_s(word[i].scrambled, word[i].correct);
		random_shuffle(word[i].scrambled, word[i].scrambled + strlen(word[i].scrambled));
	}
	cout << "Correct: ";
	for (int i = 0; i < wordCount; i++) {
		cout << word[i].correct << " ";;
	}
	cout << "Scrambled: ";
	for (int i = 0; i < wordCount; i++) {
		cout << word[i].scrambled << " ";;
	}
	system("pause>0");
	return 0;
}
