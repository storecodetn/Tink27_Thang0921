#include <bits/stdc++.h>

using namespace std;
const int nxm = 1e6 + 10;
FILE *fi = freopen("BCHANGE.inp", "r", stdin);
FILE *fo = freopen("BCHANGE.out", "w", stdout);
int a[nxm], n, q, d[nxm];
void solve()
{
    cin >> n >> q;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= q; i++)
    {
        long long l, r, val;
        cin >> l >> r >> val;
        d[l] += val;
        d[r + 1] -= val;
    }
    long long tmp = 0, ans = -1e9;
    for(int i = 1; i <= n; i++)
    {
        tmp += d[i];
        a[i] += tmp;
        ans = max(ans, 1ll*a[i]);
    }
    cout << ans;
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
