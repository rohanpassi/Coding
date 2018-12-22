#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t;
	cin>>t;
	int hosted[] = {2010, 2015, 2016, 2017, 2019};
	while(t--){
		int n;
		cin>>n;
		bool flag = false;
		for(int i = 0; i<5; i++){
			if(n == hosted[i]){
				flag = true;
				break;
			}
		}
		
		if(flag){
			cout<<"HOSTED"<<endl;
		}
		else{
			cout<<"NOT HOSTED"<<endl;
		}
	}
		
	return 0;
}
