#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define rep(i,a,b) for (int i=a;i<=b;i++)
typedef pair<int,int> ii;

int r,t,n,a,b,c;
//------------
int main()
{
    freopen("bactor.inp","r",stdin);
    freopen("bactor.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>r;
    cin>>t;
    while (t--)
    {
        cin>>n>>a>>b>>c;
        if (r==2)
            cout<<min({a,b,c})<<"\n";
        else cout<<max(0,a+b+c-2*n)<<"\n";
    }
    return 0;
}
