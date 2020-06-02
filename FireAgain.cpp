#include<bits/stdc++.h>
using namespace std;
#define read          freopen("input.txt","r",stdin)
#define write         freopen("output.txt","w",stdout)

bool visited[2005][2005];
int level[2005][2005];
pair<int,int> result;
queue<pair<int,int>> q;
int n,m,k;
int dx[]= {1,-1,0,0};
int dy[]= {0,0,1,-1};
int main()
{
    int i,k,x,y,nx,ny;
    read;
    write;
    cin>>n>>m>>k;
    
    for(i=0; i<k; i++)
    {
        cin>>x>>y;
        q.push(make_pair(x,y));
        visited[x][y]=true;
        level[x][y]=0;
    }
    while(!q.empty())
    {
        result=q.front();
        q.pop();
        x=result.first;
        y=result.second;
        for(i=0;i<4;i++)
        {
            nx=x+dx[i];
            ny=y+dy[i];
            if(nx>=1 && ny>=1 && nx<=n && ny<=m && !visited[nx][ny])
            {
                visited[nx][ny]=true;
                level[nx][ny]=level[x][y]+1;
                q.push(make_pair(nx,ny));
            }
        }
    }
    cout << x << " " << y << endl;
    return 0;
}