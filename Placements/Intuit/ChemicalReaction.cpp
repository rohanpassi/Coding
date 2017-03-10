#include <bits/stdc++.h>

# define  fill(a,v)  memset(a, v, sizeof(a))
 
using namespace std;

typedef long long int ll;
typedef long double ld;

ll n;
ll tree[2000010];
ll reaction_time[500005];

string names[500005];

void build_tree(ll node, ll start, ll end){
	
	if(start != end){
		ll mid = (start + end)/2;
		build_tree(2 * node, start, mid);
		build_tree(2 * node + 1, mid + 1, end);
		tree[node] = tree[2 * node] + tree[2 * node + 1];
	}
	else{
		tree[node] = 1;
	}
}
 
ll query(ll node, ll start, ll end, ll foo){
	
	if(start == end)
		return start;

	ll mid = (start + end)/2;
	
	if(foo <= tree[2 * node])
		return query(2 * node, start, mid, foo);
	else
		return query(2 * node + 1, mid + 1, end, foo-tree[2 * node]);
}
 
void update_tree(ll node,ll start,ll end,ll change_idx){
	
	if(start > change_idx || end < change_idx|| start > end)
		return;

	if(start!=end){
		ll mid = (start + end)/2;
		if(change_idx <= mid)
			update_tree(2 * node, start, mid, change_idx);
		else
			update_tree(2 * node + 1, mid + 1, end, change_idx);

		tree[node] = tree[2 * node] + tree[2 * node + 1];
	}
	else
		tree[node] = 0;
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	ll t;
	cin>>t;
	while(t--){
		fill(tree, 0);
		fill(reaction_time, 0);
		
		cin>>n;
		for(ll i = 1; i<=n; i++)
			cin>>names[i];

		for(ll i = 1; i<=n; i++)
			cin>>reaction_time[i];
		
		build_tree(1, 1, n);
		ll maxval = 0;
		ll tmp, idx;
		for(ll i = 0; i < n-1; i++){
			cin>>idx;
			tmp = query(1, 1, n, idx);
			cout<<names[tmp]<<" ";
			update_tree(1, 1, n, tmp);
			maxval = max(maxval, reaction_time[tmp]);
			cout<<maxval<<endl;
		}
		tmp = query(1, 1, n, 1);
		cout<<names[tmp]<<" ";
		maxval = max(maxval,reaction_time[tmp]);
		cout<<maxval<<endl;
	}
	return 0;
}

