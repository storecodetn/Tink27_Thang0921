#include <bits/stdc++.h>

using namespace std;
FILE *fi = freopen("BACTOR.inp", "r", stdin);
FILE *fo = freopen("BACTOR.out", "w", stdout);
const int nxm = 2e5 + 10;
int r;
void solve()
{
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    if(r == 1)
        cout << max(0, n - (n - a) - (n - b) - (n - c)) << "\n";
    else
        cout << min({a, b, c}) << "\n";
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> r;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
