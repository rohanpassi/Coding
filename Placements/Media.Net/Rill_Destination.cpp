#include<bits/stdc++.h>

#define SZ 50
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

bool isSafe(ll x, ll y, ll row, ll col){
	return (y >= 0) && (y < col) && (x >= 0) && (x < row);
}

pll switchDir(ll dir){
	ll row, col;
	if(dir == 0){
		row = -1;
		col = 0;
	}
	else if(dir == 1){
		row = 0;
		col = 1;
	}
	else if(dir == 2){
		row = 1;
		col = 0;
	}
	else{
		row = 0;
		col = -1;
	}
	
	return mp(row, col);
}

ll cntUniqueCells(char mat[SZ][SZ], ll x, ll y, ll dir, ll row, ll col){
	pll p = switchDir(dir);
	ll r = p.first;
	ll c = p.second;
	
	ll visited[row][col];
	memset(visited,0,sizeof(visited));
	
	ll cnt = 0;
	while(1){
		if(!isSafe(x,y,row,col))
			break;
		
		if(visited[x][y]==0)
			cnt++;
			
		visited[x][y]++;
		
		if(visited[x][y]>400)
			break;
		
		if(mat[x][y]=='r'){
			dir = (dir+1)%4;
			p = switchDir(dir);
			r = p.first;
			c = p.second;
		}
		else if(mat[x][y]=='l'){
			dir = (dir - 1) % 4;
			if(dir < 0)
				dir = (dir + 4) % 4;
			p = switchDir(dir);
			r = p.first;
			c = p.second;
		}
		x = x + r;
		y = y + c;
	}
	return cnt;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	ll t;
	cin>>t;
	
	while(t--){
		ll row, col;
		cin>>row>>col;
		
		char mat[SZ][SZ];
		loop(i, 0, row){
			loop(j, 0, col)
				cin>>mat[i][j];
		}
		
		ll res = 0;
		loop(i, 0, row){
			loop(j, 0, col){
				if(mat[i][j] == '.'){
					loop(d, 0, 4){
						ll cnt = cntUniqueCells(mat, i, j, d, row, col);
						res = max(res, cnt);
					}
				}
			}
		}
		cout<<res<<endl;
	}
	return 0;
}
