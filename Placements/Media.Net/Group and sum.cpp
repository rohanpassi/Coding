#include<bits/stdc++.h>
#define SZ 100
using namespace std;

int count(string str,int dp[SZ][9*SZ],int pos,int prevSum)
{
	int n = str.length();
	if(pos==n)
		return 1;
		
	if(dp[pos][prevSum]!=-1)
		return dp[pos][prevSum];
		
	dp[pos][prevSum] = 0;
	int sum = 0;
	int cnt = 0;
	
	for(int i=pos;i<n;i++)
	{
		sum += (str[i]-'0');
		if(sum>=prevSum)
			cnt += count(str,dp,i+1,sum);
	}
	dp[pos][prevSum] = cnt;
	return cnt;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str;
		cin>>str;

		int dp[SZ][9*SZ];
		memset(dp,-1,sizeof(dp));
		
		cout<<count(str,dp,0,0);
	}
	return 0;
}
