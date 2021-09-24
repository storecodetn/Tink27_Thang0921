#include <bits/stdc++.h>

using namespace std;
const int nxm = 1e7 + 10;
FILE *fi = freopen("AMISSING1.inp", "r", stdin);
FILE *fo = freopen("AMISSING1.out", "w", stdout);
int n, a[nxm], d[nxm], k;
void solve()
{
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        cin >> a[i], d[a[i]] = 1;
    int l = *min_element(a + 1, a + n + 1);
    int r = *max_element(a + 1, a + n + 1);
    int dem = 0;
    for(int i = l; i <= r; i++)
    {
        if(!d[i])
            dem++;
        if(dem == k)
        {
            cout << i << "\n";
            return;
        }
    }
    cout << -1;
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
