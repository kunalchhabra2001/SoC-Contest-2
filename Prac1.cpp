#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll limit = 100005;

bool visited[limit];
ll price[limit]={0};
std::vector<ll> friends[limit];
ll Min_Gold_Dfs(ll n)
{
	ll pricemin,node;
	visited[n] = true;
	ll num = friends[n].size();
	pricemin = price[n];
	for(ll i=0;i<num;i++)
	{
		node = friends[n][i];
		if(!visited[node])
			pricemin= min(pricemin,Min_Gold_Dfs(node));

	}
	return pricemin;



}

int main()
{
	ll n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> price[i];

	for(int i=1;i<=m;i++){
		ll x,y;
		cin >> x >> y;
		friends[x].push_back(y);
		friends[y].push_back(x);

	}
	ll ans = 0;
	for(int i=1;i<=n;i++)
	{
		if(!visited[i])
			ans += Min_Gold_Dfs(i);

	}
	cout << ans	<< endl;




}