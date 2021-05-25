#include <bits/stdc++.h>
using namespace std;

template<typename T>
string itos(T i){
	stringstream s;
	s<<i;
	return s.str();
}

#define N 1000001

vector<pair<int,int> > graph[N];
int dist[N];

void getDistance(int src){
	int i;
	for(i=0;i<N;i++){
		dist[i]=INT_MAX;
	}
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
	pq.push({0,src});
	dist[src]=0;
	while(pq.size()>0){
		pair<int,int> f=pq.top();
		pq.pop();
		int u=f.second;
		int d=f.first;
		
		for(int i=0;i<graph[u].size();i++){
			int v=graph[u][i].first;
			int w=graph[u][i].second;
			if(dist[v]>dist[u]+w){
				dist[v]=dist[u]+w;
				pq.push({dist[v],v});
			}
		}
	}
}

int main()
{	
	int vertices, edges;
	cin>>vertices>>edges;
	int i,j;
	for(i=0;i<edges;i++){
		int u,v,w;
		cin>>u>>v>>w;
		graph[u].push_back({v,w});
		graph[v].push_back({u,w});
	}
	int src;
	cin>>src;
	getDistance(src);
	for(i=1;i<=vertices;i++){
		cout<<i<<" : "<<dist[i]<<"\n";
	}
	return 0;
}
/*
6 9
1 2 4
1 6 2
2 6 1
2 3 5
6 3 8
6 5 10
5 3 3
5 4 5
3 4 6
1
*/
/*
7 6
1 2
1 3
2 4
2 5
3 6
6 7

4 6
*/

