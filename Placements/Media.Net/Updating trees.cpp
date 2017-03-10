#include <bits/stdc++.h>
#define SIZE 50005
#define MOD 1000000007
using namespace std;

vector <int> vec[SIZE];
long long int a[SIZE], b[SIZE], c[SIZE];
int visited[SIZE];
 
void dfs(int u) 
{
	  visited[u] = 1;
	  int len = vec[u].size();
	  if(len == 0) 
	  {
		a[u] += c[u];
		b[u] += c[u];
		a[u] %= MOD;
		b[u] %= MOD;
		return;
	  }
	  for(int i=0;i<len;i++) 
	  {
		if (visited[vec[u][i]] == 0) 
		{
		   dfs(vec[u][i]);
		   c[u] += c[vec[u][i]];
		   c[u] %= MOD;
		   b[u] += b[vec[u][i]];
		   b[u] %= MOD;
		} 
	  }
	  b[u] += c[u];
	  a[u] += c[u];
	  a[u] %= MOD;
	  b[u] %= MOD;
}
 
int main() 
{
  int t;
  cin>>t;
  while (t--) 
  {
  	int m,n,q,x,y;
  	string s;
  	
    cin>>n>>m>>q;
    
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    memset(c,0,sizeof(c));
    memset(visited,0,sizeof(visited));
   
    for (int i=1;i<=n;i++) 
    {
		cin>>x;
        vec[x].push_back(i);
    }
    
    while(m--) 
    {
		cin>>s>>x>>y;
		if (s=="ADD") 
		{
			a[x] += y;
			b[x] += y;
		}	 
		else 
		{
			c[x] += y;
		}
    }
    
    dfs(1);
    
    while(q--) 
    {
      cin>>s>>x;
      if (s=="VALTREE") 
      {
        cout<<b[x]<<endl;
      } 
      else 
      {
        cout<<a[x]<<endl;
      } 
    }
    
    for (int i=0;i<SIZE;i++)  
    	vec[i].clear();
  }       
  return 0;
} 
