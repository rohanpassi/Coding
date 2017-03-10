#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	
	double pi = 2 * acos(0.0);
	int n;
	cin>>n;
	// In C
	//printf("%.*lf\n", n, pi);
	
	// In C++
	cout<<fixed<<setprecision(n)<<pi;
		
	return 0;
}
