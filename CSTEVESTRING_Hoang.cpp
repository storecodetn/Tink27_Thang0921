#include <bits/stdc++.h>

using namespace std;
const int nxm = 1e2 + 10;
FILE *fi = freopen("CSTEVESTRING.inp", "r", stdin);
FILE *fo = freopen("CSTEVESTRING.out", "w", stdout);
bool f[nxm][nxm][3];
int dp[3][nxm];
void solve()
{
    memset(f, 0, sizeof f);
    memset(dp, 0, sizeof dp);
    string s;
    cin >> s;
    int n = s.size();
    s = "." + s;
    for(int k = 1; k <= n; k++)
    {
        for(int i = 1; i <= n - k + 1; i++)
        {
            if(k == 1)
                f[i][i + k - 1][s[i] - 'a'] = 1;
            else
            {
                for(int x = 0; x < 3; x++)
                    for(int j = i; j < i + k - 1; j++)
                        if((f[i][j][(x + 1)%3] && f[j + 1][i + k - 1][(x + 2)%3]) || (f[i][j][(x + 2)%3] && f[j + 1][i + k - 1][(x + 1)%3]))
                            f[i][i + k - 1][x] = 1;
            }
        }
    }
    for(int i = 1; i <= n; i++)
    {
        dp[0][i] = dp[1][i] = dp[2][i] = i;
        for(int j = i; j >= 1; j--)
            for(int x = 0; x < 3; x++)
                if(f[j][i][x])
                    dp[x][i] = min(dp[x][i], dp[x][j - 1] + 1);
    }
    cout << min({dp[0][n], dp[1][n], dp[2][n]}) << "\n";
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
