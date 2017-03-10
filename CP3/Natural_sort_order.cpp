#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
int main(){
	ios::sync_with_stdio(false);
	
	iii A = make_pair(-1980, ii(5, 24));
	iii B = make_pair(-1980, ii(5, 24));
	iii C = make_pair(-1983, ii(11, 13));
	
	vector<iii> birthdays;
	birthdays.push_back(A);
	birthdays.push_back(B);
	birthdays.push_back(C);
	sort(birthdays.begin(), birthdays.end());
	for(int i=0; i<(int)birthdays.size(); i++){
		cout<<birthdays[i].first<<" "<<birthdays[i].second.first<<" "<<birthdays[i].second.second<<endl;;
	}
	
	return 0;
}
