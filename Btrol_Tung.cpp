#include <bits/stdc++.h>
using namespace std;
long long q,l,r;
long long tinh(long long x)
{
    long long a=x/9;
    long long b=x%9;
    return 45*a+b*(b+1)/2;
}
int main()
{
    freopen("Btrol.inp","r",stdin);
    freopen("Btrol.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>q;
    for(int i=1;i<=q;i++)
    {
        cin>>l>>r;
        cout<<tinh(r)-tinh(l-1)<<"\n";
    }
}
