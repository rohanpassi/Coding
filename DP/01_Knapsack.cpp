#include <bits/stdc++.h>

#define SZ 123456
#define MOD7 10000007
#define MOD9 1000000009
#define pb push_back
#define pob pop_back
#define mp make_pair
#define ALL(x) x.begin(), x.end()
#define UNIQUE(x) x.resize(unique(ALL(x)) - x.begin());
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a,, min(b, c))
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
	
	ll n, w;
	cin>>n>>w;
	
	ll val[SZ], weight[SZ];
	loop(i, 0, n){
		cin>>weight[i]>>val[i];
	}
	
	ll dp[n+1][w+1];
	loop(i, 0, n+1){
		loop(j, 0, w+1){
			if(i==0 || j==0){
				dp[i][j] = 0;
				continue;
			}
			
			if(j - weight[i-1] >= 0){
				dp[i][j] = max(dp[i-1][j], dp[i-1][j-weight[i-1]] + val[i-1]);
			}
			else{
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	
	// cout<<dp[n][w]<<endl;

	loop(i, 0, n+1){
		loop(j, 0, w+1){
			cout<<dp[i][j]<<"\t";
		}
		cout<<endl;
	}
	
	return 0;
}

// Problem Statement : Given a weight W and an array of items with their weights and profits. We
// have to maximize the profit so that sum of weight of items never exceeds W.
// Solution Approach : Each row represents an item and each column represent total weight. Each
// value dp[i][j] in matrix represents the maximum profit that we can make in weight j  with first
// i items
