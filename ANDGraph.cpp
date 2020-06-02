#include<bits/stdc++.h>
using namespace std;

#define int long long
const int inf = 1e15; //Limit
const int N = 1e5+7; //Highest N possible
int dis[N],n,m,k,p,par[N];
std::vector<int> adj[N],cost[N],val[N];
int mask;

int dijkstra(int src,int sink,int k)
{
	if(mask<k)return inf;
	priority_queue<pair <int,int>> pq;
	pq.push(make_pair(0LL,src));
	for(int i=0;i<=n;i++)dis[i]=inf;
	dis[src]=0;
	while(!pq.empty())
	{
		pair<int,int> node = pq.top();
		int u = node.second;
		pq.pop();
		if(dis[u]<-node.first)continue;
		for(int i=0;i<adj[u].size();i++){
			int v = adj[u][i];
			int w = cost[u][i];
			if((mask&val[u][i])!=mask)continue;
			if(dis[u]+w<dis[v]){
				dis[v]=dis[u]+w;
				par[v]=u;
				pq.push(make_pair(-dis[v],v));
			}
		}



	}
	return dis[sink];
}

signed main()
{
	cin >> n >> m;
	for(int i=0;i<m;i++){
		int u,v,w,p;
		cin >> u >> v >> w >> p;
		adj[u].push_back(v);
		adj[v].push_back(u);
		cost[u].push_back(w);
		cost[v].push_back(w);
		val[u].push_back(p);
		val[v].push_back(p);

	}
	int a,b,k;
	cin >> a >> b >> k;
	int ans = inf;
	mask = 1LL<<32;
	int bit=32;
	while(mask>k){
		ans = min(ans,dijkstra(a,b,k));
		mask = mask >> 1;
		bit--;
	}
	for(;bit>=0;bit--){
		bool on = false;
		if((k&(1LL<<bit)))on=true;
		if(on){
			mask = mask|(1LL<<bit);
			continue;
		}
		else{
			mask = mask|(1LL<<bit);
			ans = min(ans,dijkstra(a,b,k));
			mask = mask ^ (1LL<<bit);
		}
	}
	ans = min(ans,dijkstra(a,b,k));
	if(ans>=inf)cout << "-1" <<endl;
	else cout << ans << endl;




}