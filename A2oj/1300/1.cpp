#include <bits/stdc++.h>

#define SZ 1000005
#define MOD7 10000007
#define MOD9 1000000009
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))
#define ones(a) __builtin_popcount(a)
#define loop(i, a, b) for(ll i=a; i<b; i++)
#define loopr(i, a, b) for(ll i=b-1; i>=a; i--)
#define max4(a, b, c, d) max(max(a, b), max(c, d))
#define min4(a, b, c, d) min(min(a, b), min(c, d))

using namespace std;

typedef double db;
typedef long long int ll;
typedef long double ld;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	ll n;
	cin>>n;
	
	ll sumx=0, sumy=0, sumz=0, x,y,z;
	loop(i, 0, n){
		cin>>x>>y>>z;
		sumx += x;
		sumy += y;
		sumz += z;
	}
	if((sumx == 0) && (sumy == 0) && (sumz == 0)){
		cout<<"YES"<<endl;
	}
	else{
		cout<<"NO"<<endl;
	}
	
	return 0;
}
