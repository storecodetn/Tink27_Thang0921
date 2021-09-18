#include <bits/stdc++.h>
using namespace std;
long long t,n,s,S,tg,ans;
int main()
{
    freopen("BSUB.INP","r",stdin);
    freopen("BSUB.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n;
        tg=0;
        S=s=0;
        ans=0;
        S=INT_MAX;
        long long Max=INT_MIN;
        for(int i=1;i<=n;i++)
        {
            long long x;
            cin>>x;
            if(x>0)
                s+=x;
            S=min(tg,S);
            tg+=x;
            ans=max({ans,tg-S,x});
            Max=max(Max,x);
        }
        if(Max<=0)
            ans=Max;
        if(s==0)
            s=ans;
        cout<<s<<" "<<ans<<"\n";
    }
}
