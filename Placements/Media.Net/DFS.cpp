#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define SZ 1005
using namespace std;
 
vector<vector<ll> > tree(SZ);
vector<bool>vis(SZ,false);
vector<ll>cnt(SZ,0);
ll ans = 1;
 
void dfs(ll root)
{
    vis[root] = true;
    ll x = tree[root].size();
 
    for(ll i=0; i<x; i++)
    {
        if(!vis[tree[root][i]])
        {
            cnt[root]++;
            dfs(tree[root][i]);
        }
    }
}
 
void init()
{
    for(int i=0; i<SZ; i++)
    {
        tree[i].clear();
        vis[i] = false;
        cnt[i] = 0;
    }
}
 
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll x;
        ans = 1;
        init();
        ll n,root;
        cin>>n;
        for(int i=1; i<=n; i++)
        {
 
            cin>>x;
            if(x==0)
                root = i;
            else
            {
                tree[i].push_back(x);
                tree[x].push_back(i);
            }
        }
        
        dfs(root);
        
        for(int i=1; i<=n; i++)
        {
            if(cnt[i]>1)
            {
                cnt[i]= (cnt[i]*(cnt[i]-1))%mod;
                ans= (ans*cnt[i])%mod;
            }
        }
        cout<<ans<<endl;
    }
 
}
