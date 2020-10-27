#include<bits/stdc++.h>
using namespace std;


struct binarytree
{
	int value;
	binarytree *left;
	binarytree *right;
};

binarytree * root = NULL;
bool found=false;
binarytree *addr=NULL;
void findnode(int value, binarytree *root)
{
	if (root)
	{
		if (root->value == value)
		{
			addr=root;
			found=true;
		}
		if(!found)
			findnode(value,root->left);
		else
			return;
		if(!found)
			findnode(value,root->right);
		else
			return;
	}
}

void insertion(int value, int posi, char dir)
{
	binarytree *node;
	node = new binarytree;
	node->value = value;
	node->left = node->right = NULL;
	if (root == NULL)
		root = node;
	else
	{
		findnode(posi, root);
		if (dir == 'L')
			addr->left = node;
		else
			addr->right = node;
	}
}
void traversal(binarytree *root)
{
	if (root)
	{
		cout << root->value<<"\t";
		traversal(root->left);
		traversal(root->right);
	}
	else
		return;
}

int main()
{
	// insertion(1,1,'L');
	// found=false;
	// addr=NULL;

	// insertion(2,1,'L');
	// found=false;
	// addr=NULL;

	// insertion(3,1,'R');
	// found=false;
	// addr=NULL;

	// insertion(4,2,'L');
	// found=false;
	// addr=NULL;

	// insertion(5,2,'R');
	// found=false;
	// addr=NULL;

	// traversal(root);
	int value;
	int choice;
	int v1;
	char a;
	while(1)
	{
		cout<<"1. insertion in binary tree\n";
		cout<<"2. traversal in binary tree\n";
		cout<<"3. exit\n";
		cout<<"enter your choice\n";
		cin>>choice;
		switch(choice)
		{
			case 1:
				cout<<"type the value you want to insert\n";
				cin>>value;
				cout<<"type the value at which you want to insert\n";
				cin>>v1;
				cout<<"type the posi where you want to insert\n";
				cin>>a;
				found=false;
				addr=NULL;
				insertion(value,v1,a);
				break;
			case 2:
				traversal(root);
				cout<<endl;
				break;
			case 3:
				exit(0);
				break;
		}
	}
	return 0;
}