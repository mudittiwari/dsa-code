#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node *left;
	Node *right;
};
Node *root = NULL;
unordered_map<int, Node *> map_;
void traversal(Node *root,string s)
{
	if(!root->left && !root->right)
	{
		// cout<<s<<" ";
		return ;
	}
	cout<<root->data<<" ";
	traversal(root->left,s+='0');
	s.pop_back();
	traversal(root->right,s+='1');
	s.pop_back();
}
int main()
{
	int n;
	cin >> n;
	priority_queue<int> q;
	for (int i = 0; i < n; i++)
	{
		int value;
		cin >> value;
		q.push((value) * (-1));
	}
	while (q.size()!=1)
	{
		// cout<<q.size();
		int val1 = q.top() * -1;
		q.pop();
		int val2 = q.top() * -1;
		q.pop();
		// cout<<val1<<" "<<val2<<endl;
		Node *temp;
		temp = new Node;
		temp->data = val1 + val2;
		if (map_.find(val1) == map_.end() && map_.find(val2) == map_.end())
		{
			Node *node1 = new Node;
			node1->data = val1;
			node1->left = node1->right = NULL;
			Node *node2 = new Node;
			node2->data = val2;
			node2->left = node2->right = NULL;
			temp->left = node1;
			temp->right = node2;
			map_.insert(make_pair(temp->data, temp));
		}
		else if (map_.find(val1) != map_.end() && map_.find(val2) != map_.end())
		{
			// cout<<val1<<" "<<val2<<endl;
			temp->left = map_[val1];
			temp->right = map_[val2];
			map_.erase(val2);
			map_.erase(val1);
			map_.insert(make_pair(temp->data, temp));
		}
		else if (map_.find(val2) != map_.end() && map_.find(val1) == map_.end())
		{
			Node *node1 = new Node;
			node1->data = val1;
			node1->left = node1->right = NULL;
			temp->left = node1;
			temp->right = map_[val2];
			map_.erase(val2);
			map_.insert(make_pair(temp->data, temp));
		}
		else
		{
			Node *node1 = new Node;
			node1->data = val2;
			node1->left = node1->right = NULL;
			temp->left = map_[val1];
			temp->right = node1;
			map_.erase(val1);
			map_.insert(make_pair(temp->data, temp));
		}
		if(q.empty())
			root=temp;
		// traversal(temp);
		// cout<<endl;
		q.push((val1 + val2) * -1);
	}
	traversal(root,"");
	return 0;
}
