// second method for fast exponentiation
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,power;
	cout<<"type the number you want to find power"<<endl;
	cin>>n;
	cout<<"type the power"<<endl;
	cin>>power;
	int res=1;
	while(power>0)
	{
		if(power%2!=0)
		{
			res=res*n;
		}
		n=n*n;
		power=power/2;
	}
	cout<<res<<endl;
	return 0;
}
