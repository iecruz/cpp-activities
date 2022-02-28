#include <iostream>
#include <algorithm>
#include <Windows.h>
#include <cmath>

using namespace std;

struct Node
{
	int data;
	int H = 1;
	int B = 0;
	bool scan = false;
	Node *U = NULL;
	Node *L = NULL;
	Node *R = NULL;
}*root, *tmp, *ptr, *check;

bool bal = true;
int X = 3, Y = 11, YT, lvl = 1;

void XY(int x, int y)
{
	COORD POS = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), POS);
}

Node* insert(Node*,int);
Node* balance(Node*);
void search();
void reset(Node*);
void display(Node*,int);

int main()
{
	int choice, x;
	while (true)
	{
		system("cls");
		cout << "\n     [ A V L   T R E E ]\n\n"
			<< " [1] INSERT\n"
			<< " [2] SEARCH\n"
			<< " [3] DISPLAY\n"
			<< " [4] EXIT\n\n"
			<< "     Enter: "; cin >> choice;
		cout << endl;
		switch (choice)
		{
		case 1:
			cout << "     Enter Value: "; cin >> x;
			root = insert(root, x);
			//reset(root);
			break;
		case 2:
			//reset(root);
			//if (!bal){
			//	balance(check);
			//	bal = true;
			//}
			search(); system("pause>0"); break;
		case 3:
			system("cls");
			//reset(root);
			//if (!bal){
			//	balance(check);
			//	bal = true;
			//}
			display(root, 1); system("pause>0"); break;
		case 4: exit(1);
		default: cout << "INVALID INPUT!"; system("pause>0");
		}
	}
}

Node *insert(Node*root, int data)
{
		if (root == NULL)
		{
			root = new Node;
			root->data = data;
			root->L = NULL;
			root->R = NULL;
			return root;
		}
		else if (data < root->data)
		{
			root->L = insert(root->L, data);
			root = balance(root);
		}
		else if (data >= root->data)
		{
			root->R = insert(root->R, data);
			root = balance(root);
		}
		return root;
}

/*void insert()
{
	ptr = root;
	while (ptr != NULL){
		//ptr->H = depth(ptr)+1;
		if (ptr != NULL && (ptr->B > 1 || ptr->B < -1)){
			check = ptr;
			bal = false;
		}
		if (tmp->data >= ptr->data){
			if (ptr->R == NULL){
				//ptr->B = depth(ptr->R) - depth(ptr->L) + 1;
				tmp->U = ptr;
				ptr->R = tmp;
				break;
			}
			else{
				//ptr->B = depth(ptr->R) - depth(ptr->L) + 1;
				ptr = ptr->R;
			}
		}
		else{
			if (ptr->L == NULL){
				//ptr->B = depth(ptr->R) - depth(ptr->L) - 1;
				tmp->U = ptr;
				ptr->L = tmp;
				break;
			}
			else{
				//ptr->B = depth(ptr->R) - depth(ptr->L) - 1;
				ptr = ptr->L;
			}
		}
	}
	root = balance(root);
}*/

int depth(Node *N)
{
	if (N != NULL)
		return max(depth(N->L), depth(N->R))+1;
}

int status(Node *N)
{
//	int l_height = depth(N->L);
//	int r_height = depth(N->R);
	return depth(N->L) - depth(N->R);
}

Node *RR(Node*N)
{
	Node *tmp;
	tmp = N->R;
	N->R = tmp->L;
	tmp->L = N;
	return tmp;
}

Node *LL(Node*N)
{
	Node *tmp;
	tmp = N->L;
	N->L = tmp->R;
	tmp->R = N;
	return tmp;
}

Node *LR(Node*N)
{
	Node *tmp;
	tmp = N->L;
	N->L = RR(tmp);
	return LL(N);
}

Node *RL(Node*N)
{
	Node *tmp;
	tmp = N->R;
	N->R = LL(tmp);
	return RR(N);
}

Node *balance(Node *ptr)
{
	if (status(ptr) > 1)
	{
		if (status(ptr->R) > 0)
			ptr = LL(ptr);
		else
			ptr = LR(ptr);
	}
	else if (status(ptr) < -1)
	{
		if (status(ptr->L) > 0)
			ptr = RL(ptr);
		else
			ptr = RR(ptr);
	}
	return ptr;
}

void search()
{
	bool found = false;
	tmp = root;
	int x;
	cout << "     Enter Key Value: "; cin >> x;
	cout << "\n     Output: ";
	while (tmp != NULL)
	{
		cout << tmp->data << " ";
		if (x == tmp->data){
			cout << "FOUND!";
			found = true;
			break;
		}
		else if (x > tmp->data)
			tmp = tmp->R;
		else
			tmp = tmp->L;
	}
	if (!(found))
		cout << x << " NOT FOUND!";
}

void reset(Node*N)
{
	if (N)
	{
		N->B = depth(N->R) - depth(N->L);
		N->H = depth(N);
		if (N != NULL && (N->B > 1 || N->B < -1)){
			//check = N;
			//cout << N->data;
			N = balance(N);
		}
		reset(N->L);
		reset(N->R);
	}
		
}

void display(Node*N, int level)
{
	if (N != NULL)
	{
		display(N->R, level + 1);
		printf("\n");
		if (N == root)
			cout << "Root -> ";
		for (int i = 0; i < level && N != root; i++)
			cout << "        ";
		cout << N->data;
		display(N->L, level + 1);
	}
}