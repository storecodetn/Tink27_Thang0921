#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxN = 1e5 + 10;
int n, m;
int sum[maxN], a[maxN];

int32_t main(){
    freopen("BCHANGE.inp", "r", stdin);
    freopen("BCHANGE.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int l, r, k, res = -1e18;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    while (m--) {
        cin >> l >> r >> k;
        sum[l] += k;
        sum[r + 1] -= k;
    }
    for (int i = 1; i <= n; i++) {
        sum[i] += sum[i - 1];
        res = max(res, sum[i] + a[i]);
    }
    cout << res;
}
