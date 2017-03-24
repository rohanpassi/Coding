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
#define min3(a, b, c) min(a, min(b, c))
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

ll ceilIndex(ll a[], ll tail[], ll high, ll key){
	ll low = 0;
	ll mid;
	ll len = high;
	while(low <= high){
		mid = (low + high)/2;
		if((mid < len) && (a[tail[mid]] < key) && (key <= a[tail[mid+1]])){
			return mid + 1;
		}
		else if(a[tail[mid]] < key){
			low = mid + 1;
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
	ll a[n];
	loop(i, 0, n){
		cin>>a[i];
	}

	// O(n^2) solution
	ll lis[n], soln[n];
	loop(i, 0, n){
		lis[i] = 1;
		soln[i] = i;
	}

	loop(i, 1, n){
		loop(j, 0, i){
			if((a[i] > a[j]) && (lis[i] < (lis[j] + 1))){
				lis[i] = lis[j] + 1;
				soln[i] = j;
			}
		}
	}

	ll len = 0, maxIdx = -1;
	loop(i, 0, n){
		if(lis[i] > len){
			len = lis[i];
			maxIdx = i;
		}
	}
	cout<<len<<endl;
	ll i1 = maxIdx, i2 = maxIdx;
	stack<ll> stk;
	do{
		i1 = i2;
		stk.push(a[i1]);
		i2 = soln[i1];
	}while(i1 != i2);
	while(!stk.empty()){
		cout<<stk.top()<<" ";
		stk.pop();
	}
	cout<<endl;
	cout<<"--------------------------"<<endl;

	// O(n log n) Solution
	ll tail[n], prev[n];
	ll l = 0;
	loop(i, 0, n){
		tail[i] = 0;
		prev[i] = -1;
	}

	loop(i, 1, n){
		if(a[i] < a[tail[0]]){
			tail[0] = i;
		}
		else if(a[i] > a[tail[l]]){
			l++;
			tail[l] = i;
			prev[tail[l]] = tail[l-1];
		}
		else{
			ll idx = ceilIndex(a, tail, l, a[i]);
			tail[idx] = i;
			prev[tail[idx]] = tail[idx-1];
		}
	}
	cout<<l+1<<endl;

	// Print LIS
	ll idx = tail[l];
	stack<ll> s;
	while(idx != -1){
		s.push(a[idx]);
		idx = prev[idx];
	}
	
	while(!s.empty()){
		cout<<s.top()<<" ";
		s.pop();
	}

	
	return 0;
}
// Solution Approach for O(n log n) : 
// 1.) If a[i] is smallest among all end candidates of active lists, we will start new active list
// of length 1.
// 2.) If a[i] is largest among all end candidates of active lists, we will clone the largest
// active list and extend it by a[i].
// 3.) If a[i] is in between, we will find a list with largest end element that is smaller than
// a[i]. Clone and extend this list by a[i]. We will discard all other lists of same length as that
// of this modified list.
