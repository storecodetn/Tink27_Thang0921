#include <bits/stdc++.h>
using namespace std;
long long n,a[200001],m,d[200001];
int main()
{
    freopen("BCHANGE.INP","r",stdin);
    freopen("BCHANGE.OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=m;i++)
    {
        long long l,r;
        long long k;
        cin>>l>>r>>k;
        d[l]+=k;
        d[r+1]-=k;
    }
    long long ans=0,Max=-1e18;
    for(int i=1;i<=n;i++)
    {
        ans+=d[i];
        a[i]+=ans;
        Max=max(Max,a[i]);
    }
    cout<<Max;
}
