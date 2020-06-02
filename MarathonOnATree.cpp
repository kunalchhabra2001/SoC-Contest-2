#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const int num = 200000;
std::vector<ll> reln[num];
ll tin[num],tout[num],p[num][20],log_term,level[num],timer;



void dfs(ll u, ll conn)
{	
	tin[u] = timer++;
	p[u][0] = conn;
	level[u] = level[conn] + 1;
	for(int i=1;i<=log_term;i++)
	{
		p[u][i] = p[p[u][i-1]][i-1];
	}
	for(auto elem:reln[u])
	{
		if(elem == conn) continue;
		dfs(elem,u);


	}
	tout[u] = timer++;


}

bool ansces(ll u,ll v)
{
	if(level[u]>level[v])
	{
		if(tin[v]<=tin[u] && tout[v]>=tout[u])
			return true;
		else
			return false;
	}
	else
	{
		if(tin[v]>=tin[u] && tout[v]<=tout[u])
			return true;
		else
			return false;
    }
}

ll lca(ll x, ll y)
{
	if(ansces(x,y))
	{
		if(level[x]>level[y])
			return y;
		else return x;
	}
	for(int i=log_term;i>=0;i--)
	{
		if(!ansces(p[x][i],y))
			x = p[x][i];

	}
	return p[x][0];
}

ll dist(ll u, ll v)
{
	ll res = lca(u,v);
	return level[u] + level[v] - 2*level[res];

}

int main()
{
	timer = 0;
	ll n,q;
	cin >> n >> q;
	for(int i=1;i<n;i++){
		ll x,y;
		cin >> x >> y;
		reln[x].push_back(y);
		reln[y].push_back(x);

	}
	log_term = ceil(log2(n));
	dfs(1,1);

	while(q--)
	{
		ll x,y,r;
		cin >> x >> y >> r;

		ll dist1 = dist(x,y);
		ll dist2 = dist(x,r);
		ll dist3 = dist(r,y);
		if(dist2+dist3 == dist1)cout<<"YES"<<endl;
		else cout << "NO" << endl;







	}




}
