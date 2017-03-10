#include <bits/stdc++.h>

#define SZ 123456

using namespace std;

typedef long long int ll;
typedef long double ld;

vector<ll> bit;
vector<vector<ll> > e;
ll n, k;
 
ll read(ll idx){
	idx++;
	ll ans = 0;
	if(idx >= (ll)bit.size())
		idx = bit.size() - 1;
	while(idx > 0){
		ans += bit[idx];
		idx -= idx & (-idx);
	}
	return ans;
}
 
void update(ll idx, ll val){
	idx++;
	while(idx <= (ll)bit.size()-1){
		bit[idx] += val;
		idx += idx & (-idx);
	}
	return;
}
 
long long dfs(ll p){
	ll ans = read(k/p);
	update(p, 1);
	for(ll i = 0; i < (ll)e[p].size(); i++){
		ll v = e[p][i];
		ans += dfs(v);
	}
	update(p, -1);
	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n>>k;
	bit.resize(n + 3, 0);
	e.resize(n + 1);
	vector<bool> root(n + 1, false);
	root[0] = true;

	
	for(ll i=0; i<n-1; i++){
		ll a, b;
		cin>>a>>b;
		e[a].push_back(b);
		root[b] = true;
	}
	ll r = find(root.begin(), root.end(), false) - root.begin();
	cout<<dfs(r)<<endl;
	return 0;
}
