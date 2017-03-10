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
	
	ll t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		
		ll a[SZ];
		ll cnt = 0;
		loop(i, 0, n){
			cin>>a[i];
			if(a[i] != i){
				cnt++;
			}
		}
		if(cnt > 0){
			cout<<cnt+1<<endl;
		}
		else{
			cout<<cnt<<endl;
		}
	}
	
	return 0;
}
