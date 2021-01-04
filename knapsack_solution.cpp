#include<bits/stdc++.h>
using namespace std;

int dp[5][9];
int dp2[5][9];

int knapsack(vector<int> arr,vector<int> price,int total,int n)
{
	if(total==0 || n==0)
	{
		dp[n][total]=0;
		return 0;
	}
	else if(dp[n][total]!=-1)
		return dp[n][total];
	else if(arr[n-1]<=total)
	{
		return dp[n][total]=max(price[n-1]+knapsack(arr,price,total-arr[n-1],n-1),
			knapsack(arr,price,total,n-1));
	}
	else
		return dp[n][total]=knapsack(arr,price,total,n-1);
}
int main()
{
	memset(dp,-1,sizeof(dp));
	vector<int> arr={2,5,3,4};
	vector<int> price={1,2,3,4};
	int weight=8;
	int ans=knapsack(arr,price,weight,arr.size());
	cout<<ans<<endl;
	for(int j=0;j<=8;j++)
		dp2[0][j]=0;
	for(int i=0;i<=4;i++)
		dp2[i][0]=0;
	for(int i=1;i<=4;i++)
	{
		for(int j=1;j<=8;j++)
		{
			if(arr[i-1]<=j)
			{
				dp2[i][j]=max(price[i-1]+knapsack(arr,price,j-arr[i-1],i-1),
			knapsack(arr,price,j,i-1));
			}
			else
				dp2[i][j]=knapsack(arr,price,j,i-1);
		}
	}
	for(int i=0;i<=4;i++)
	{
		for(int j=0;j<=8;j++)
		{
			cout<<dp2[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
