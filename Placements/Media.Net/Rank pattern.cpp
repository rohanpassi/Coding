#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
	string str;
	cin>>str;
	
	ll k;
	cin>>k;
	
	ll a[k];
	for(int i=0;i<k;i++)
		cin>>a[i];
		
	ll len = str.length();
	ll i = 0;
	ll ans = -1;
	int flag;
	while(i+k<=len)
	{
		ll j = i+k-1;
		ll cnt = 1;
		
		map<char,ll> hash;
		for(int l=i;l<=j;l++)
		{
			hash[str[l]] = 1;
		}
		
		map<char,ll> ::iterator it;
		for(it=hash.begin();it!=hash.end();it++)
		{
			it->second = cnt;
			cnt++;
		}
		
		flag = 1;
		for(int l=i;l<=j;l++)
		{
			if(hash[str[l]]!=a[l-i])
			{
				flag = 0;
				break;
			}
		}
		if(flag)
		{
			ans = i;
			break;
		}
		i++;
	}
	if(flag)
		cout<<str.substr(ans,k)<<endl;
	return 0;
}
