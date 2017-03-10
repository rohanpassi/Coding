#include<bits/stdc++.h>
using namespace std;

string day[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

int dayOfWeek(int d, int m, int y){
	static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
	y -= m < 3;
	return (y + y/4 - y/100 + y/400 + t[m-1] + d) % 7;
}

int main(){
	ios::sync_with_stdio(false);
	
	int dd, mm, yyyy;
	cin>>dd>>mm>>yyyy;
	int dayIdx = dayOfWeek(dd, mm, yyyy);
	cout<<day[dayIdx]<<endl;
		
	return 0;
}
