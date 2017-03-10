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

bool checkConsecutive(ll a, ll b, ll c){
	ll diff1 = b - a;
	ll diff2 = c - b;
	if((diff1 == 1) && (diff2 == 1)){
		return true;
	}
	else{
		return false;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	ll t;
	cin>>t;
	while(t--){
		ll n, m;
		ll dirty[m];
		
		bool flag = false;
		loop(i, 0, n){
			cin>>dirty[i];
			if((dirty[i] == 1) || (dirty[i] == n)){
				flag = true;
			}
		}
		
		if(!flag){
			sort(dirty, dirty+m);
			loop(i, 2, m){
				if(checkConsecutive(dirty[i-2], dirty[i-1], dirty[i])){
					flag = true;
					break;
				}
			}
		}
		
		if(flag){
			cout<<"NO"<<endl;
		}
		else{
			cout<<"YES"<<endl;
		}
	}
	
	return 0;
}
