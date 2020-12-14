// code for binary search

#include<bits/stdc++.h>
using namespace std;

int main()
{
	int size;
	cout<<"type the lenght of the array";
	cin>>size;
	vector<int> arr(size);
	cout<<"\ntype the array";
	for(int i=0;i<size;i++)
		cin>>arr[i];
	sort(arr.begin(),arr.end());
	while(1)
	{
		cout<<"\ntype the element you want to search";
		int element;
		cin>>element;
		int left=0;
		int right=size-1;
		int middle;
		while(left!=right)
		{
			middle=(left+right)/2;
			if(arr[middle]==element)
			{
				cout<<"the element is present at "<<middle+1<<" posi";
				break;
			}
			else if(arr[middle]<element)
				left=middle+1;
			else
				right=middle-1;
		}
		if(left==right)
			if(arr[left]==element)
				cout<<"the element is found at "<<left+1<<" posi";
	}
	return 0;
}
