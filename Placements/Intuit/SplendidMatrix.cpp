#include <bits/stdc++.h>

#define SZ 1025

using namespace std;

typedef long long int ll;
typedef long double ld;


ll mat[SZ][SZ] = {0};

void solve(ll a[][SZ],ll n,ll v,ll i,ll j)
{
    if(n == 1){
        a[i][j] = v;
    }
    else{
		if(!a[i][j])
			solve(a,n/2,v,i,j);
        
        if(!a[i][j+n/2])
			solve(a,n/2,v+n*n/4,i,j+n/2);
        
        if(!a[i+n/2][j])
			solve(a,n/2,v+n*n/2,i+n/2,j);
        
        if(!a[i+n/2][j+n/2])
			solve(a,n/2,v+3*n*n/4,i+n/2,j+n/2);
    }
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	ll b[11];
	b[1] = 2;
	for(ll i=2; i<11; i++){
		b[i] = 2 * b[i-1];
	}
	
	ll n;
	cin>>n;
	
	solve(mat, b[n], 1, 1, 1);
	
	for(ll i=1; i<=b[n]; i++){
		for(ll j=1; j<=b[n]; j++){
			cout<<mat[i][j]<<" ";
		}
		cout<<endl;
	}
	
	return 0;
}

