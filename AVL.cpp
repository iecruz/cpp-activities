#include <iostream>
#include <algorithm>

using namespace std;

struct Node{
	int data;
	Node*left;
	Node*right;
	Node*parent;
}*root;

Node*insert(Node*, int);
void search(Node*, int);
void display(Node*, int);
Node*del(Node*,int);
int depth(Node*);
Node*balance(Node*);

int main()
{
	int choice;
	int input;
	root = NULL;
	while (true){
		system("cls");
		cout << endl << "     [ A V L   T R E E ]\n\n"
			<< " [1] INSERT DATA\n"
			<< " [2] DELETE DATA\n"
			<< " [3] SEARCH DATA\n"
			<< " [4] VIEW TREE\n"
			<< " [5] EXIT\n\n"
			<< "     Enter Choice: "; cin >> choice;
		switch (choice)
		{
		case 1:
			cout << endl << "     Enter New Data: "; cin >> input;
			root = insert(root, input);
			break;
		case 2:
			cout << endl << "     Enter Data: "; cin >> input;
			root = del(root, input);
			//if (root != NULL)
				//reset(root);
			system("pause>0");
			break;
		case 3:
			cout << endl << "     Enter Data: "; cin >> input;
			cout << "     OUTPUT: ";
			search(root, input);
			system("pause>0");
			break;
		case 4:
			if (root != NULL){
				system("cls");
				display(root, 1);
			}
			else
				cout << endl << "     TREE IS EMPTY!";
			system("pause>0");
			break;
		case 5:
			exit(1);
			break;
		default:
			cout << endl << "     INVALID INPUT!";
			system("pause>0");
		}
	}
}

// INSERT

Node*insert(Node*root, int x)
{
	if (root == NULL){
		root = new Node;
		root->left = NULL;
		root->right = NULL;
		root->data = x;
		return root;
	}
	else if (x >= root->data){
		root->right = insert(root->right, x);
		root = balance(root);
	}
	else if (x < root->data){
		root->left = insert(root->left, x);
		root = balance(root);
	}
	return root;
}

// SEARCH (WITH PATH)

void search(Node*root, int x)
{
	if (root == NULL)
		cout << "DATA NOT FOUND!";
	else{
		cout << root->data << " ";
		if (x > root->data)
			search(root->right, x);
		else if (x < root->data)
			search(root->left, x);
		else
			cout << "DATA FOUND!";
	}
}

// DISPLAY

void display(Node *ptr, int level)
{
	if (ptr != NULL){
		display(ptr->right, level + 1);
		printf("\n");
		if (ptr == root)
			cout << "Root -> ";
		for (int i = 0; i < level && ptr != root; i++)
			cout << "        ";
		cout << ptr->data;
		display(ptr->left, level + 1);
	}
}

// DELETE

Node*del(Node*root, int x)
{
	Node*tmp;
	if (root == NULL){
		cout << endl << "     DATA DOESN'T EXIST!";
		return root;
	}
	else if (x > root->data){
		root->right = del(root->right, x);
		root = balance(root);
	}
	else if (x < root->data){
		root->left = del(root->left, x);
		root = balance(root);
	}
	else{
		if (root->left == NULL && root->right == NULL){
			tmp = root;
			root = NULL;
			free(tmp);
			cout << endl << "     DATA DELETED!";
		}
		else if (root->left == NULL){
			tmp = root->right;
			*root = *root->right;
			free(tmp);
			cout << endl << "     DATA DELETED!";
		}
		else if (root->right == NULL){
			tmp = root->left;
			*root = *root->left;
			free(tmp);
			cout << endl << "     DATA DELETED!";
		}
		else{
			tmp = root->right;
			while (tmp->left != NULL)
				tmp = tmp->left;
			root->data = tmp->data;
			root->right = del(root->right, tmp->data);
		}
	}
	return root;
}

// BALANCE

int depth(Node*root)
{
	if (root != NULL)
	return max(depth(root->right), depth(root->left)) + 1;
}

int diff(Node*root)
{
	return depth(root->left) - depth(root->right);
}

Node*rr_rotation(Node*root)
{
	Node*tmp;
	tmp = root->right;
	root->right = tmp->left;
	tmp->left = root;
	return tmp;
}

Node*ll_rotation(Node*root)
{
	Node*tmp;
	tmp = root->left;
	root->left = tmp->right;
	tmp->right = root;
	return tmp;
}

Node*lr_rotation(Node*root)
{
	Node*tmp;
	tmp = root->left;
	root->left = rr_rotation(tmp);
	return ll_rotation(root);
}

Node*rl_rotation(Node*root)
{
	Node*tmp;
	tmp = root->right;
	root->right = ll_rotation(tmp);
	return rr_rotation(root);
}

Node*balance(Node*tmp)
{
	if (diff(tmp) > 1)
	{
		if (diff(tmp->left) > 0)
			tmp = ll_rotation(tmp);
		else
			tmp = lr_rotation(tmp);
	}
	else if (diff(tmp) < -1)
	{
		if (diff(tmp->right) > 0)
			tmp = rl_rotation(tmp);
		else
			tmp = rr_rotation(tmp);
	}
	return tmp;
}