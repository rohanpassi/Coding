#include<bits/stdc++.h>
#define SZ 105
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int n,k;
	cin>>n>>k;
	
	int a[SZ];
	for(int i=0;i<n;i++)
		cin>>a[i];
		
	int cnt = 0;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if((a[i]+a[j])%k==0)
				cnt++;
		}
	}
	cout<<cnt<<endl;
	return 0;
}
