#include <bits/stdc++.h>
using namespace std;

#define N 100001

vector<int> graph[N], transpose[N];
bool visited[N];

void topoSort(int src, stack<int> &st){
	visited[src]=true;
	for(int i=0;i<graph[src].size();i++){
		int child=graph[src][i];
		if(visited[child]==false){
			topoSort(child,st);
		}
	}
	st.push(src);
}

void dfs(int src){
	visited[src]=true;
	for(int i=0;i<transpose[src].size();i++){
		int child=transpose[src][i];
		if(visited[child]==false){
			dfs(child);
		}
	}
}

int main()
{	
	int vertices, edges;
	cin>>vertices>>edges;
	int i,j;
	for(i=0;i<edges;i++){
		int u,v;
		cin>>u>>v;
		graph[u].push_back(v);
	}
	stack<int> st;	
	for(i=1;i<=vertices;i++){
		if(visited[i]==false){
			topoSort(i,st);
		}
	}
	
	for(i=1;i<=vertices;i++){
		for(j=0;j<graph[i].size();j++){
			int child=graph[i][j];
			transpose[child].push_back(i);
		}
	}
	
	memset(visited,false,N);
	int scc=0;
	while(st.size()>0){
		int src=st.top();
		st.pop();
		if(visited[src]==false){
			dfs(src);
			scc++;
		}
	}
	cout<<scc;
	return 0;
}
