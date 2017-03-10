#include<bits/stdc++.h>

#define push_back pb
#define pop_back pob
#define make_pair mp
#define SZ 1234567

using namespace std;

typedef long long int ll;
typedef long double ld;


int main(){
	ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);
	
	ll fib[10];
	ll start[10];
	fib[0] = 0;
	fib[1] = 100;
	start[0] = 0;
	start[1] = 100;
	
	for(ll i=2; i<10; i++){
		fib[i] = fib[i-1] + fib[i-2];
		start[i] = start[i-1] + fib[i-1] + 100;
	}
	
	ll t;
	cin>>t;
	while(t--){
		ll d;
		cin>>d;
		
		ll i=10;
		while(1){
			if(start[i] + fib[i] <= d)
				break;
			else
				i--;
		}
		cout<<fib[i-1]<<" "<<fib[i]<<endl;		
	}
	
	return 0;
}
