#include <bits/stdc++.h>
using namespace std;

#define N 1000001

struct Edge{
	int u, v;
	int w;
};

vector<Edge> graph;
int parent[N], rank[N];

bool compare(Edge e1, Edge e2){
	return e1.w < e2.w;
}

int find(int n){
	// path compression
	if(parent[n]<0){
		return n;
	}else{
		return parent[n]=find(parent[n]);
	}
}

void merge(int pu, int pv){
	// union by rank
	if(rank[pu]>rank[pv]){
		parent[pv]=pu;
		rank[pu]+=rank[pv];
	}else{
		parent[pu]=pv;
		rank[pv]+=rank[pu];
	}
//	parent[pu]=pv;
}

int main()
{	
	int t,i,n,m,u,v,src,d;
	
	cin>>n>>m;
	for(i=1;i<=n;i++){
		parent[i]=-1;
		rank[i]=1;
	}
	for(i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		Edge e= {u,v,w};
		graph.push_back(e);
	}
	sort(graph.begin(),graph.end(),compare);
	
	int sum=0;
	for(i=0;i<graph.size();i++){
		int pu=find(graph[i].u);
		int pv=find(graph[i].v);
		
		if(pu!=pv){
			sum+=graph[i].w;
			merge(pu,pv);
		}
	}
	cout<<sum;
	return 0;
}
