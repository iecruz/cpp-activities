#include <iostream>
#include <iomanip>
#include <cstring>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include <Windows.h>

using namespace std;

int rec = 0;

struct Student{
	int id;
	char Lname[20];
	char Fname[20];
	char Mname[20];
	int quiz[3];
	double ave;
	string remark;
} stud[30];

void newLine()
{
	char s; do { cin.get(s); } while (s != '\n');
}

void add();
void edit();
void del(); void transfer();
void view();
void search();
void output();
void detail(int);

int main()
{
	int menuchoice;
	cout << setiosflags(ios::fixed) << setprecision(2);
menu:
	cout << setw(40) << "M A I N   M E N U\n\n";
	cout << "   1.  Add Record\n"
		<< "   2.  Edit Record\n"
		<< "   3.  Delete Record\n"
		<< "   4.  View Record\n"
		<< "   5.  Search Record\n"
		<< "   6.  Exit";
	cout << endl << endl << "Choose option: ";
	cin >> menuchoice;
	cout << endl;
	switch (menuchoice)
	{
	case 1: system("cls"); add(); system("cls"); break;
	case 2:
		if (rec == 0){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
			cout << "There is no record available!";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			system("pause > 0");
			system("cls");
			break;
		}
		else{
			system("cls"); output(); cout << endl;  edit();
			system("pause>0"); system("cls"); break;
		}
	case 3:
		if (rec == 0){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
			cout << "There is no record available!";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			system("pause > 0");
			system("cls");
			break;
		}
		else{
			system("cls"); output(); cout << endl;  del();
			system("pause>0"); system("cls");  break;
		}
	case 4:
		if (rec == 0){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
			cout << "There is no record available!";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			system("pause > 0");
			system("cls");
			break;
		}
		else{
			system("cls"); output(); cout << endl; view(); system("cls"); break;
		}
	case 5:
		if (rec == 0){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
			cout << "There is no record available!";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			system("pause > 0");
			system("cls");
			break;
		}
		else{
			search(); system("cls"); break;
		}
	case 6: exit(1); break;
	default: system("cls"); break;
	}
	goto menu;
}

void add()
{
	char add_cont;
add_rep:
	int sum = 0;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
	cout << endl << setw(11) << "RECORD #" << rec + 1 << endl << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
check:
	cout << setw(14) << "ID Number: "; cin >> stud[rec].id;
	if (stud[rec].id > 9999 || stud[rec].id < 1000){
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		cout << setw(20) << "Please try again!\n";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		goto check;
	}
	for (int i = 0; i < rec; i++)
		if (stud[rec].id == stud[i].id){
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		cout << setw(48) << "ID Number is already taken. Please try again!\n";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		goto check;
		}
	newLine();
	cout << setw(14) << "Last Name: "; gets_s(stud[rec].Lname); //newLine();
	cout << setw(14) << "First Name: "; gets_s(stud[rec].Fname); //newLine();
	cout << setw(14) << "Middle Name: "; gets_s(stud[rec].Mname);
	cout << endl;
	for (int i = 0; i < 3; i++){
		cout << setw(8) << "Quiz #" << i + 1 << ": "; cin >> stud[rec].quiz[i];
		if (stud[rec].quiz[i] > 100 || stud[rec].quiz[i] < 0){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
			cout << setw(20) << "Please try again!\n";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			--i;
			continue;
		}
		sum += stud[rec].quiz[i];
	}
	stud[rec].ave = sum / 3.00;
	cout << endl << setw(10) << "Average: " << stud[rec].ave << endl;
	if (stud[rec].ave >= 75)
		stud[rec].remark = "PASSED";
	else
		stud[rec].remark = "FAILED";
	cout << setw(10) << "Remarks: ";
	if (stud[rec].remark == "PASSED")
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	else
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	cout << stud[rec].remark;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
	cout << endl << endl << "Record is successfully added!" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	++rec;
	do{
		//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
		cout << endl << "Do you want to continue adding? (Y or N): ";
		//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		cin >> add_cont;
	} while (add_cont != 'Y' && add_cont != 'y' && add_cont != 'N' && add_cont != 'n');
	if (add_cont == 'Y' || add_cont == 'y'){
		cout << endl;
		goto add_rep;
	}
}

