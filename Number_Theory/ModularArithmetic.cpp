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
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;

ll modPow(ll a, ll b, ll MOD){
	ll result = 1;
	a = a % MOD;
	while(b > 0){
		if(b & 1){
			result = (result * a) % MOD;
		}
		b = b >> 1;
		a = (a * a) % MOD;
	}
	return result;
}
// x is multiplicative modulo inverse of a under modulo b
// y is multiplicative modulo inverse of b under modulo a
//ax + by = d
ll x, y, d;
void extendedEuclid(ll a, ll b){
	if(!b){
		d = a;
		x = 1;
		y = 0;
	}
	else{
		extendedEuclid(b, a%b);
		int tmp = x;
		x = y;
		y = tmp - (a/b)*y;
	}
}

// a and MOD should be coprime
ll modInverse(ll a, ll MOD){
	extendedEuclid(a, MOD);
	return (x % MOD + MOD) % MOD;
}

// MOD should be prime
// Fermat's little theorem
ll modInversePrime(ll a, ll MOD){
	return modPow(a, MOD-2, MOD);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	extendedEuclid(16, 10);
	cout<<"GCD of 16 and 10 is "<<d<<endl;
	cout<<"Coefficients x and y are "<<x<<" "<<y<<endl;
	
	return 0;
}
