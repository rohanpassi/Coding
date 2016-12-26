#include <bits/stdc++.h>

#define ll long long int

#define SZ 12345
#define MOD 10000007

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	
	ll n, w;
	cin>>n>>w;
	
	ll val[SZ], weight[SZ];
	for(ll i=0; i<n; i++){
		cin>>weight[i]>>val[i];
	}
	
	ll dp[n+1][w+1];
	for(ll i=0; i<=n; i++){
		for(ll j=0; j<=w; j++){
			if(i==0 || j==0){
				dp[i][j] = 0;
				continue;
			}
			
			if(j - weight[i-1] >= 0){
				dp[i][j] = max(dp[i-1][j], dp[i-1][j-weight[i-1]] + val[i-1]);
			}
			else{
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	
	cout<<dp[n][w]<<endl;
	
	return 0;
}
