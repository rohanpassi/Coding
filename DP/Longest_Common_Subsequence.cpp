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

	loop(i, 0, l1+1){
		loop(j, 0, l2+1){
			if((i == 0) || (j == 0)){
				dp[i][j] = 0;
			}
			else if(s1[i-1] == s2[j-1]){
				dp[i][j] = 1 + dp[i-1][j-1];
			}
			else{
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}

	ll len = dp[l1][l2];
	cout<<len<<endl;

	string lcs = "";

	ll i = l1, j = l2;
	while(i > 0 && j > 0 && len > 0){
		if(s1[i-1] == s2[j-1]){
			lcs.insert(0, s1, i-1, 1);
			i--;
			j--;
			len--;
		}
		else if(dp[i-1][j] > dp[i][j-1]){
			i--;
		}
		else{
			j--;
		}
	}
	cout<<lcs<<endl;

	// Linear Space Solution
	// ll dp[2][l2+1];

	// loop(i, 0, l1+1){
	// 	loop(j, 0, l2+1){
	// 		if((i == 0) || (j == 0)){
	// 			dp[i%2][j] = 0;
	// 		}
	// 		else if(s1[i-1] == s2[j-1]){
	// 			dp[i%2][j] = 1 + dp[(i-1)%2][j-1];
	// 		}
	// 		else{
	// 			dp[i%2][j] = max(dp[(i-1)%2][j], dp[i%2][j-1]);
	// 		}
	// 	}
	// }


	// ll len = dp[l1%2][l2];
	// cout<<len<<endl;
	
	return 0;
}
// Problem Statement : Given 2 strings, find the length of the common subsequence. Also print the
// subsequence.
// Solution Approach : We compare ith and jth char in string s1 and s2. If they are equal, we add
// 1 to the length of subsequence formed without them, else we find max of length of subsequence
// formed without each of them i.e. max(dp[i-1][j], dp[i][j-1]).
// To print the subsequence we trace back that current length comes from identical chars or is
// max of (dp[i-1][j], dp[i][j-1]), which ever is greater we follow its direction. If the current
// chars in both strings is equal, then we add that char to subsequence.