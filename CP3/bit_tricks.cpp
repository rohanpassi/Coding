#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	
	int a = 34;
	
	// Divide by 2
	a = a >> 1;
	
	// Multiply by 2
	a = a << 1;
	
	// Set jth bit
	int j = 3;
	a = a | (1 << j);
	
	// Unset jth bit
	a = a & ~(1 << j);
	
	// Toggle jth bit
	a = a ^ (1 << j);
	
	// Get value of least significant bit
	int val = a & (-a);
	
	// Turn on all bits
	a = (1 << n) - 1;
	
	// Modulo by power of 2
	a = a & ((1 << j) - 1);
	
	// Determine if power of 2
	val = a & (a-1);
	if(val){
		cout<<"Not a power of 2"<<endl;
	}
	else{
		cout<<"Power of 2"<<endl;
	}
	
	// Turn off the right most set bit
	a = a & (a-1);
	
	// Turn on the right most unset bit
	a = a | (a+1);
	
	// Turn off last consecutive run of ones
	a = a & (a+1);
	
	// Turn on last consecutive run of zeros
	a = a | (a-1);
	
	
	return 0;
}
