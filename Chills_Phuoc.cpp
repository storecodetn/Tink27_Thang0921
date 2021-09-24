#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxN = 5e3 + 10;
int n, g, res ,tmp;
int a[maxN];
int dp[(maxN / 2) + 10][maxN];

bool minimize(int &a, int b) {
    if (a > b) {
        a = b;
        return true;
    } else return false;
}

int32_t main() {
    freopen("Chills.inp", "r", stdin);
    freopen("Chills.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tmp2, tmpl, tmpr;
    res = 1e18;
    memset(dp, 0x3f, sizeof dp);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        g = 0;
        if (a[i - 1] >= a[i]) g += a[i - 1] - (a[i] - 1);
        if (a[i + 1] >= a[i]) g += a[i + 1] - (a[i] - 1);
        dp[1][i] = g;
        res = min(res, dp[1][i]);
    }
    cout << res << " ";
    for (int house = 2; house <= (n + 1) / 2; house++) {
        g = res = 1e18;
        for (int i = 3; i <= n; i++) {
            tmpr = a[i + 1] >= a[i] ? a[i + 1] - (a[i] - 1) : 0;
            tmpl = a[i - 1] >= a[i]  ? a[i - 1] - (a[i] - 1) : 0;
            if (a[i - 2] <= a[i - 1]) {
                tmp = a[i - 1] - (a[i - 2] - 1);
                tmp2 = a[i - 1] -  min({a[i - 1], a[i - 2] - 1, a[i] - 1});
                minimize(dp[house][i], dp[house - 1][i - 2] - tmp + tmp2 + tmpr);
            }
            else minimize(dp[house][i], dp[house - 1][i - 2] + tmpl + tmpr);
            minimize(g, dp[house - 1][i - 3]);
            minimize(dp[house][i], g + tmpl + tmpr);
        }
        for (int i = 1; i <= n; i++) res = min (res, dp[house][i]);
        cout << res << " ";
    }
}
