#include <bits/stdc++.h>

#define SZ 12345678
#define MOD1 10000007
#define MOD2 1000000009
#define max3(a,b,c) max(a, max(b,c))
#define max4(a,b,c,d) max(max(a,b), max(c,d))
#define ones(a) __builtin_popcount(a)

using namespace std;

typedef double db;
typedef long long int ll;
typedef long double ld;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	ll n;
	cin>>n;
	cout<<ones(n)<<endl;
	
	return 0;
}
