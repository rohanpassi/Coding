#include<bits/stdc++.h>

#define SZ 1234567
#define MOD7 10000007
#define MOD9 1000000009
#define pb push_back
#define pob pop_back
#define mp make_pair
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a,, min(b, c))
#define max4(a, b, c, d) max(max(a, b), max(c, d))
#define min4(a, b, c, d) min(min(a, b), min(c, d))
#define loop(i, a, b) for(ll i=a; i<b; i++)
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;

ll calculateLCM(ll a, ll b){
	ll product = a * b;
	ll gcd = __gcd(a, b);
	return product/gcd;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	ll t;
	cin>>t;
	 while(t--){
	 	ll n;
	 	cin>>n;
	 	vll p(n);
	 	loop(i, 0, n){
	 		cin>>p[i];
	 	}
	 	vector<bool> visited(n, false);
	 	vll lcm;
	 	ll cnt;
	 	for(ll j=0; j<n; j++){
	 		cnt = 0;
	 		if(visited[j]){
	 			continue;
	 		}
	 		else{
	 			visited[j] = true;
	 			cnt++;
	 			ll i = p[j] - 1;
	 			while(!visited[i]){
	 				visited[i] = true;
	 				i = p[i] - 1;
	 				cnt++;
	 			}
	 			lcm.pb(cnt);
	 		}
	 	}
	 	ll ans = 1;
	 	for(ll i=0; i<(ll)lcm.size(); i++){
	 		ans = calculateLCM(lcm[i], ans);
	 	}
	 	cout<<ans<<endl;
	 }
	
	return 0;
}
