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

	string s1, s2;
	cin>>s1>>s2;

	ll l1 = s1.length();
	ll l2 = s2.length();

	ll dp[l1+1][l2+1];
	loop(i, 0, l2+1){
		dp[0][i] = i;
	}

	loop(i, 0, l1+1){
		dp[i][0] = i;
	}

	loop(i, 1, l1+1){
		loop(j, 1, l2+1){
			if(s1[i-1] == s2[j-1]){
				dp[i][j] = dp[i-1][j-1];
			}
			else{
				dp[i][j] = 1 + min3(dp[i-1][j-1], dp[i-1][j], dp[i][j-1]);
			}
		}
	}
	ll dist = dp[l1][l2];
	cout<<dist<<endl;

	// Print Operations
	ll i = l1, j = l2;
	while(1){
		if((i == 0) || (j == 0)){
			break;
		}
		if(s1[i-1] == s2[j-1]){
			i--;
			j--;
		}
		else if(dp[i][j] == dp[i-1][j-1] + 1){
			cout<<"Edit "<<s1[i-1]<<" in s1 to "<<s2[j-1]<<" in s2"<<endl;
			i--;
			j--;
		}
		else if(dp[i][j] == dp[i-1][j] + 1){
			cout<<"Delete in s1 "<<s1[i-1]<<endl;
			i--;
		}
		else if(dp[i][j] == dp[i][j-1] + 1){
			cout<<"Insert in s1 "<<s2[j-1]<<endl;
			j--;
		}
	}
	
	
	return 0;
}
// Problem Statement : Given 2 strings and operations like edit, delete and add. How many minimum
// operations would it take to convert one string to another string.
// Solution Approach : If ith and jth char in s1 and s2 are same, then cost of edit distance is
// same as dp[i-1][j-1]. Otherwise we consider minimum of all 3 operations i.e. substitute,
// delete and insert.
// Substitute --> dp[i-1][j-1]
// Delete --> dp[i-1][j]
// Insert --> dp[i][j-1]