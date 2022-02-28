#include <iostream>
#include <string>
#include <cstring>
#include <Windows.h>

#include "UI.h"
#include "Link.h"

using namespace std;

int main()
{
	string menu[5] = { "ADD", "DELETE", "SORT", "SEARCH", "EXIT" };
	Maximize();
	topBanner("S E M I N A R   A T T E N D A N C E");
	leftPanel(menu);
	int choice;
	/*while (true){
		//system("cls");
		cout << endl << "	S E M I N A R   A T T E N D A N C E\n\n"
			<< "   1 - Adding of Participant at the Beginning\n"
			<< "   2 - Adding of Participant at the End\n"
			<< "   3 - Adding of Participant at any Specified Position\n"
			<< "   4 - Deleting of Participant at the Beginning\n"
			<< "   5 - Deleting of Participant at the End\n"
			<< "   6 - Deleting of Participant at any Specified Position\n"
			<< "   7 - Sorting by Student Number | Course | Year\n"
			<< "   8 - Search by Student Number | Course | Year\n"
			<< "   9 - Exit\n\n"
			<< "       Enter Choice here: "; cin >> choice;
		system("cls");
		cout << endl;
		switch (choice){
		case 1:
			if (head == NULL)
				addFirst();
			else
				addBegin();
			break;
		case 2:
			if (head == NULL)
				addFirst();
			else
				addEnd();
			break;
		case 4:
			if (head == NULL)
				cout << "   No Record!";
			else if (head->next == NULL && tail->next == NULL){
				delete head;
				head = NULL;
			}
			else
				delBegin();
			break;
		case 5:
			if (head == NULL)
				cout << "   No Record!";
			else if (head->next == NULL && tail->next == NULL){
				delete head;
				head = NULL;
			}
			else
				delEnd();
			break;
		case 8: transverse(); system("pause>0"); break;
		case 9: exit(1);
		}
	}*/
	system("pause>0");
	return 0;
}
