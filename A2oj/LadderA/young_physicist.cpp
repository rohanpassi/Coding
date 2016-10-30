#include <bits/stdc++.h>
#define SZ 12345678
#define MOD1 10000007
#define MOD2 1000000009
#define rep(i,a) for(ll i=0; i<a; i++)
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	ll n;
	cin>>n;
	
	ll sumx=0, sumy=0, sumz=0, x,y,z;
	rep(i,n){
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
