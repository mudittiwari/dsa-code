#include<bits/stdc++.h>
using namespace std;

vector<string> ans;
void find_sub(string s,int index,string temp)
{
	if(index==s.length())
	{
		ans.push_back(temp);
		return ;
	}
	temp+=s[index];
	find_sub(s,index+1,temp);
	temp.erase(temp.end()-1);
	find_sub(s,index+1,temp);
}

int main()
{
	string s;
	cout<<"type the string"<<endl;
	cin>>s;
	find_sub(s,0,"");
	for(int i=0;i<ans.size();i++)
		cout<<ans[i]<<endl;
	return 0;
}
