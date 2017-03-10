#include <bits/stdc++.h>

#define SZ 1234567
#define MOD7 10000007
#define MOD9 1000000009
#define pb push_back
#define pob pop_back
#define mp make_pair
#define ALL(x) x.begin(), x.end()
#define UNIQUE(x) x.resize(unique(ALL(x)) - x.begin());
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a,, min(b, c))
#define max4(a, b, c, d) max(max(a, b), max(c, d))
#define min4(a, b, c, d) min(min(a, b), min(c, d))
#define loop(i, a, b) for(ll i=a; i<b; i++)
#define loopr(i, a, b) for(ll i=a; i>=b; i--)
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;

struct Job{
	ll start;
	ll end;
	ll profit;
};

bool compare(Job j1, Job j2){
	return j1.end < j2.end;
}

ll getNonConflictingJob(Job jbs[], ll i){
	ll low = 0, high = i-1;
	while(low <= high){
		ll mid = (low + high)/2;
		if(jbs[mid].end <= jbs[i].start){
			if(jbs[mid + 1].end <= jbs[i].start){
				low = mid + 1;
			}
			else{
				return mid;
			}
		}
		else{
			high = mid - 1;
		}
	}
	return -1;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	ll t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		Job jobs[n];
		loop(i, 0, n){
			cin>>jobs[i].start>>jobs[i].end>>jobs[i].profit;
		}
		sort(jobs, jobs+n, compare);

		ll dp[n];
		memset(dp, 0, sizeof(dp));
		dp[0] = jobs[0].profit;

		loop(i, 1, n){
			dp[i] = max(dp[i-1], jobs[i].profit);
			ll idx = getNonConflictingJob(jobs, i);
			if(idx != -1){
				dp[i] = max(dp[i], dp[idx] + jobs[i].profit);
			}
		}

		ll ans = INT_MIN;
		loop(i, 0, n){
			if(ans < dp[i]){
				ans = dp[i];
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
