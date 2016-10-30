#include <bits/stdc++.h>
#define SZ 12345678
#define MOD1 10000007
#define MOD2 1000000009
#define max3(a,b,c) max(a, max(b,c))
#define max4(a,b,c,d) max(max(a,b), max(c,d))

using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	ll a,b,c;
	cin>>a>>b>>c;
	ll max1 = max(a*b*c, a+b+c);
	ll max2 = max(a*(b+c), (a+b)*c);
	cout<<max(max1, max2)<<endl;
	
	return 0;
}
