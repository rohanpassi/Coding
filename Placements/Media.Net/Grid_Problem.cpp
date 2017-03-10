#include<bits/stdc++.h>

#define push_back pb
#define pop_back pob
#define make_pair mp
using namespace std;

typedef long long int ll;
typedef long double ld;

ll ROW, COL;
bool visited[1005][1005];

bool isSafe(string grid[], ll row, ll col){
    return (row >= 0) && (row < ROW) &&     
           (col >= 0) && (col < COL) &&      
           (grid[row][col] == '1') && 
           (!visited[row][col]); 
}


void DFS(string grid[], ll row, ll col){
    static int rowDir[] = {0, 0, -1, 1};
    static int colDir[] = {-1, 1, 0, 0};
	
    visited[row][col] = true;
    
    for (ll k = 0; k < 8; ++k){
		if(isSafe(grid, row + rowDir[k], col + colDir[k])){
			DFS(grid, row + rowDir[k], col + colDir[k]);
		}
	}
}

ll countIslands(string grid[]){
    ll cnt = 0;
    for(ll i = 0; i < ROW; i++){
		for(ll j = 0; j < COL; j++){
			if((grid[i][j] == '1') && (!visited[i][j])){
				DFS(grid, i, j);
				cnt++;
            }
		}
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
		ll n;
		cin>>n;
		string grid[n];
		for(ll i=0; i<n; i++){
			cin>>grid[i];
		}
		ROW = n;
		COL = grid[0].length();
		memset(visited, false, sizeof(visited));
		cout<<countIslands(grid)<<endl;
		
	}
	
	return 0;
}
