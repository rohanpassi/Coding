#include <bits/stdc++.h>

#define SZ 1234567
#define MOD7 10000007
#define MOD9 1000000009
#define pb push_back
#define pob pop_back
#define mp make_pair
#define ALL(x) x.begin(), x.end()
#define UNIQUE(x) x.resize(unique(ALL(x)) - x.begin());
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))
#define max4(a, b, c, d) max(max(a, b), max(c, d))
#define min4(a, b, c, d) min(min(a, b), min(c, d))
#define loop(i, a, b) for(ll i=a; i<b; i++)
#define loopr(i, a, b) for(ll i=a; i>=b; i--)
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
	
	ll n, total;
	cin>>n>>total;
	
	ll coins[n];
	loop(i, 0, n){
		cin>>coins[i];
	}

	ll dp[total+1], coinIdx[total+1];
	loop(i, 0, total+1){
		dp[i] = INT_MAX;
		coinIdx[i] = -1;
	}

	dp[0] = 0;
	loop(i, 0, n){
		loop(j, 1, total+1){
			if(j >= coins[i]){
				if(1 + dp[j-coins[i]] < dp[j]){
					dp[j] = 1 + dp[j-coins[i]];
					coinIdx[j] = i;
				}
			}
		}
	}
	cout<<dp[total]<<endl;

	// Print solution
	if(coinIdx[total] == -1){
		cout<<"No Solution Possible"<<endl;
	}

	ll start = total;
	cout<<"Coins used to form total: ";
	while(start != 0){
		ll j = coinIdx[start];
		cout<<coins[j]<<" ";
		start = start - coins[j];
	}
	cout<<endl;

	return 0;
}
// Problem Statement : Given some coins of different denominations and a total, how many minimum
// number of coins we would need to get that total, assuming infinite supply of coins.