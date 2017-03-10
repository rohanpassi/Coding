#include <bits/stdc++.h>

#define SZ 1234567

using namespace std;

typedef long long int ll;
typedef long double ld;

struct point{
	ll x;
	ll y;
};

bool checkDistance(ll d, point p1, point p2){
	return (abs(p1.x - p2.x) + abs(p1.y - p2.y)) <= d;
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	ll t;
	cin>>t;
	while(t--){
		ll n, m, d;
		cin>>n>>m>>d;
		
		point locations[n], targets[m];
		bool done[m];
		
		memset(done, false, sizeof(done));
		
		for(ll i=0; i<n; i++){
			cin>>locations[i].x>>locations[i].y;
		}
		
		for(ll i=0; i<m; i++){
			cin>>targets[i].x>>targets[i].y;
		}
		
		ll cnt = m/2;
		for(ll i=0; i<n; i++){
			for(ll j=0; j<m; j++){
				if(done[j])
				continue;
				
				if(checkDistance(d, locations[i], targets[j])){
					done[j] = true;
					cnt--;
				}
				if(cnt == 0)
					break;
			}
			if(cnt == 0)
				break;
		}
		
		if(cnt == 0){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
		
	}
	
	return 0;
}

