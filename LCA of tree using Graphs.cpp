#include <bits/stdc++.h>
using namespace std;

template<typename T>
string itos(T i){
	stringstream s;
	s<<i;
	return s.str();
}

#define N 10001

vector<int> graph[N];
int parent[N], level[N];
bool visited[N];

void bfs(int src){
	memset(visited,false,N);
	queue<int> q;
	level[src]=0;
	visited[src]=true;
	parent[src]=-1;
	q.push(src);
	while(q.size()>0){
		int u=q.front();
		q.pop();
		for(int i=0;i<graph[u].size();i++){
			int v=graph[u][i];
			if(visited[v]==false){
				visited[v]=true;
				level[v]=level[u]+1;
				parent[v]=u;
				q.push(v);
			}
		}
	}
}

int lca(int a, int b){
	if(level[a]>level[b]){
		swap(a,b);
	}
	int d=level[b]-level[a];
	while(d>0){
		b=parent[b];
		d--;
	}
	if(a==b){
		return a;
	}
	while(parent[a]!=parent[b]){
		a=parent[a];
		b=parent[b];
	}
	return parent[a];
}

int main()
{	
	int vertices, edges;
	cin>>vertices>>edges;
	int i;
	for(i=0;i<edges;i++){
		int u,v;
		cin>>u>>v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	bfs(1);
	int a,b;
	cin>>a>>b;
	cout<<lca(a,b);
	return 0;
}
/*
7 6
1 2
1 3
2 4
2 5
3 6
6 7

7 3
*/

