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
	
	ll n, q, sum = 0;
	cin>>n;
	
	ll a[SZ];
	loop(i, 0, n){
		cin>>a[i];
		sum += a[i];
	}
	
	ll dp[n+1][sum+1];
	loop(i, 1, sum){
		dp[0][i] = 0;
	}
	
	loop(i, 0, n){
		dp[i][0] = 1;
	}
	
	loop(i, 1, n+1){
		loop(j, 1, sum+1){
			if(j - a[i-1] >= 0){
				dp[i][j] = dp[i-1][j] | dp[i-1][j - a[i-1]];
			}
			else{
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	
	cin>>q;
	loop(i, 0, q){
		ll tmp;
		bool flag = false;
		cin>>tmp;
		loop(j, 0, n){
			if(dp[j][tmp]){
				flag = true;
				break;
			}
		}
		if(flag){
			cout<<"Yes"<<endl;
		}
		else{
			cout<<"No"<<endl;
		}
	}
	
	return 0;
}

// Problem Statement : Given array of positive integers and a number K, is there any subset of
// elements which could add to make K.
// Solution Approach : Each row represents an element and each column represents sum which could
// be achieved or not.
// As 0 could be achieved by not taking any number, so first column is true. If a number is
// greater than current sum we are checking we take the value from top, otherwise go i-num steps back
// and OR the result.