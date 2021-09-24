#include <bits/stdc++.h>
using namespace std;

long long l, r;

long long sol(long long x) {
    int sum = 0;
    for (int i = 1; i <= x % 9; i++) sum += i;
    return 1ll * 45 * (x / 9) + sum;
}

int main() {
    freopen("BTrol.inp", "r", stdin);
    freopen("BTrol.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int numQuery;
    cin >> numQuery;
    while (numQuery--) {
        cin >> l >> r;
        l--;
        cout << sol(r) - sol(l) << "\n";
    }
}
