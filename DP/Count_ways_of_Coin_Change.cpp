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

	// 2-D DP Solution
	ll dp[n+1][total+1];
	loop(i, 0, n+1){
		loop(j, 0, total+1){
			if(j == 0)
				dp[i][j] = 1;
			else
				dp[i][j] = 0;
		}
	}

	loop(i, 1, n+1){
		loop(j, 1, total+1){
			if(coins[i-1] > j){
				dp[i][j] = dp[i-1][j];
			}
			else{
				dp[i][j] = dp[i][j - coins[i-1]] + dp[i-1][j];
			}
		}
	}
	cout<<dp[n][total]<<endl;

	// Space efficient
	ll dp[total+1];
	loop(i, 0, total+1){
		dp[i] = 0;
	}

	dp[0] = 1;
	loop(i, 0, n){
		loop(j, 1, total+1){
			if(j >= coins[i]){
				dp[j] += dp[j-coins[i]];
			}
		}
	}
	cout<<dp[total]<<endl;

	
	return 0;
}
// Problem Statement : Given a value total, if we want to make change and we have infinite supply
// of each of coins = {c1, c2, c3....cn} valued coins. How many ways we can make the change
// Solution Approach : We can make 0 in 1 way, and if coin value is less than or equal to the total
// then we add dp[i-1][j] and dp[i][j-coins[i-1]]