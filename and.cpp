#include <bits/stdc++.h>
using namespace std ;
typedef long long ll;
const ll inf = 1e15;
const ll N = 1e5+7;
ll dis[N],n,m,k,p,g,t,a[N],par[N];
vector<ll>adj[N],cost[N],val[N];
#define uu second
#define ww first
ll mask ;
ll dijkstra(ll src,ll snk , ll k) { //VlogV+E
    //cout << (bitset<40>)mask << endl;
    //cout << (bitset<40>)k << endl;
    if(mask<k)return inf;
    priority_queue< pair < ll, ll > > pq ;
    pq.push( make_pair( 0LL, src ) ) ;
    for( ll i = 0; i <= n ; i++ ) dis[i] = inf ;
    dis[src] = 0 ;
    while( !pq.empty() ) {
        pair<ll,ll>node = pq.top() ;
        ll u = node.uu;
        pq.pop();
        if(dis[u]<-node.ww)continue;
        for( ll i =0; i <adj[u].size() ; i++ ) {
            ll v = adj[u][i] ;
            ll w = cost[u][i] ;
            if((mask&val[u][i])!=mask)continue;
            if(dis[u]+w<dis[v]) {
                dis[v]=dis[u]+w;
                par[v]=u;
                pq.push( make_pair( -dis[v], v ) ) ;
            }
        }
    }
    return dis[snk];
}
int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        ll u,v,w,p;
        scanf("%lld %lld %lld %lld",&u,&v,&w,&p);
        adj[u].push_back(v);
        adj[v].push_back(u);
        cost[u].push_back(w);
        cost[v].push_back(w);
        val[u].push_back(p);
        val[v].push_back(p);
    }
    ll a, b, k ;

    cin>>a>>b>>k;
    ll ans = inf ;
    mask = 1LL<<32 ;
   // cout << mask << endl;
    int bit = 32 ;
    while(mask>k){
        //cout << (bitset<40>)mask << endl;
        ans = min(ans,dijkstra(a,b,k));
        mask = mask >> 1 ;
        bit--;
    }
    for(;bit>=0;bit--){
        //cout << (bitset<40>)k << endl;
        bool on=false;
        if((k&(1LL<<bit)))on=true;
        if(on){
            mask = mask | (1LL<<bit);
            //cout << (bitset<40>)mask << endl;
            continue;
        }
        else{
            mask = mask | (1LL<<bit);
            ans = min(ans,dijkstra(a,b,k));
            mask = mask ^ (1LL<<bit);
        }
    }
    //cout << (bitset<40>)mask << endl;
    ans = min(ans,dijkstra(a,b,k));
    //cout << bit << endl;
    if(ans>=inf)ans = -1;
    cout << ans ;




    return 0 ;
}
