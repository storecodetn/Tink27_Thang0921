#include <bits/stdc++.h>

using namespace std;
FILE *fi = freopen("BTROL.inp", "r", stdin);
FILE *fo = freopen("BTROL.out", "w", stdout);
const int nxm = 2e5 + 10;
long long sum(long long n)
{
    long long x = n/9;
    return x*45 + (n%9)*(n%9 + 1)/2;
}
void solve()
{
    int q;
    cin >> q;
    while(q--)
    {
        long long l, r;
        cin >> l >> r;
        cout << sum(r) - sum(l - 1) << "\n";
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while(t--)
        solve();
    return 0;
}
