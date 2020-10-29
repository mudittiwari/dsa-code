// this is the program to find the value of gcd of two numbers using 
// ecludin algo
#include<bits/stdc++.h>
using namespace std;

int findgcd(int a,int b)
{
	if(a%b==0)
		return b;
	else
		return(findgcd(b,a%b));
}

int main()
{
	cout<<"type the two numbers"<<endl;
	int a,b;
	cin>>a>>b;
	if(a>b)
		cout<<findgcd(a,b);
	else
		cout<<findgcd(b,a);
	return 0;
}
