#include<bits/stdc++.h>
using namespace std;
#define ll long long int

bool visited_or_not[100001];
vector<ll>v[100001];
ll c[100001];
ll Depth_First_search(ll n)
{
	ll mini,node;
	visited_or_not[n] = true; // This node is visited;
	mini = c[n];
	ll size = v[n].size(); //Total friends
	for(int i=0;i<size;i++){
		node = v[n][i]; //Iterating over each friend
		if(!visited_or_not[node])
			mini = min(mini,Depth_First_search(node)); // only if this friend isn't visited before
	}
	return mini;
}


int main()
{
	ll n,m;
	cin >> n >> m;
	
	for(int i=1;i<=n;i++){
		cin >> c[i];
	}
	ll x,y;
	
	for(int i=0;i<m;i++){
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	ll ans =0;
	for(int i=1;i<=n;i++){
		if(!visited_or_not[i])
		ans += Depth_First_search(i);

	}
	cout << ans << endl;

}