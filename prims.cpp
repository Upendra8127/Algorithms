#include <bits/stdc++.h>
using namespace std;
#define int long long int
int n,e;
const int N=(int)1e5;
vector<pair<int,int>>edges[N];
vector<pair<int,int>> prims()
{
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> >pq;
	pq.push({0,0});
	
	vector<pair<int,int>>ans;
	int parent[n],updated_weights[n];
	for(int i=0;i<n;i++)
		updated_weights[i]=INT_MAX;
	parent[0]=-1;
	updated_weights[0]=0;
	while(!pq.empty()){
		
		pair<int,int>p=pq.top();
		int node=p.second;
		int w=p.first;
		pq.pop();
		if(w>updated_weights[node])
			continue;
		ans.push_back({node,parent[node]});
		
		for(auto x:edges[node]){
			int v=x.first;
			int ww=x.second;
			if(updated_weights[v]>w+ww){
				updated_weights[v]=w+ww;
				parent[v]=node;
				pq.push({updated_weights[v],v});
			}
		}
	}
	return ans;
}
main() 
{
	cin>>n>>e;
	for(int i=0;i<e;i++){
		int u,v,w;
		cin>>u>>v>>w;
		u--;v--;	//Zero Based 
		edges[u].push_back({v,w});
		edges[v].push_back(make_pair(u,w));
	}
	vector<pair<int,int>>ans=prims();
	for(auto x:ans){
		cout<<x.first<<" "<<x.second<<"\n";
	}
}

