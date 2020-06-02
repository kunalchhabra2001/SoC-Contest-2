#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const long long int mod = 998244353;

ll powerLL(ll  x, ll n) 
{ 
    ll result = 1; 
    while (n) { 
        if (n & 1) 
            result = result * x % mod; 
        n = n / 2; 
        x = x * x % mod; 
    } 
    return result; 
} 
int main()
{	
	int T;
	cin >> T;
	while(T--)
	{
		long long int N;
		cin >> N;
		long long int A[N],f[N+1]={0};
		for (int i = 0; i < N; i++)
		{
			cin >> A[i];
			if(A[i]>N)A[i]=N;
		}
		long long int j=0;
		sort(A,A+N);
		for(int i=0;i<N;i++){
			f[A[i]]++;
		}
		long long int temp_mex=1,sum=0,count=N+1;
		long long int dp[N+1]={0},dp2[N+1]={0};
		dp[N] = 1; 
		for(ll i=N-1;i>0;i--){
			ll num = powerLL(2,f[i]);
			dp[i] = dp[i+1]*num%mod;
		}
		for(ll i=1;i<=N;i++){
			ll num = powerLL(2,f[i])-1;
			if(i>1)dp2[i] = dp2[i-1]*num%mod;
			if(dp2[i]==0)count=i; 

		}
		for(ll i= count;i>0;i--){
			sum += dp2[i]*dp[i]*i%mod;
		}
		cout << sum << endl;
	}

}