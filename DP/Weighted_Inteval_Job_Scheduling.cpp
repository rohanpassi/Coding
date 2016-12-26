#include <bits/stdc++.h>

#define ll long long int

#define SZ 12345
#define MOD 10000007

using namespace std;

struct Job{
	ll start;
	ll end;
	ll profit;
};

bool compare(Job jb1, Job jb2){
	return jb1.end < jb2.end;
}

int main(){
	ios::sync_with_stdio(false);
	
	ll n;
	cin>>n;
	
	Job jobs[SZ];
	for(ll i=0; i<n; i++){
		cin>>jobs[i].start>>jobs[i].end>>jobs[i].profit;
	}
	
	sort(jobs, jobs+n, compare);
	
	ll dp[SZ];
	memset(dp, 0, sizeof(dp));
	
	dp[0] = jobs[0].profit;
	for(ll i = 1; i<n; i++){
		dp[i] = max(jobs[i].profit, dp[i-1]);
		for(ll j=i-1; j>=0; j--){
			if(jobs[j].end <= jobs[i].start){
				dp[i] = max(dp[i], jobs[i].profit + dp[j]);
				break;
			}
		}
	}
	
	ll ans = INT_MIN;
	for(ll i=0; i<n; i++){
		if(ans < dp[i]){
			ans = dp[i];
		}
	}
	
	cout<<ans<<endl;
	return 0;
}
