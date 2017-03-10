#include<bits/stdc++.h>
using namespace std;

bool check(string a[],int firstS,int secondS,int k)
{
	for(int i=0;i<k;i++)
	{
		if(a[firstS+i]!=a[secondS+i])
			return false;
	}
	return true;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string a[n];
		for(int i=0;i<n;i++)
			cin>>a[i];
			
		int ansS,ansE;
		int flag = 0;
		for(int k=n/2;k>0;k--)
		{
			int i = 0;
			while(i+k-1<n)
			{
				int j = i+k-1;
				int nxtS = j+1;
				while(nxtS+k-1<n)
				{
					if(check(a,i,nxtS,k))
					{
						flag = 1;
						ansS = i;
						ansE = j;
						break;
					}
					nxtS++;
				}
				if(flag)
					break;
				i++;
			}
			if(flag)
				break;
		}
		
		for(int i=ansS;i<=ansE;i++)
			cout<<a[i]<<" ";
		cout<<endl;
	}
	return 0;
}
