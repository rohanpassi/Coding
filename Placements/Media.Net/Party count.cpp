#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;

		int arr[n],dept[n];
		for(int i=0;i<n;i++)
		{
			cin>>arr[i]>>dept[i];
		}
		sort(arr,arr+n);
		sort(dept,dept+n);
		
		int i = 1;
		int j = 0;
		int cnt = 1;
		int ans = 1;
		while(i<n && j<n)
		{
			if(arr[i]<dept[j])
			{
				cnt++;
				ans = max(ans,cnt);
				i++;
			}
			else
			{
				cnt--;
				j++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
