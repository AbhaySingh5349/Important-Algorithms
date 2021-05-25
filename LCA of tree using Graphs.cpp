METHOD 1: O(N) time ,O(N) space

#include <bits/stdc++.h>
using namespace std;

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

METHOD 2: O(log(N)) time ,O(Nlog(N)) space

#include <bits/stdc++.h>
using namespace std;

#define N 1001

vector<int> graph[N];
const int maxN=10; // pow(2,10) = 1024
int level[N], dp[N][maxN+1];

void dfs(int src, int parent, int l){
	dp[src][0]=parent;
	level[src]=l;
	for(int i=0;i<graph[src].size();i++){
		int child=graph[src][i];
		if(child!=parent){
			dfs(child,src,l+1);
		}
	}
}

void initialize(){
	int i,j;
	memset(dp,-1,sizeof(dp));
	dfs(1,-1,0);
	
	for(j=1;j<=maxN;j++){
		for(i=1;i<=N;i++){
			if(dp[i][j-1]!=-1){
				int parent=dp[i][j-1];
				dp[i][j]=dp[parent][j-1];
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
		int jumps=log2(d);
		b=dp[b][jumps];
		d-=(1<<jumps);
	}
	if(a==b){
		return a;
	}
/*	while(dp[a][0]!=dp[b][0]){
		a=dp[a][0]; // this takes only 1 jump, therefore we have to modify solution to get jumps as power of 2
		b=dp[b][0];
	} */
	for(int j=maxN;j>=0;j--){
		if(dp[a][j]!=-1 && (dp[a][j]!=dp[b][j])){
			a=dp[a][j];
			b=dp[b][j];
		}
	} 
	return dp[a][0];
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
		graph[v].push_back(u);
	}
	initialize();
	int a,b;
	cin>>a>>b;
	cout<<lca(a,b);
	return 0;
}
