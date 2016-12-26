#include <bits/stdc++.h>

#define ll long long int

#define SZ 12345
#define MOD 10000007

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	
	ll n, q, sum = 0;
	cin>>n;
	
	ll a[SZ];
	for(ll i=0; i<n; i++){
		cin>>a[i];
		sum += a[i];
	}
	
	ll dp[n+1][sum+1];
	for(ll i=1; i<sum; i++){
		dp[0][i] = 0;
	}
	
	for(ll i=0; i<n; i++){
		dp[i][0] = 1;
	}
	
	for(ll i = 1; i <= n; i++){
		for(ll j = 1; j <= sum; j++){
			if(j - a[i-1] >= 0){
				dp[i][j] = dp[i-1][j] | dp[i-1][j - a[i-1]];
			}
			else{
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	
	cin>>q;
	for(ll i=0; i<q; i++){
		ll tmp;
		bool flag = false;
		cin>>tmp;
		for(ll i=0; i<n; i++){
			if(dp[i][tmp]){
				flag = true;
				break;
			}
		}
		if(flag){
			cout<<"Yes"<<endl;
		}
		else{
			cout<<"No"<<endl;
		}
	}
	
	return 0;
}
