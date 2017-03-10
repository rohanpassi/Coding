#include<bits/stdc++.h>
using namespace std;

// O(n^2)
int sumP(int a[],int n)
{
	int ans = 0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			ans += __builtin_popcount(a[i]^a[j]);
		}
	}
	return ans;
}

// O(N)
int sumPairs(int a[],int n)
{
	int ans = 0;
	for(int i=0;i<32;i++)
	{
		int cnt = 0;
		for(int j=0;j<n;j++)
		{
			if(a[j] &(1<<i))
				cnt++;
		}
		ans += 2*cnt*(n-cnt);
	}
	return ans;
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
		{
			cin>>a[i];
		}
		
		cout<<sumP(a,n)<<endl;
		cout<<sumPairs(a,n)<<endl;
	}
	return 0;
}
