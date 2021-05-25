#include <bits/stdc++.h>
using namespace std;

#define N 100001

vector<int> graph[N];
bool visited[N];
int colour[N];
int colourType[2]; // to count total no. of 0, 1 colours in each component

bool isBipartite(int src , int c){
	visited[src]=true;
	colour[src]=c;
	colourType[c]++;
	for(int i=0;i<graph[src].size();i++){
		int child=graph[src][i];
		if(visited[child]==false){
			if(isBipartite(child,c^1)==false){
				return false;
			}
		}else{
			if(colour[src]==colour[child]){
				return false;
			}
		}
	}
	return true;
}

int main()
{	
	int vertices, edges;
		
	for(i=0;i<edges;i++){
		int u,v;
		cin>>u>>v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
		
	bool flag=true;
	for(i=1;i<=vertices;i++){
		if(visited[i]==false){
			colourType[0]=colourType[1]=0;
			bool check=isBipartite(i,0);
			
			if(check==false){
				flag=false;
				break;
			}
		}
	}
	if(flag==false){
		cout<<"Not Bipartite";
	}else{
		cout<<"Not Bipartite";
	} 
	return 0;
}
