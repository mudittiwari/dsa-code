// binary exponentiation program to find the exponent of a number 
// efficiently
#include<bits/stdc++.h>
using namespace std;

int findpower(int a,int pow)
{
	if(pow==1)
		return a;
	if(pow%2==0)
		return (findpower(a*a,pow/2));
	else	
		return (a*findpower(a,pow-1));
}

int main()
{
	int a;
	cout<<"type the number whose power you want to find";
	cin>>a;
	int b;
	cout<<"type the power"<<endl;
	cin>>b;
	cout<<findpower(a,b);
	return 0;
}
