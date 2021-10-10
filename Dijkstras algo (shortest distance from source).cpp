#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstrasAlgorithm(int start, vector<vector<vector<int>>> edges) {
	int n=edges.size();
  	vector<pair<int,int>> graph[n];
	for(int i=0;i<n;i++){
		vector<vector<int>> adj=edges[i];
		for(int j=0;j<adj.size();j++){
			int v=adj[j][0], wt=adj[j][1];
			graph[i].push_back({v,wt});
		}
	}
	vector<int> dist(n,INT_MAX);
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq; 
	pq.push({0,start});
	dist[start]=0;
	while(pq.size()>0){
		pair<int,int> p=pq.top();
		pq.pop();
		int d=p.first;
		int u=p.second;
		
		for(int i=0;i<graph[u].size();i++){
			int v=graph[u][i].first;
			int wt=graph[u][i].second;
			
			if(dist[v]>d+wt){
				dist[v]=d+wt;
				pq.push({dist[v],v});
			}
		}
	}
	for(int i=0;i<n;i++) if(dist[i]==INT_MAX) dist[i]=-1;
  return dist;
}
