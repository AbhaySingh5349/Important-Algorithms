#include <bits/stdc++.h>
using namespace std;

// Question: given jobs from [1,n] and dependency vector with 1st job is pre-requisite of 2nd (i.e 2nd job is dependent on 1st)

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

#include <vector>
using namespace std;

vector<int> topologicalSort(vector<int> jobs, vector<vector<int>> deps) {
  int n=jobs.size();
	
	vector<int> graph[n+1];
	vector<int> indegree(n+1,0);
	for(int i=0;i<deps.size();i++){
		int u=deps[i][0], v=deps[i][1];
		graph[u].push_back(v);
		indegree[v]++;
	}
	
	queue<int> q;
	for(int i=0;i<n;i++){
		if(indegree[jobs[i]]==0) q.push(jobs[i]);
	}
	
	vector<int> v;
	while(q.size()>0){
		int u=q.front();
		q.pop();
		v.push_back(u);
		
		for(int i=0;i<graph[u].size();i++){
			int v=graph[u][i];
			indegree[v]--;
			if(indegree[v]==0) q.push(v);
		}
	}
	if(v.size()<n) v.clear();
  return v;
}
