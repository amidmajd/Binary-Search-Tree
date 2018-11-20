//#include "stdafx.h"
#include <iostream>
//#include <conio.h>
//#include <windows.h>
#include <iomanip>
#include <stdlib.h>


using namespace std;
void menu();


struct BstNode
{
	int data;
	BstNode* leftChild;
	BstNode* rightChild;
};



BstNode* CreatNewNode(int data)
{
	BstNode* newNode = new BstNode();
	newNode->data = data;
	newNode->leftChild = NULL;
	newNode->rightChild = NULL;
	return newNode;
}

BstNode* Insert(BstNode* root, int data)
{
	if (root == NULL)
	{
		root = CreatNewNode(data);
	}
	else if (data == root->data)
	{
		cout << "Aleady this data exist." << endl << endl;
	}
	else if (data < root->data)
	{
		root->leftChild = Insert(root->leftChild, data);
	}
	else if (data > root->data)
	{
		root->rightChild = Insert(root->rightChild, data);
	}
	return root;
}

bool Search(BstNode* root, int data)
{
	if (root == NULL) { return false; }
	else if (data == root->data) { return true; }
	else if (data < root->data) return  Search(root->leftChild, data);
	else if (data > root->data) return  Search(root->rightChild, data);

}

BstNode* FindMin(BstNode* root)
{
	if (root->leftChild == NULL) { return root; }
	else { return FindMin(root->leftChild); }
}

BstNode* Delete(BstNode* root, int data)
{
	if (root == NULL) return root;

	else if (data < root->data)
	{
		root->leftChild = Delete(root->leftChild, data);
	}
	else if (data > root->data)
	{
		root->rightChild = Delete(root->rightChild, data);
	}
	else    //key found
	{
		if (root->leftChild == NULL && root->rightChild == NULL)    //0 child
		{
			delete root;
			root = NULL;
		}
		else if (root->leftChild == NULL)    //1 child
		{
			BstNode* temp = root;
			root = root->rightChild;
			delete temp;
		}
		else if (root->rightChild == NULL)    //1 child
		{
			BstNode* temp = root;
			root = root->leftChild;
			delete temp;
		}
		else                                  //2 child
		{
			BstNode* temp = FindMin(root->rightChild);
			root->data = temp->data;
			root->rightChild = Delete(root->rightChild, temp->data);
		}
	}

	return root;
}

void Display(BstNode* root)
{
	if (root != NULL)
	{
		cout << " (" << root->data << ")";
		Display(root->leftChild);
		Display(root->rightChild);
	}

}


int main()
{
	menu();

	return 0;
}

void menu()
{
	BstNode* root = NULL;
	int select;
	char ch;
	do
	{
		system("clear");
		//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << endl << endl;
		cout << "0.Exit" << endl;
		cout << "1.Insert" << endl;
		cout << "2.Display" << endl;
		cout << "3.Search" << endl;
		cout << "4.Delete" << endl;
		cout << "Enter Option : ";
		cin >> select;
		//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		system("clear");
		switch (select)
		{
		case 0:
			break;
		case 1:

			do
			{
				int data;
				cout << "Enter Data = ";
				cin >> data;
				root = Insert(root, data);
				cout << "Do you want to add new data?[y/n] ";
				cin >> ch;
				cout << endl;
			} while (ch != 'n');
			break;
		case 2:
			if (root == NULL)
			{
				cout << "Empty Tree" << endl;
			}
			else
			{
				Display(root);
			}
			cout << endl << endl << endl << "Enter any key to Continue ... ";
			system("read 1");
			break;
		case 3:
			do
			{
				int key;
				cout << "Enter data for search = ";
				cin >> key;
				if (root == NULL && Search(root, key) == false) { cout << "Empty Tree" << endl; }
				else if (Search(root, key) == true) { cout << "Found" << endl; }
				else { cout << "Not Found" << endl; }
				cout << "Do you want to search for another data ?[y/n] ";
				cin >> ch;
				cout << endl;
			} while (ch != 'n');
			break;
		case 4:
			do
			{
				int key;
				cout << "Enter data for Delete = ";
				cin >> key;
				if (root == NULL ) { cout << "Empty Tree" << endl; }
				else if( Search(root, key) == false) { cout << "Not Found" << endl; }
				else
				{
					Delete(root, key);
					cout << endl;
				}
				cout << "Do you want to Delete another data ?[y/n] ";
				cin >> ch;
				cout << endl;
			} while (ch != 'n');
			break;
		}

	} while (select != 0);

}

