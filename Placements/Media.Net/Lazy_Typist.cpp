#include<bits/stdc++.h>

#define SZ 123456
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

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	ll n;
	cin>>n;
	char str[SZ];
	for(ll i=0; i<n; i++){
		cin>>str[i];
	}
	sort(str, str+n);
	if(str[0] == '0'){
		while(str[0] == '0'){
			rotate(str, str+1, str+n);
		}
	}
	else{
		reverse(str, str+n);
	}
	cout<<str<<endl;
	return 0;
}
