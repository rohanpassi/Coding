#include<bits/stdc++.h>

#define push_back pb
#define pop_back pob
#define make_pair mp
#define SZ 1234567

using namespace std;

typedef long long int ll;
typedef long double ld;

// O(n^3) Solution
ll minPalinPartition(string str){
	ll len = str.length();
	
	// C[i][j] = Minimum number of cuts needed for palindrome
	// partitioning of substring str[i...j]
	// P[i][j] = true if substring str[i...j] is palindrome, else false
	ll C[len][len];
	bool P[len][len];
	
	for(ll i=0; i<len; i++){
		P[i][i] = true;
		C[i][i] = 0;
	}
	// L is substring length. Build the solution in bottom-up manner by
	// consisdering all substrings of length starting from 2 to n.
	// The loop structure is same as Matrix Chain Multiplication problem
	for(ll l = 2; l <= len; l++){
		for(ll i = 0; i < len-l+1; i++){
			// Set ending index
			ll j = i + l - 1;
			// If L is 2, then we just need to compare two characters.
			//Else need to check two corner characters and value of P[i+1][j-1]
			if(l == 2){
				P[i][j] = (str[i] == str[j]);
			}
			else{
				P[i][j] = (str[i] == str[j]) && (P[i+1][j-1]);
			}
			
			// If str[i...j] is palindrome, then C[i][j] is 0
			if(P[i][j]){
				C[i][j] = 0;
			}
			else{
				// Make a cut at every possible location starting from i to j
				// and get the mminimum cost cut.
				C[i][j] = INT_MAX;
				for(ll k=i; k <= j-1; k++){
					C[i][j] = min(C[i][j], C[i][k] + C[k+1][j] + 1);
				}
			}
		}
	}
	return C[0][len-1];
}


ll minPalinPartition2(string str){
	ll len = str.length();
	
	// C[i] = Minimum number of cuts needed for palindrome
	// partitioning of substring str[0...i]
	// P[i][j] = true if substring str[i...j] is palindrome, else false
	ll C[len];
	bool P[len][len];
	
	for(ll i=0; i<len; i++){
		P[i][i] = true;
	}
	// l is substring length. Build the solution in bottom-up manner by
	// consisdering all substrings of length starting from 2 to n.
	// The loop structure is same as Matrix Chain Multiplication problem
	for(ll l = 2; l <= len; l++){
		for(ll i = 0; i < len-l+1; i++){
			// Set ending index
			ll j = i + l - 1;
			// If l is 2, then we just need to compare two characters.
			//Else need to check two corner characters and value of P[i+1][j-1]
			if(l == 2){
				P[i][j] = (str[i] == str[j]);
			}
			else{
				P[i][j] = (str[i] == str[j]) && (P[i+1][j-1]);
			}
		}
	}
	
	for(ll i=0; i<len; i++){
		if(P[0][i]){
			C[i] = 0;
		}
		else{
			C[i] = INT_MAX;
			for(ll j=0; j<i; j++){
				if(P[j+1][i] && (1+C[j] < C[i])){
					C[i] = 1+ C[j];
				}
			}
		}
	}
	return C[len-1];
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	ll t;
	cin>>t;
	while(t--){
		string str;
		cin>>str;
		cout<<minPalinPartition2(str)<<endl;
	}
	
	return 0;
}
