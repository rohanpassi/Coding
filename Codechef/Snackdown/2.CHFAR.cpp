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
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t;
	cin>>t;
	
	while(t--){
		int n, k;
		cin>>n>>k;
		
		int cnt=0;
		for(int i=0; i<n; i++){
			int tmp;
			cin>>tmp;
			
			if(tmp == 1){
				cnt++;
			}
		}
		
		if(n - cnt <= k){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}
	
	return 0;
}
