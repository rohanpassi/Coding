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

	ll n;
	cin>>n;

	ll dims[n];
	loop(i, 0, n){
		cin>>dims[i];
	}

	ll mat[n][n];
	loop(i, 1, n){
		mat[i][i] = 0;
	}

	loop(len, 2, n){
		loop(i, 1, n-len+1){
			ll j = i + len - 1;
			mat[i][j] = INT_MAX;
			loop(k, i, j){
				ll q = mat[i][k] + mat[k+1][j] + dims[i-1] * dims[k] * dims[j];
				if(q < mat[i][j]){
					mat[i][j] = q;
				}
			}
		}
	}

	cout<<mat[1][n-1]<<endl;
	
	return 0;
}
// Problem Statement : Given chain of matrices, find the minimum number of multiplications needed.
// Solution Approach : We can place the first set of parenthesis in n-1 ways, which reduces the
// problem into smaller subproblems.
// Application : Minimum and maximum values of an expression with * and +
