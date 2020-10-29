// program for finding modulo multiplicative inverse
// (a.b)%m==1 formula of modulo multiplicative inverse
#include <bits/stdc++.h>
using namespace std;

int findm(int a,int m)
{
	for(int i=1;i<m;i++)
		if(((a%m)*(i%m))%m==1)
			return i;
	return -1;
}

int main()
{
	cout<<"Type the value of number and m"<<endl;
	int a,m;
	cin>>a>>m;
	cout<<findm(a,m);
	return 0;
}
