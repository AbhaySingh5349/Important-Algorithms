#include <bits/stdc++.h>
using namespace std;

#define N 100001

vector<int> graph[N];
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
	memset(visited,false,N);
	for(i=1;i<=vertices;i++){
		if(visited[i]==false){
			topoSort(i,st);
		}
	}
	
	while(st.size()>0){
		int x=st.top();
		st.pop();
		cout<<x<<" ";
	}
	return 0;
}
