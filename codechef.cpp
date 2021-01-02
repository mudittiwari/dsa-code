#include<bits/stdc++.h>
using namespace std;

vector< vector<int> > final_ans;
vector<int> arr;
int min_lenght = INT_MAX;
void find_subone(vector<int> prev, int index, int sum, int k)
{
	if (index == arr.size())
	{
		if (sum >= k && prev.size() <= min_lenght)
		{
			final_ans.push_back(prev);
			min_lenght = prev.size();
		}
		return;
	}
	find_subone(prev, index + 1, sum, k);
	prev.push_back(arr[index]);
	find_subone(prev, index + 1, sum + arr[index], k);
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int ans=0;
		vector<int> seive(10000);
		arr.clear();
		final_ans.clear();
		min_lenght = INT_MAX;
		int n, k;
		cin >> n >> k;
		for (int i = 0; i < n; i++)
		{
			int var;
			cin >> var;
			arr.push_back(var);
		}
		vector<int> prev;
		find_subone(prev, 0, 0, k);
		if (final_ans.size() == 0)
			cout << "-1" << endl;
		else
		{
			for (int i = 0; i < final_ans.size(); i++)
			{
				if (final_ans[i].size() != min_lenght)
					final_ans.erase(final_ans.begin() + i);
			}
			if (final_ans.size() > 1)
			{
				
			}
		}
	}
	return 0;
}



// for (int i = 0; i < final_ans.size(); i++)
// 		{
// 			for (int j = 0; j < final_ans[i].size(); j++)
// 				cout << final_ans[i][j] << " ";
// 			cout << endl;
// 		}
