#include<bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	node *right;
	node *left;
};
node *root = NULL;
bool found = false;
node *parent;
void findposi(int value, node *root)
{
	if (!found)
	{
		if (value > root->data)
		{
			if (root->right)
				findposi(value, root->right);
			else
			{
				parent = root;
				found = true;
				return;
			}
		}
		else
		{
			if(value<root->data)
			{
				if(root->left)
					findposi(value,root->left);
				else
				{
					parent=root;
					found=true;
					return;
				}
			}
		}
	}
}
void insertion(int value)
{
	node *temp = new node;
	temp->data = value;
	temp->left = temp->right = NULL;
	if (root)
	{
		findposi(value,root);
		if(value>parent->data)
			parent->right=temp;
		else
			parent->left=temp;
		found=false;
	}
	else
		root = temp;
}

void traversal(node *root)
{
	if(root)
	{
		cout<<root->data<<" ";
		traversal(root->left);
		traversal(root->right);
	}
}

int main()
{
	cout << "type the size of the tree" << endl;
	int size;
	cin >> size;
	while (size--)
	{
		int value;
		cout << "type the value you want to insert" << endl;
		cin >> value;
		insertion(value);
	}
	traversal(root);
	return 0;
}
