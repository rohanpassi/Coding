#include<bits/stdc++.h>

#define SZ 123456
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

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	ll n;
	cin>>n;
	
	ll a[SZ], sum[SZ];
	loop(i, 0, n){
		cin>>a[i];
		
		if(i==0){
			sum[i] = a[i];
		}
		else{
			sum[i] = sum[i-1] + a[i];
		}
	}
		
	ll res = 0;
	loop(i, 0, n){
		if(a[i] >= 0){
			res += a[i];
		}
		else{
			ll idx = max(0LL, (a[i] + i));
			ll add = sum[i];
			if(idx - 1 >= 0){
				add -= sum[idx - 1];
			}
			res += add;
		}
	}
	cout<<res<<endl;
	
	return 0;
}
