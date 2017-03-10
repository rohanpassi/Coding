#include <bits/stdc++.h>

#define SZ 1234567

using namespace std;

typedef long long int ll;
typedef long double ld;

struct card{
	ll x;
	ll y;
};


ll n, m, c;

bool checkValid(ll x, ll y, card cd){
	ll newX, newY;
	newX = x + cd.x;
	newY = cd.y;
	bool f = false;
	if((newX >= 0) && (newX < n) && (newY >= 0) && (newY < m)){
		f = true;
	}
	return f;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n>>m>>c;
	
	card cards[c];
	for(ll i=0; i<c; i++){
		cin>>cards[i].x>>cards[i].y;
	}
	
	ll x, y;
	x = 0;
	y = 0;
	ll cnt = 0;
	for(ll i=0; i<c; i++){
		if(checkValid(x, y, cards[i])){
			x += cards[i].x;
			y += cards[i].y;
			cnt++;
		}
		else{
			continue;
		}
	}
	
	cout<<cnt<<endl;
	return 0;
}

