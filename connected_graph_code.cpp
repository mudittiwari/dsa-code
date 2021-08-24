#include<bits/stdc++.h>
using namespace std;
// code to represent the graph using adjacency matrix
vector<int> ans;
void dfs(vector<int> [],vector<int>&,int);//on adjacency list
void dfs(vector<vector<int>>,vector<int>&,int);//on adjacency matrix
vector<int> bfs(vector<vector<int>>,int,int);//adjacency matrix
vector<int> bfs(vector<int> [],int,int);//adjacency list
void printgraph(vector<int>[],int);//adjacency list print
void printgraph(vector<vector<int>>);//adjacency matrix print


void printgraph(vector<int> graph[],int n)
{
	// n is size of the array
	for(int i=0;i<n;i++)
	{
		cout<<i<<"\t";
		for(int j=0;j<graph[i].size();j++)
			cout<<graph[i][j]<<" ";
		cout<<endl;
	}
}


void printgraph(vector<vector<int>> graph)
{
	for(int i=0;i<graph.size();i++)
	{
		for(int j=0;j<graph[i].size();j++)
			cout<<graph[i][j]<<" ";
		cout<<endl;
	}
}


// dfs on adjacency list
void dfs(vector<int> graph[],vector<int> &visited,int node)
{
	if(visited[node])
		return;
	visited[node]=1;
	ans.push_back(node);
	for(int i=0;i<graph[node].size();i++)
		dfs(graph,visited,graph[node][i]);
}

//dfs on adjacency matrix
void dfs(vector<vector<int>> graph,vector<int> &visited,int node)
{
	if(visited[node])
		return;
	visited[node]=1;
	ans.push_back(node);
	for(int i=0;i<graph[node].size();i++)
	{
		if(graph[node][i]==1)
			dfs(graph,visited,i);
	}
}

vector<int> bfs(vector<int> graph[],int node,int n)
{
	vector<int> bfsans;
	vector<int> visited(n+1,0);
	queue<int> q;
	q.push(node);
	visited[node]=1;
	while(!q.empty())
	{
		int temp=q.front();
		q.pop();
		bfsans.push_back(temp);
		for(int i=0;i<graph[temp].size();i++)
		{
			if(!visited[graph[temp][i]])
			{
				q.push(graph[temp][i]);
				visited[graph[temp][i]]=1;
			}
		}
	}
	return bfsans;
}

vector<int> bfs(vector<vector<int>> graph,int node,int n)
{
	vector<int> bfsans;
	vector<int> visited(n+1,0);
	queue<int> q;
	q.push(node);
	visited[node]=1;
	while(!q.empty())
	{
		int temp=q.front();
		q.pop();
		bfsans.push_back(temp);
		for(int i=0;i<graph[temp].size();i++)
		{
			if(graph[temp][i] && !visited[i])
			{
				q.push(i);
				visited[i]=1;
			}
		}
	}
	return bfsans;
}

void adjacencymatrix(int n,int e)
{
	vector<vector<int>> graph(n+1,vector<int>(n+1,0));
	for(int i=0;i<e;i++)
	{
		int u,v;
		cin>>u>>v;
		graph[u][v]=1;
		graph[v][u]=1;
	}
	printgraph(graph);
	// vector<int> visited(n+1,0);
	// dfs(graph,visited,0);
	// for(int i=0;i<ans.size();i++)
	// 	cout<<ans[i]<<" ";
	vector<int> ans=bfs(graph,0,n);
	for(int i=0;i<ans.size();i++)
		cout<<ans[i]<<" ";
	cout<<endl;
}

void adjacencylist(int n,int e)
{
	vector<int> graph[n+1];
	for(int i=0;i<e;i++)
	{
		int u,v;
		cin>>u>>v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	printgraph(graph,n+1);
	// vector<int> visited(n+1,0);
	// dfs(graph,visited,0);
	// for(int i=0;i<ans.size();i++)
	// 	cout<<ans[i]<<" ";
	vector<int> ans=bfs(graph,0,n);
	for(int i=0;i<ans.size();i++)
		cout<<ans[i]<<" ";
	cout<<endl;
}

void Solve()
{
	// n is the number of nodes and e is the number of edges
	int n,e;
	cin>>n>>e;
	adjacencymatrix(n,e);
}

int main()
{
	// int t;
	// cin>>t;
	// while(t--)
	// {
	// 	Solve();
	// }
	Solve();
}
