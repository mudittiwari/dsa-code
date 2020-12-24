// insertion sort algo
#include<bits/stdc++.h>
using namespace std;

vector<int> selection_sort(vector<int> arr)
{
	for(int i=0;i<arr.size();i++)
	{
		int min=i;
		for(int j=i+1;j<arr.size();j++)
			if(arr[j]<arr[min])
				min=j;
		swap(arr[i],arr[min]);
	}
	return arr;
}

int main()
{
	int n;
	cout<<"type the size of the array"<<endl;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++)
		cin>>arr[i];
	vector<int> final_array;
	final_array=selection_sort(arr);
	for(int i=0;i<n;i++)
		cout<<final_array[i]<<" ";
	return 0;
}
