#include <bits/stdc++.h>
using namespace std;

#define N 1000001

struct Edge{
	int u,v;
	int w;
};

vector<Edge> graph;
int dist[N], parent[N];

void getDistance(int src, int vertices, int edges){
	int i, j;
	for(i=0;i<N;i++){
		dist[i]=INT_MAX;
	}

	dist[src]=0;
	for(i=0;i<vertices-1;i++){
		bool flag=false;
		for(j=0;j<edges;j++){
			int u=graph[j].u;
			if(dist[u]!=INT_MAX){
				int v=graph[j].v;
				int w=graph[j].w;
				if(dist[v]>dist[u]+w){
					dist[v]=dist[u]+w;
					flag=true;
				//	parent[v]=u;
				}
			}
		}
		if(flag==false){
			break;
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
		Edge e={u,v,w};
		graph.push_back(e);
	}
	int src;
	cin>>src;
	getDistance(src,vertices,edges);
	
	for(i=0;i<N;i++){
		parent[i]=-1;
	}
	
	bool hasNegativeCycle=false;
	int x=-1; // last vertex which was relaxed
	for(j=0;j<edges;j++){
		int u=graph[j].u;
		if(dist[u]!=INT_MAX){
			int v=graph[j].v;
			int w=graph[j].w;
			if(dist[v]>dist[u]+w){
				dist[v]=dist[u]+w;
				hasNegativeCycle=true;
				parent[v]=u;
				x=v;
			}
		}
	}
	if(hasNegativeCycle){
		cout<<"Negative Cycle Exists"<<"\n";
		j = x;
        for (i=0; i<vertices; i++){
        	j = parent[j]; // making j point to start of cycle
		}
           
        vector<int> path;
        for (int cur=j; ; cur=parent[cur])
        {
            path.push_back (cur);
            if (cur == j && path.size() > 1)
                break;
        }
        reverse (path.begin(), path.end());
        for (i=0; i<path.size(); i++)
            cout<<path[i]<<" ";
	} 
	
	return 0;
}
