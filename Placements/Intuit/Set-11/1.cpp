#include <bits/stdc++.h>

#define SZ 1234567

using namespace std;

typedef long long int ll;
typedef long double ld;

ll findNum(ll c, ll s){
	ll low, mid, high;
	ll ans;
	low = 0;
	high = s;
	while(low <= high){
		mid = (low + high)/2;
		//cout<<mid<<endl;
		ld logValue = log2(mid);
		ld sqrtValue = sqrt(mid);
		ld val = c * mid * logValue * sqrtValue;
		if(val <= s){
			if(ans == mid)
			break;
			low = mid;
			ans = mid;
		}
		else{
			high = mid;
		}
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	ll c, s;
	cin>>c>>s;
	
	cout<<findNum(c, s)<<endl;
	
	
	return 0;
}
