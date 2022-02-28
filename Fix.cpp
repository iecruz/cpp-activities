#include <iostream>
#include <cstring>

using namespace std;

char in[50], post[50], pre[50], op[50];
int rnk[50], opr[50];

void newline()
{
	char s;
	do{ cin.get(s); } while (s != '\n');
}

void prefix();
void postfix();
void rankpost();
void rankpre();
void initiate();
bool valid();

int main()
{
	while (true){
		do{
			cout << endl;
			cout << "     Enter: "; gets_s(in); //newline();
			rankpost();
			if (valid())
				cout << "\n     Invalid Input! Please try again.\n";
		} while (valid());
		postfix();
		_strrev(in);
		rankpre();
		prefix();
		_strrev(pre);
		cout << "   Postfix: "; puts(post);
		cout << "    Prefix: "; puts(pre);
		initiate();
	}
}

void initiate()
{
	for (int i = 0; i < 50; i++){
		rnk[i] = 0;
		in[i] = NULL;
		pre[i] = NULL;
		post[i] = NULL;
	}
}

void rankpost()
{
	for (int i = 0; i < strlen(in); i++){
		switch (in[i]){
		case '+': rnk[i] = 3; break;
		case '-': rnk[i] = 3; break;
		case '*': rnk[i] = 4; break;
		case '/': rnk[i] = 4; break;
		case '^': rnk[i] = 5; break;
		case '(': rnk[i] = 2; break;
		case ')': rnk[i] = -2; break;
		case '\0': rnk[i] = 0; break;
		default: rnk[i] = 1;
		}
	}
}

void rankpre()
{
	for (int i = 0; i < strlen(in); i++){
		switch (in[i]){
		case '+': rnk[i] = 3; break;
		case '-': rnk[i] = 3; break;
		case '*': rnk[i] = 4; break;
		case '/': rnk[i] = 4; break;
		case '^': rnk[i] = 5; break;
		case '(': rnk[i] = -2; break;
		case ')': rnk[i] = 2; break;
		case '\0': rnk[i] = 0; break;
		default: rnk[i] = 1;
		}
	}
}

bool valid()
{
	bool invalid = false;
	for (int i = 1; i < strlen(in); i++){
		if (rnk[i] >= 3 && rnk[i - 1] >= 3){
			invalid = true;
			break;
		}
		else
			invalid = false;
	}
	return invalid;
}

void postfix()
{
	int ctr = 0, grp = 0, pos = 0, sel = 0;
	for (; ctr < strlen(in); ctr++){
		if (rnk[ctr] == 1){
			post[sel] = in[ctr];
			sel++;
		}
		else if (rnk[ctr] >= 3 && rnk[ctr] <= 5){
			if (rnk[ctr] <= opr[pos - 1] && pos != 0)
				for (; rnk[ctr] <= opr[pos - 1]; pos--, sel++){
				post[sel] = op[pos - 1];
				opr[pos-1] = 0;
				op[pos-1] = NULL;
				}
			opr[pos] = rnk[ctr];
			op[pos] = in[ctr];
			++pos;
		}
		else if (rnk[ctr] == 2){
			opr[pos] = rnk[ctr];
			op[pos] = in[ctr];
			++grp;
			++pos;
		}
		else if (rnk[ctr] == -2){
			for (; opr[pos - 1] != 2; sel++, pos--){
				post[sel] = op[pos - 1];
				opr[pos - 1] = 0;
				op[pos - 1] = NULL;
			}
			--pos;
			--grp;
			opr[pos] = 0;
			op[pos] = NULL;
		}
	}
	for (; (pos - 1) >= 0; sel++, pos--)
		post[sel] = op[pos - 1];
}

void prefix()
{
	int ctr = 0, grp = 0, pos = 0, sel = 0;
	for (; ctr < strlen(in); ctr++){
		if (rnk[ctr] == 1){
			pre[sel] = in[ctr];
			sel++;
		}
		else if (rnk[ctr] >= 3 && rnk[ctr] <= 5){
			if (rnk[ctr] < opr[pos - 1] && pos != 0)
				for (; rnk[ctr] < opr[pos - 1]; pos--, sel++){
				pre[sel] = op[pos - 1];
				opr[pos - 1] = 0;
				op[pos - 1] = NULL;
				}
			opr[pos] = rnk[ctr];
			op[pos] = in[ctr];
			++pos;
		}
		else if (rnk[ctr] == 2){
			opr[pos] = rnk[ctr];
			op[pos] = in[ctr];
			++grp;
			++pos;
		}
		else if (rnk[ctr] == -2){
			for (; opr[pos - 1] != 2; sel++, pos--){
				pre[sel] = op[pos - 1];
				opr[pos - 1] = 0;
				op[pos - 1] = NULL;
			}
			--pos;
			--grp;
			opr[pos] = 0;
			op[pos] = NULL;
		}
	}
	for (; (pos - 1) >= 0; sel++, pos--)
		pre[sel] = op[pos - 1];
}