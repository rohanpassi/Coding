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
	
	ll dp[sum+1];
	memset(dp, 0, sizeof(dp));
	
	dp[0] = 1;
	for(ll i = 0; i < n; i++){
		for(ll j = sum; j >= a[i]; j--){
			dp[j] |= dp[j - a[i]];
		}
	}
	
//	for infinite usage of a[i]
//	for(ll j = a[i]); j <= required_sum; j++)
	
	cin>>q;
	for(ll i=0; i<q; i++){
		ll tmp;
		bool flag = false;
		cin>>tmp;
		cout<<dp[tmp]<<endl;
	}
	
	return 0;
}