void edit()
{
	int edit_rec;
	do {
		cout << "Choose record to edit: "; cin >> edit_rec;
		if (edit_rec < 1 || edit_rec > rec){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
			cout << "Please try again!" << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		}
	} while (edit_rec < 1 || edit_rec > rec);
	cout << endl;
	--edit_rec;
	detail(edit_rec);
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
	cout << endl << setw(23) << "Please type the new name!" << endl << endl;
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	newLine();
	cout << setw(14) << "Last Name: "; gets_s(stud[edit_rec].Lname); 
	cout << setw(14) << "First Name: "; gets_s(stud[edit_rec].Fname);
	cout << setw(14) << "Middle Name: "; gets_s(stud[edit_rec].Mname);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
	cout << endl << "Record is successfully updated!" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

void view()
{
	int view_rec;
	char view_cont;
	view_rep:
	do{
		cout << endl << "Choose record to view: "; cin >> view_rec;
		if (view_rec < 1 || view_rec > rec){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
			cout << "Please try again!" << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		}
	} while (view_rec < 0 || view_rec > rec);
	cout << endl;
	--view_rec;
	detail(view_rec);
	do{
		//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
		cout << endl << "Do you want to continue viewing? (Y or N): ";
		//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		cin >> view_cont;
	} while (view_cont != 'Y' && view_cont != 'y' && view_cont != 'N' && view_cont != 'n');
	if (view_cont == 'Y' || view_cont == 'y')
		goto view_rep;
}

void del()
{
	int del_rec;
	char del_ver;
	do {
		cout << "Choose record to delete: "; cin >> del_rec;
		if (del_rec < 1 || del_rec > rec){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
			cout << "Please try again!" << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		}
	} while (del_rec < 1 || del_rec > rec);
	cout << endl;
	--del_rec;
	detail(del_rec);
	do{
		//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
		cout << endl << "Are you sure you want to delete this record? (Y or N): ";
		//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		cin >> del_ver;
	} while (del_ver != 'Y' && del_ver != 'y' && del_ver != 'N' && del_ver != 'n');
	if (del_ver == 'Y' || del_ver == 'y'){
		stud[del_rec].id = NULL;
		for (int i = 0; i < 20; i++){
			stud[del_rec].Fname[i] = NULL;
			stud[del_rec].Mname[i] = NULL;
			stud[del_rec].Lname[i] = NULL;
		}
		for (int i = 0; i < 3; i++)
			stud[del_rec].quiz[i] = NULL;
		stud[del_rec].ave = NULL;
		stud[del_rec].remark = '\0';
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		cout << endl << "Record is successfully deleted!" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		transfer();
		--rec;
	}
}

void transfer()
{
	int emp;
	do{
		emp = 0;
		while (stud[emp].id != NULL)
			++emp;
		//while (emp < rec){
		if (emp < rec){
			stud[emp].id = stud[emp + 1].id;
			for (int i = 0; i < 20; i++){
				stud[emp].Fname[i] = stud[emp + 1].Fname[i];
				stud[emp].Mname[i] = stud[emp + 1].Mname[i];
				stud[emp].Lname[i] = stud[emp + 1].Lname[i];
			}
			//stud[emp].Lname = stud[emp + 1].Lname;
			for (int i = 0; i < 3; i++)
				stud[emp].quiz[i] = stud[emp + 1].quiz[i];
			stud[emp].ave = stud[emp + 1].ave;
			stud[emp].remark = stud[emp + 1].remark;

			stud[emp + 1].id = NULL;
			for (int i = 0; i < 30; i++){
				stud[emp + 1].Fname[i] = NULL;
				stud[emp + 1].Mname[i] = NULL;
				stud[emp + 1].Lname[i] = NULL;
			}
			//stud[emp + 1].Lname = '\0';
			for (int i = 0; i < 3; i++)
				stud[emp + 1].quiz[i] = NULL;
			stud[emp + 1].ave = NULL;
			stud[emp + 1].remark = '\0';
		}
		emp = 0;
	} while (emp > rec);
}

void search()
{
	char search_cont;
	int search_menu, FNresult = 0, LNresult = 0, MNresult = 0;
	int id_search;
	char fname_search[20], mname_search[20], lname_search[20];
	bool no_id = false;
search_rep:
	system("cls");
	cout << setw(40) << "S E A R C H   M E N U" << endl << endl;
	cout << "    1.  Search by ID Number" << endl
		<< "    2.  Search by First Name" << endl
		<< "    3.  Search by Middle Name" << endl
		<< "    4.  Search by Last Name" << endl;
	cout << endl << "Choose option: "; cin >> search_menu;
	cout << endl;
	switch (search_menu)
	{
	case 1:
		cout << "Enter ID Number: "; cin >> id_search;
		cout << endl;
		for (int i = 0; i < rec; i++){
			if (stud[i].id == id_search){
				detail(i);
				//system("pause>0");
				no_id = false;
				break;
			}
			else
				no_id = true;
		}
		if (no_id)
			cout << endl << "There is no record containing " << id_search << " as an ID Number." << endl;
		//system("pause>0");;
		break;
	case 2:
		newLine();
		cout << "Enter First Name: "; gets_s(fname_search);
		cout << endl << "Search Result of \"" << fname_search << "\"" << endl;
		for (int i = 0; i < rec; i++){
			if (!(strcmp(stud[i].Fname, fname_search))){
				++FNresult;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
				cout << endl << setw(11) << "RESULT #" << FNresult << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				detail(i);
			}
		}
		//system("pause>0");
		if (FNresult == 0)
			cout << endl << "There is no record containing " << fname_search << " as a First Name." << endl;
		//system("pause>0");
		FNresult = 0;
		break;
	case 3:
		newLine();
		cout << "Enter Middle Name: "; gets_s(mname_search);
		cout << endl << "Search Result of \"" << mname_search << "\"" << endl;
		for (int i = 0; i < rec; i++){
			if (!(strcmp(stud[i].Mname, mname_search))){
				++MNresult;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
				cout << endl << setw(11) << "RESULT #" << MNresult << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				detail(i);
			}
		}
		//system("pause>0");
		if (MNresult == 0)
			cout << endl << "There is no record containing " << mname_search << " as a Middle Name." << endl;
		//system("pause>0");
		MNresult = 0;
		break;
	case 4:
		newLine();
		cout << "Enter Last Name: "; gets_s(lname_search);
		cout << endl << "Search Result of \"" << lname_search << "\"" << endl;
		for (int i = 0; i < rec; i++){
			if (!(strcmp(stud[i].Lname, lname_search))){
				++LNresult;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
				cout << endl << setw(11) << "RESULT #" << LNresult << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				detail(i);
			}
		}
		//system("pause>0");
		if (LNresult == 0)
			cout << endl << "There is no record containing " << lname_search << " as a Last Name." << endl;
		//system("pause>0");
		LNresult = 0;
		break;
	default:
		system("cls");
		main();
	}
	do{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
		cout << endl << "Do you want to continue searching? (Y or N): ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		cin >> search_cont;
	} while (search_cont != 'Y' && search_cont != 'y' && search_cont != 'N' && search_cont != 'n');
	if (search_cont == 'Y' || search_cont == 'y'){
		goto search_rep;
	}
}

void output()
{
	int pass = 0, fail = 0;
	cout << setw(47) << "STUDENT RECORD RESULT\n\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
	cout << setw(10) << "RECORD #"
		<< setw(11) << "ID"
		<< setw(18) << "NAME"
		<< setw(19) << "AVERAGE"
		<< setw(15) << "REMARKS" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	for (int i = 0; i < rec; i++){
		cout << setw(6) << i + 1
			<< setw(16) << stud[i].id
			<< setw(19) << stud[i].Lname << ", " << stud[i].Fname[0]
			<< setw(13) << stud[i].ave;
		if (stud[i].remark == "PASSED")
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		else
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		cout << setw(15) << stud[i].remark << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	}
	cout << endl;
	for (int i = 0; i < rec; i++){
		if (stud[i].remark == "PASSED")
			++pass;
		else
			++fail;
	}
	cout << setw(25) << "Number of Passed: ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	cout << pass;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cout << setw(35) << "Number of Failed: ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	cout << fail;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cout << endl;
}

void detail(int x)
{
	cout << setw(14) << "ID Number: " << stud[x].id << endl
		<< setw(14) << "Name: " << stud[x].Fname << " " << stud[x].Mname[0] << ". " << stud[x].Lname << endl
		<< setw(14) << "Quizzes: " << endl
		<< setw(15) << "Quiz #1: " << stud[x].quiz[0] << endl
		<< setw(15) << "Quiz #2: " << stud[x].quiz[1] << endl
		<< setw(15) << "Quiz #3: " << stud[x].quiz[2] << endl
		<< setw(14) << "Average: " << stud[x].ave << endl
		<< setw(14) << "Remarks: ";
	if (stud[x].remark == "PASSED")
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	else
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	cout << stud[x].remark << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}