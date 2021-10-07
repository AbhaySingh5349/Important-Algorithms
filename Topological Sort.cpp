#include <bits/stdc++.h>
using namespace std;

// Approach 1: using DFS

void toposort(vector<int> graph[], stack<int> &st,int src, bool visited[]){
	visited[src]=true;
	for(int i=0;i<graph[src].size();i++){
		int child=graph[src][i];
		if(visited[child]==false){
			toposort(graph,st,child,visited);
		}
	}
	st.push(src);
}

vector<int> topologicalSort(vector<int> jobs, vector<vector<int>> deps) {
  int n=jobs.size();
	int maxe=*max_element(jobs.begin(),jobs.end());
	vector<int> graph[maxe+1];
	for(int i=0;i<deps.size();i++){
		int u=deps[i][0], v=deps[i][1];
		graph[u].push_back(v);
	}
	stack<int> st;
	
	bool visited[maxe+1];
	memset(visited,false,sizeof(visited));
	
	for(int i=0;i<n;i++){
		if(visited[jobs[i]]==false){
			toposort(graph,st,jobs[i],visited);
		}
	} 
	vector<int> v;
	if(st.size()!=n) return v;
	
	while(st.size()>0){
		v.push_back(st.top());
		st.pop();
	}
  return v;
}

// Approach 2: using BFS 
