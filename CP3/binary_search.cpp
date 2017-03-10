#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	
	int a[] = {1, 1, 2, 3, 5, 6, 7, 8, 9, 10, 1, 2, 3, 5, 6, 7, 8, 9, 10, 2, 3, 2, 3, 11};
	int n = 24;
	vector<int> nums(a, a+n);
	sort(nums.begin(), nums.end());
	int v = 4;
	//cout<<binary_search(nums.begin(), nums.end(), v)<<endl;
	for(int i=0; i<(int)nums.size(); i++){
		cout<<nums[i]<<" ";
	}
	cout<<endl;
	vector<int>::iterator low, up;
	low = lower_bound(nums.begin(), nums.end(), v);
	up = upper_bound(nums.begin(), nums.end(), v);
	cout<<(low-nums.begin())<<" "<<(up-nums.begin())<<endl;
	
	return 0;
}
