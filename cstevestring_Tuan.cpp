#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define rep(i,a,b) for (int i=a;i<=b;i++)
typedef pair<int,int> ii;

int t,n,dp[101][3];
string s;
bool b[101][101][3];
//---------------
bool check(int i,int j,int k,int x)
{
    return (b[i][k][(x+1)%3]&b[k+1][j][(x+2)%3])|(b[i][k][(x+2)%3]&b[k+1][j][(x+1)%3]);
}
//--------------
void init()
{
    for (int i=1;i<=n;i++)
        b[i][i][s[i]]=1;
    for (int l=2;l<=n;l++)
    {
        for (int i=1;i<=n-l+1;i++)
        {
            int j=i+l-1;
            for (int k=i;k<=j;k++)
            {
                for (int x=0;x<=2;x++)
                    b[i][j][x]|=check(i,j,k,x);
            }
        }
    }
}
//--------------
void solve()
{
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=i;j++)
        {
            for (int k=0;k<=2;k++)
            {
                if (b[j][i][k])
                    dp[i][k]=min(dp[i][k],dp[j-1][k]+1);
            }
        }
    }
}
//---------------
int main()
{
    freopen("cstevestring.inp","r",stdin);
    freopen("cstevestring.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>t;
    while (t--)
    {
        cin>>s;
        n=s.size();
        s=" "+s;
        for (int i=1;i<=n;i++)
        {
            s[i]-='a';
            for (int j=1;j<=n;j++)
            {
                for (int k=0;k<=2;k++)
                    b[i][j][k]=0;
            }
            for (int j=0;j<=2;j++)
                dp[i][j]=n;
        }
        init();
        solve();
        cout<<min({dp[n][0],dp[n][1],dp[n][2]})<<"\n";
    }
    return 0;
}
