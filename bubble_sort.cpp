// bubble sort algorithm
#include<bits/stdc++.h>
using namespace std;

vector<int> bubble_sort(vector<int> arr)
{
	int swap_count;
	for(int i=arr.size()-1;i>=0;i--)
	{
		swap_count=0;
		for(int j=0;j<i;j++)
			if(arr[j]>arr[j+1])
			{
				swap_count++;
				swap(arr[j],arr[j+1]);
			}
		if(swap_count==0)
			return arr;
	}
	return arr;
}

int main()
{
	int n;
	cout<<"Type the size of the array"<<endl;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++)
		cin>>arr[i];
	vector<int> arrfinal;
	arrfinal=bubble_sort(arr);
	for(int i=0;i<n;i++)
		cout<<arrfinal[i]<<" ";
	return 0;
}
