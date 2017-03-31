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

	ll a[n];
	loop(i, 0, n){
		cin>>a[i];
	}

	ll max_so_far = INT_MIN, max_end_here = 0;
	ll left=0, right=0, s=0;
	loop(i, 0, n){
		max_end_here += a[i];
		if(max_so_far < max_end_here){
			max_so_far = max_end_here;
			left = s;
			right = i;
		}

		if(max_end_here < 0){
			max_end_here = 0;
			s = i + 1;
		}
	}
	cout<<"Max Sum : "<<max_so_far<<endl;
	cout<<"("<<left<<" ,"<<right<<")"<<endl;
	
	return 0;
}
