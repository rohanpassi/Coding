#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	
	vector<int> p(10);
	int n = 10;
	for(int i=0; i<n; i++){
		p[i] = i;
	}
	cout<<(1<<n)<<endl;
	for(int i=0; i<(1 << n); i++){
		for(int j=0; j<n; j++){
			if(i & (1 << j)){
				cout<<p[j]<<" ";
			}
		}
		cout<<endl;
	}
	
	return 0;
}
