#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e6 + 10;
int n, kth;
int a[maxN];

int main() {
    freopen("AMISSING1.inp", "r", stdin);
    freopen("AMISSING1.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> kth;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + 1 + n);
    for (int i = 2; i <= n; i++) {
        if (a[i] == a[i - 1]) continue;
        if (kth > a[i] - a[i - 1] - 1) kth -= (a[i] - a[i - 1] - 1);
        else {
            cout << a[i - 1] + kth;
            return 0;
        }
    }
    cout << -1;
}
