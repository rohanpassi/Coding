#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;


ll catDP[31];

// Exponential Solution
ll catalan(ll n){
    if (n <= 1) return 1;
 
    ll res = 0;
    for(ll i = 0; i < n; i++){
		res += catalan(i) * catalan(n-i-1);
	}
    return res;
}

// O(n^2) Solution using DP
void catalanDP(ll catDP[], ll n){
	catDP[0] = catDP[1] = 1;
	
	for(ll i=2; i<=n; i++){
		catDP[i] = 0;
		for(ll j=0; j<i; j++){
			catDP[i] += catDP[j] * catDP[i-j-1];
		}
	}
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	ll t;
	cin>>t;
	catalanDP(catDP, 30);
	while(t--){
		ll n;
		cin>>n;
		cout<<catDP[n]<<endl;
	}
	
	return 0;
}
