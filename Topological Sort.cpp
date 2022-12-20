#include <bits/stdc++.h>
using namespace std;

// Question: given jobs from [1,n] and dependency vector with 1st job is pre-requisite of 2nd (i.e 2nd job is dependent on 1st)
// jobs:[1,2,3,4], deps:[[1,2],[1,3],[3,2],[4,2],[4,3]]
// o/p: [1,4,3,2] or [4,1,3,2]

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
