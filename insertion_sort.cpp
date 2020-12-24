// insertion sort algorithm
#include<bits/stdc++.h>
using namespace std;

vector<int> insertion_sort(vector<int> arr)
{
	for(int i=1;i<arr.size();i++)
	{
		bool swapped=false;
		int temp=arr[i];
		int j;
		for(j=i-1;j>=0;j--)
		{
			if(temp<arr[j])
			{
				swapped=true;
				arr[j+1]=arr[j];
			}
			else
				break;
		}
		if(swapped)
			arr[j+1]=temp;
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
	vector<int> arr_final;
	arr_final=insertion_sort(arr);
	for(int i=0;i<n;i++)
		cout<<arr_final[i]<<" ";
	return 0;
}
