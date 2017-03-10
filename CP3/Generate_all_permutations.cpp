#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	
	char a = 'A';
	char str[5];
	for(int i=0; i<5; i++){
		str[i] = a + i;
	}
	
	do{
		cout<<str<<endl;
	}
	while(next_permutation(str, str+5));
	
	return 0;
}
