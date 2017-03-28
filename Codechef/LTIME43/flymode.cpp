#include <bits/stdc++.h>

#define SZ 100005
#define MOD7 10000007
#define MOD9 1000000009
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))
#define ones(a) __builtin_popcount(a)
#define loop(i, a, b) for(ll i=a; i<b; i++)
#define loopr(i, a, b) for(ll i=b-1; i>=a; i--)
#define max4(a, b, c, d) max(max(a, b), max(c, d))
#define min4(a, b, c, d) min(min(a, b), min(c, d))

using namespace std;

typedef double db;
typedef long long int ll;
typedef long double ld;

bool check(ll a, ll b, ll l, ll r){
	if(a <= l && b >= r){
		return true;
	}
	else if(a >= l && b <= r){
		return true;
	}
	else if(a <= l && b >= l && b <= r){
		return true;
	}
	else if(a >= l && a <= r && b >= r){
		return true;
	}
	return false;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	ll n;
	cin>>n;
	
	ll a[SZ];
	loop(i, 0, n){
		cin>>a[i];
	}
	ll ans = INT_MIN;
	
	loop(i, 1, n){
		ll cnt = 0;
		ll l = min(a[i-1], a[i]);
		ll r = max(a[i-1], a[i]);
		//cout<<l<<" "<<r<<endl;
		
		loop(j, i+1, n){
			ll minEle = min(a[j], a[j-1]);
			ll maxEle = max(a[j], a[j-1]);
			//cout<<minEle<<" "<<maxEle<<endl;
			if(check(minEle, maxEle, l, r)){
				cnt++;
			}
		}
		if(cnt > ans){
			ans = cnt;
		}
	}
	
	loop(i, 0, n){
		ll cnt=0;
		loop(j, i, n){
			if(a[i] == a[j]){
				cnt++;
			}
		}
		if(cnt > ans){
			ans = cnt;
		}
	}
	
	cout<<ans<<endl;
	return 0;
}
