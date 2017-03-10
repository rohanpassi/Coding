#include <bits/stdc++.h>

#define SZ 123456
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

bool compare(Job jb1, Job jb2){
	return jb1.end < jb2.end;
}

ll getNonConflictingJob(Job jb[], ll i){
	ll low = 0, high = i-1;
	while(low <= high){
		ll mid = (low + high)/2;
		if(jb[mid].end <= jb[i].start){
			if(jb[mid + 1].end <= jb[i].start){
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
	
	ll n;
	cin>>n;
	
	Job jobs[SZ];
	loop(i, 0, n){
		cin>>jobs[i].start>>jobs[i].end>>jobs[i].profit;
	}
	
	sort(jobs, jobs+n, compare);
	
	ll dp[SZ];
	memset(dp, 0, sizeof(dp));
	
	dp[0] = jobs[0].profit;
	loop(i, 1, n){
		dp[i] = max(jobs[i].profit, dp[i-1]);

		// O(n logn) solution
		ll idx = getNonConflictingJob(jobs, i);
		if(idx != -1){
			dp[i] = max(dp[i], jobs[i].profit + dp[idx]);
		}

		// O(n^2) solution
		// loopr(j, i-1, 0){
		// 	if(jobs[j].end <= jobs[i].start){
		// 		dp[i] = max(dp[i], jobs[i].profit + dp[j]);
		// 		break;
		// 	}
		// }
	}
	
	ll ans = INT_MIN;
	loop(i, 0, n){
		if(ans < dp[i]){
			ans = dp[i];
		}
	}
	
	cout<<ans<<endl;
	return 0;
}

// Problem Statement : Given certain jobs with their start times and end time and profit we can
// make by finishing the job. What is the maximum profit that we can make from these jobs.

// Solution Approach : Sort all the jobs by their end time. Initialize the dp[i] with profit[i].
// Then we check that job[j] should not overlap job[i]
// Example: start    end     profit
//			 1		  3			5
//			 2		  5			6
//			 4		  6			5
//			 6		  7			4
//			 5		  8			11
//			 7		  9			2
// Time Complexity of Solution : O(n^2)
// This solution can be further improved by search for non-conflicting job in O(logn).
//Sample Questions:
// Leo and Maximum Pay on Hackerearth