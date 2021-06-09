// this algorithm can only be used when array elements are not changing
// time complexity::
	// O(k)---forqueries
	// O(n)---for finding cumulative sum of prefix array
	// O(n)---for adding both the arrays
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cout<<"type the size of the array"<<endl;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	int q;
	cout<<"type the number of queries"<<endl;
	cin>>q;
	vector<int> prefix_sum(n);
	while(q--)
	{
		int leftindex;
		int rightindex;
		cout<<"type the value of left and right index"<<endl;
		cin>>leftindex>>rightindex;
		cout<<"type the value to add"<<endl;
		int toadd;
		cin>>toadd;
		if(rightindex==(n-1))
		{
			prefix_sum[leftindex]+=toadd;
		}
		else
		{
			prefix_sum[leftindex]+=toadd;
			prefix_sum[rightindex+1]-=toadd;
		}
	}
	for(int i=1;i<n;i++)
	{
		prefix_sum[i]=prefix_sum[i]+prefix_sum[i-1];
	}
	for(int i=0;i<n;i++)
	{
		arr[i]=arr[i]+prefix_sum[i];
	}
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";  
	}
	return 0;
}
