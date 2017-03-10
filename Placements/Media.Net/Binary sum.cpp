#include<bits/stdc++.h>
using namespace std;

bool hasBothChild(int i,int n)
{
	return (2*i+1<n && 2*i+2<n);
}

bool hasLeftChild(int i,int n)
{
	return (2*i+1<n);
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
			cin>>a[i];
			
		int dp[n];
		int ans = INT_MIN;
		for(int i=n-1;i>=0;i--)
		{
			if(hasBothChild(i,n))
			{
				int sum = max(max(dp[2*i+1],dp[2*i+2]),a[i]+dp[2*i+1]+dp[2*i+2]);
				ans = max(ans,sum);
				dp[i] = max(dp[2*i+1],dp[i+2]) + a[i];
			}
			else if(hasLeftChild(i,n))
			{
				int sum = max(dp[2*i+1],a[i]+dp[2*i+1]);
				ans = max(ans,sum);
				dp[i] = dp[2*i+1] + a[i];
			}
			else
			{
				ans = max(ans,a[i]);
				dp[i] = a[i];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
