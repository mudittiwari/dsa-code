// to find the reverse level order traversal we have to 
// check the right first in level order traversal condition
// then we have to push them in the linked list at the 
// begin to get the reverse level order traversal output

void traversal()
{
	queue<bnode *> que;
	que.push(root);
	list<int> li;
	list<int>::iterator itr;
	while (!que.empty())
	{
		li.push_front((que.front())->value);
		if ((que.front())->right)
			que.push((que.front())->right);
		if ((que.front())->left)
			que.push((que.front())->left);
		que.pop();
	}
	for(itr=li.begin();itr!=li.end();itr++)
		cout<<*(itr)<<"\t";
	cout << "\n";
}
