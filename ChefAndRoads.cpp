#include <bits/stdc++.h>
using namespace std;

#define ll long long int;


class graph{
    public:
  int V;
  list<int> * adj;
  graph(int v){
      V = v;
      adj = new list<int>[V+1];
  }
  void addEdge(int u, int v){
      adj[u].push_back(v);
  }
  
    void dfs(int start, int end, bool visited[], int dp[], int num = 1000000007){
        if(start == end){
            dp[start] = 1;
            return;
        }
        visited[start] = 1;
        for(auto v: adj[start]){
            if(!visited[v]){
                dfs(v, end, visited, dp);
            }
        }
        for(auto v:adj[start]){
            dp[start] = (dp[v] + dp[start])%num;
        }
    }
  
  
  
    
};



int main() {
	int n, m;
	cin>>n>>m;
	graph g(n);
	int start, end;
	cin>>start>>end;
	for(int i=0; i<m; i++){
	    int u, v;
	    cin>>u>>v;
	    g.addEdge(u, v);
	}
	
	
    bool * visited = new bool[n+10];
    int * dp = new int[n+10];
    memset(visited, false, sizeof(visited));
    memset(dp, 0, sizeof(dp));
	g.dfs(start, end, visited, dp);
	cout<<dp[start]<<endl;;
	return 0;
}
