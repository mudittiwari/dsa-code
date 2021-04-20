#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node *next;
};

Node *root;
void insertion(int value)
{
	Node *toinsert = new Node;
	toinsert->data = value;
	toinsert->next = NULL;
	if (root)
	{
		Node *temp = root;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = toinsert;
	}
	else
		root = toinsert;
}
void print(Node *root)
{
	while (root != NULL)
	{
		cout << root->data << " ";
		root = root->next;
	}
}
int findlength()
{
	int len = 0;
	Node *temp = root;
	while (temp != NULL)
	{
		temp = temp->next;
		len++;
	}
	return len;
}
int main()
{
	int size;
	cout << "type the size of the list" << endl;
	cin >> size;
	while (size--)
	{
		int value;
		cout << "type the value you want to insert" << endl;
		cin >> value;
		insertion(value);
	}
	int lenght = findlength();
	int k;
	cout << "type the value of k" << endl;
	cin >> k;
	Node *tempone = root;
	Node *temptwo = root;
	Node *temp = root;
	Node *tmp = root;
	int i = 1;
	int len = findlength();
	if (k > (len / 2))
		k = len - k + 1;
	while (i < k)
	{
		tempone = temp;
		temp = temp->next;
		i++;
	}
	// cout<<"mudit"<<endl;
	i = 1;
	while (i <= (len - k))
	{
		// cout<<"mudit"<<endl;
		temptwo = tmp;
		tmp = tmp->next;
		i++;
	}
	// cout<<tempone->data<<endl;
	// cout<<temptwo->data<<endl;
	// cout<<temp->data<<endl;
	// cout<<tmp->data<<endl;
	if(len%2==0 && k==len/2)
	{
		tempone->next=tmp;
		temp->next=tmp->next;
		tmp->next=temp;
	}
	else if(len%2!=0 && k==((len/2)+1))
	{
		print(root);
		return 0;
	}
	else if (tempone == temp)
	{
		root=root->next;
		temptwo->next=tmp->next;
		temp->next=tmp->next=NULL;
		tmp->next = root;
		root=tmp;
		temptwo->next=temp;
	}
	else
	{
		tempone->next = temp->next;
		temptwo->next = tmp->next;
		temp->next = tmp->next = NULL;
		tmp->next = tempone->next;
		tempone->next = tmp;
		temp->next = temptwo->next;
		temptwo->next = temp;
	}
	print(root);
	return 0;
}
