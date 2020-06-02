#include<bits/stdc++.h>

using namespace std;
#define int long long
stack<int> store;
vector<int> v,graph[100001],rev_graph[100001],vis,dp,c;
set<int> final_graph[100001];

int sum,k=1;
unordered_map<int,int> comp,comp_val;


void dfs_store(int source){
    vis[source]=1;
    for(int val:graph[source]){
        if(!vis[val])
            dfs_store(val);
    }
    store.push(source);
}
void dfs(int source){
    vis[source]=1;
    for(int val:rev_graph[source]){
        if(!vis[val]){
            sum+=c[val];
            comp[val]=k;
            dfs(val);
        }       
    }
}
void find_components(int n){
    vis.assign(n+1,0);
    for(int i=1;i<n+1;i++)if(!vis[i])dfs_store(i);
    vis.assign(n+1,0);
    while(!store.empty()){
        int val = store.top();
        store.pop();
        if(!vis[val]){
            sum=c[val];
            comp[val]=k;
            dfs(val);
            comp_val[k]=sum;
            k++;
        } 
    }
}


void final_dfs(int u){
    vis[u]=1;
    int val=0;
    for(auto v:final_graph[u]){
        final_dfs(v);
        val=max(val,dp[v]);
    }
    dp[u]=comp_val[u]+val;
    
}

signed main()
{
    
    int n,m;
    cin>>n>>m;
    c.assign(n+1,0);
    for(int i=1;i<n+1;i++)cin>>c[i];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        rev_graph[v].push_back(u);
    }
    find_components(n);
   
        int size=comp_val.size()+1;
        for(int i=1;i<n+1;i++){
            for(int val:graph[i]){
                if(comp[i]!=comp[val])
                    final_graph[comp[i]].insert(comp[val]);
            }
        }
        dp.assign(size,0);
        vis.assign(size,0);
        for(int i=1;i<size;i++)
            if(!vis[i])final_dfs(i);

    for(int i=1;i<n+1;i++){
        cout<<dp[comp[i]]<<" ";
    }
    cout << endl;
	return 0;
}