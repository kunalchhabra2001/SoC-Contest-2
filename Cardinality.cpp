#include<bits/stdc++.h>
using namespace std;

#define int long long
const int MOD = 1000000007;

int modulo(int a,int b){
 int x=1,y=a;
  while(b>0){
    if(b&1){
      x=(x*y)%MOD;
    }
    y=(y*y)%MOD;
    b/=2;
  }
  return x%MOD;
}

int arr[103];
int sum[1025];
int cnt[1025];
int getmask(int a){
	int mask = 0;
	while(a){
		mask |= (1<<(a%10));
		a/=10;
	}
	return mask;
}

signed main(){
	int t,mask,mask_max;
	cin >> t;
		for(int i=0;i<1024;i++){
			sum[i]=cnt[i]=0;
		}
		for(int i=0;i<t;i++){
			cin >> arr[i];
			mask = getmask(arr[i]);
			if(sum[mask] < arr[i]){
				sum[mask] = arr[i];
				cnt[mask] = 1;
			}
			for(int m=0;m<1024;m++){
				if((m&mask) == 0){
					mask_max = mask|m;
					if(sum[mask_max] <= arr[i] + sum[m]){
						if(sum[mask_max] < arr[i] + sum[m]){
							sum[mask_max] = arr[i] + sum[m];
							cnt[mask_max] = cnt[m] + 1;
						}
						else if(sum[mask_max] == arr[i] + sum[m] && cnt[mask_max] < cnt[m] + 1){
							cnt[mask_max] = cnt[m] + 1;
						}
					}
				}
			}
		}
		int max_sum = 0,max_elem = 0;
		for(int i=0;i<1024;i++){
			if(max_sum < sum[i]){
				max_sum = sum[i];
				max_elem = cnt[i];
			}
			else if(max_sum == sum[i] && max_elem < cnt[i]){
				max_elem = cnt[i];
			}
		}
		cout << max_elem << endl;
	}
