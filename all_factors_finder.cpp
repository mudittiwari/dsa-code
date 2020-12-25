#include<bits/stdc++.h>
using namespace std;

vector<int> find_divisors(int a)
{
	vector<int> answers;
	for(int i=1;i<=sqrt(a);i++)
	{
		if(a%i==0)
		{
			if(a/i==i)
				answers.push_back(i);
			else
			{
				answers.push_back(i);
				answers.push_back(a/i);
			}
		}
	}
	return answers;
}

int main()
{
	int n;
	cout<<"type the number whose divisors you want to find";
	cin>>n;
	vector<int> arr;
	arr=find_divisors(n);
	for(int i=0;i<arr.size();i++)
		cout<<arr[i]<<endl;
	return 0;
}
