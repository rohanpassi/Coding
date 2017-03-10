#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string a,b;
		cin>>a>>b;
		int m = a.length();
		int n = b.length();
		int dp[m+1][n+1];
		
		for(int i=0;i<=m;i++)
			dp[i][0] = 0;
		for(int j=0;j<=n;j++)
			dp[0][j] = 0;
			
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(a[i-1]==b[j-1])
					dp[i][j] = 1+dp[i-1][j-1];
				else
					dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			}
		}
		
		int len = dp[m][n];
		int i = m;
		int j = n;
		int idx = len-1;
		char ans[len+1];
		ans[len] = '\0';
		while(i>0 && j>0)
		{
			if(a[i-1]==b[j-1])
			{
				ans[idx--] = a[i-1];
				i--;
				j--;
			}
			else if(dp[i-1][j]>dp[i][j-1])
				i--;
			else
				j--;
		}
		cout<<ans<<endl;
	}
	return 0;
}
