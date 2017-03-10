#include<bits/stdc++.h>

#define SZ 1234567
#define MOD7 10000007
#define MOD9 1000000009
#define pb push_back
#define pob pop_back
#define mp make_pair
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

int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,b;
		cin>>n>>b;
		ll cost[n],price[n];
		loop(i, 0, n){
			cin>>cost[i];
		}
		
		loop(i, 0, n){
			cin>>price[i];
		}
			
	    ll sack[n+1][b+1];
	    
	    loop(i, 0, b+1){
			sack[0][i] = 0;
		}
			
		loop(i, 0, n+1){
			sack[i][0] = 0;
		}
			
	    loop(i, 1, n+1){
			loop(j, 1, b+1){
				if(price[i-1] <= j){
					sack[i][j] = max(sack[i-1][j-price[i-1]] + cost[i-1], sack[i-1][j]);
				}
				else{
					sack[i][j] = sack[i-1][j];
				}
			}
		}
		cout<<sack[n][b]<<endl;
	}
	return 0;
}
