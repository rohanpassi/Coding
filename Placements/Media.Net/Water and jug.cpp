#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int x,y,z;
		cin>>x>>y>>z;
		if(z==0)
			cout<<"True"<<endl;
		else if(z<=x+y && z%__gcd(x,y)==0)
			cout<<"True"<<endl;
		else
			cout<<"False"<<endl;
	}
	return 0;
}
