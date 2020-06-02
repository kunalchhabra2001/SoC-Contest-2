#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
void printVector(vector<int> &v)
{
	for(auto x:v)
		cout<<x<<" ";
	cout<<"\n";
}
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int t;
    cin>>t;
    int m = (1<<20) - 1;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        map<int,int> mp;
        queue<int> q;
        std::vector<int> visited(m+1,0);
        for(int i=0;i<k;i++)
        {
            string p;
            cin>>p;
            int x = 0;
            for(auto c:p)
            {
                x=x|1<<(c-'a');
            }
            if(visited[x]==0)
            {
                visited[x]=1;
                q.push(x);
                mp.insert({x,i+1});
                //cout<<mp[x]<<"hi\n";
            }
        }
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            for(int i=0;i<20;i++)
            {
                int x = u&(m-(1<<i));
                if(visited[x]==0)
                {
                    visited[x]=1;
                    q.push(x);
                    mp.insert({x,mp[u]});
                }
            }
        }
        std::vector<int> ans;
        int x = 0;
        int cnt = 0;
        for(int i=0;i<n;i++)
        {
            int y = 1<<(s[i]-'a');
            if(visited[x|y]==0)
            {
                //cout<<cnt<<mp[x]<<"hi\n";
                int val = mp[x];
                while(cnt>0)
                {
                    ans.push_back(val);
                    cnt--;
                }
                x = 0;
            }
            x = x|y;
            cnt++;
        }
        int val = mp[x];
        while(cnt>0)
        {
            ans.push_back(val);
            cnt--;
        }
        printVector(ans);
    }
}

