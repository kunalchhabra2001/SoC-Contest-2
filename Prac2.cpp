#include<bits/stdc++.h>
using namespace std;
#define read          freopen("input.txt","r",stdin)
#define write         freopen("output.txt","w",stdout)


int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
bool reached[2001][2001];

queue<pair<int,int>> q;
pair<int,int> result;
int n,m,x,y,nx,ny;
void bfs()
{
	while(!q.empty())
	{
		result = q.front();
		q.pop();
		
		x = result.first;
		y = result.second;
		for(int i=0;i<4;i++)
		{
			nx = x + dx[i];
			ny = y + dy[i];
			if(nx>=1 and nx<=m and ny>=1 and ny<=n and (!reached[nx][ny]))
			{
				reached[nx][ny]=true;
				q.push(make_pair(nx,ny));
			}


		}





	}

	cout << x << " " << y << endl;


}


int main()
{
	int n,m,k;
	read;
	write;
	cin >> n >> m >> k;
	for(int i=0;i<k;i++){
		
		cin >> x >> y;
		q.push(make_pair(x,y));

	}
	bfs();





}