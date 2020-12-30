#include<bits/stdc++.h>
using namespace std;

vector<int> merge_sort(vector<int> arr)
{
	if(arr.size()==1)
		return arr;
	vector<int> arr_one(arr.begin(),arr.begin()+(arr.size()/2));
	vector<int> arr_two(arr.begin()+(arr.size()/2),arr.end());
	arr_one=merge_sort(arr_one);
	arr_two=merge_sort(arr_two);
	vector<int> final_vector;
	int i=0,j=0;
	for(int k=0;k<arr.size();k++)
	{
		if(j==arr_two.size())
		{
			// copy first array now
			for(int temp=i;temp<arr_one.size();temp++)
				final_vector.push_back(arr_one[temp]);
			break;
		}
		else if(i==arr_one.size())
		{
			for(int temp=j;temp<arr_two.size();temp++)
				final_vector.push_back(arr_two[temp]);
			break;
		}
		else if(arr_one[i]<arr_two[j])
		{
			final_vector.push_back(arr_one[i]);
			i++;
		}
		else
		{
			final_vector.push_back(arr_two[j]);
			j++;
		}
	}
	return final_vector;
}

int main()
{
	int n;
	cout<<"type the size of the array"<<endl;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++)
		cin>>arr[i];
	vector<int> final_array=merge_sort(arr);
	for(int i=0;i<n;i++)
		cout<<final_array[i]<<endl;
	return 0;
}
