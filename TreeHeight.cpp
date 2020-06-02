#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAX_NUM 300005

int n;
std::vector<pair<int,int>> adj[MAX_NUM];
int dp1[MAX_NUM],dp2[MAX_NUM];
int size[MAX_NUM];

void dfs(int u, int p)
{
	size[u]=1;
	for(pair<int,int> temp: adj[u])
	{
		int v = temp.first,w = temp.second;
		if(v==p)continue;
		dp1[v]=dp1[u]+w;
		dfs(v,u);
		size[u] += size[v];


	}

}

void dfs2(int u, int p)
{
	for(pair<int,int> temp : adj[u])
	{
		int v = temp.first, w = temp.second;
		if(v==p)continue;

		dp2[v]=dp2[u];
		dp2[v] -= size[v]*w;
		dp2[v] += (n-size[v])*w;

		dfs2(v,u);


	}


}

signed main()
{
	memset(dp1,0,sizeof dp1);
	memset(dp2,0,sizeof dp2);
	cin >> n;
	for(int i=0;i<n-1;i++)
	{
		int u,v,w;
		cin >> u >> v >> w;
		u--,v--,w;
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});

	}
	dfs(0,-1);
	for(int i=0;i<n;i++)
	{
		dp2[0] += dp1[i];
	}

	dfs2(0,-1);
	for(int i=0;i<n;i++){
		cout << dp2[i] << " ";
	}
	cout << endl;



}