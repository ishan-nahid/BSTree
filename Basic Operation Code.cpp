#include <iostream>
#include <cstdlib>

using namespace std;

struct Node
{
	int data;
	Node *left, *right;
}*root = NULL;

void insert();
void pre_order(Node *node);
void post_order(Node *node);
void in_order(Node *node);

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	insert();

	pre_order(root);
	cout << endl;
	post_order(root);
	cout << endl;
	in_order(root);
	cout << endl;
	return 0;
}

void insert()
{
	int n;
	//cout << "How many node you want to insert: ";
	cin >> n;

	root = (Node*)malloc(sizeof(Node));
	cin >> root->data;
	root->left = NULL;
	root->right = NULL;

	Node *temp, *current, *parent;

	for(int i = 1; i < n; i++)
	{
		temp = (Node*)malloc(sizeof(Node));
		cin >> temp->data;
		temp->left = NULL;
		temp->right = NULL;

		current = root, 
		parent = NULL;

		while(true)
		{
			parent = current;
			if(temp->data > parent->data)
			{
				current = current->right;
				if(current == NULL)
				{
					parent->right = temp;
					break;
				}
			}
			else
			{
				current = current->left;
				if(current == NULL)
				{
					parent->left = temp;
					break;
				}
			}
		}
	}
}

void pre_order(Node *node)
{
	if(node == NULL)
	{
		return;
	}

	cout << node->data << endl;
	pre_order(node->left);
	pre_order(node->right);
	
}

void post_order(Node *node)
{
	if(node == NULL)
	{
		return;
	}
	post_order(node->left);
	post_order(node->right);

	cout << node->data << endl;
}

void in_order(Node *node)
{
	if(node == NULL)
	{
		return;
	}
	in_order(node->left);
	cout << node->data << endl;
	in_order(node->right);
}
