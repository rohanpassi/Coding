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
	
	ll t;
	cin>>t;
	while(t--){
		ll n,super,vil;
		super=0;
		vil=0;
		cin>>n;
		ll fl = -1;
		loop(i, 0, n){
			string str;
			cin>>str;
			if(fl == -1){
				ll len = str.length();
				if(len>=3 && str[len-3]=='m' && str[len-2]=='a' && str[len-1]=='n'){
					super++;
				}
				else{
					vil++;
				}
				
				if(super - vil >= 2){
					fl=1;
				}
				else if(vil - super >= 3){
					fl=2;
				}
				else{
					continue;
				}
			}
		}
		if(fl == -1){
			cout<<"draw"<<endl;
		}
		else if(fl==1){
			cout<<"superheroes"<<endl;
		}
		else if(fl==2){
			cout<<"villains"<<endl;
		}
	}
	
	return 0;
}
