#include <bits/stdc++.h>
using namespace std;
long long a[5001],n,ans[5001],luu[5001];
long long d[5][3000][2];
void dich()
{
    for(int i=1;i<=(n+1)/2;i++)
    {
        d[1][i][0]=d[2][i][0];
        d[1][i][1]=d[2][i][1];
    }
    for(int i=1;i<=(n+1)/2;i++)
    {
        d[2][i][0]=d[3][i][0];
        d[2][i][1]=d[3][i][1];
    }
}
int main()
{
    freopen("Chills.inp","r",stdin);
   freopen("Chills.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            luu[i]=ans[i]=1e17;
        }
    for(int i=1;i<=3;i++)
        for(int j=1;j<=(n+1)/2;j++)
            d[i][j][1]=d[i][j][0]=1e17;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=(i+1)/2;j++)
        {
           if(i<=2)
               {
                   d[3][j][1]=max(1ll*0,a[i-1]-a[i]+1)+max(1ll*0,a[i+1]-a[i]+1);
                   d[3][j][0]=min(d[2][j][0],d[2][j][1]);
               }
           else
           {
               d[3][j][1]=max(1ll*0,a[i-1]-a[i]+1)+max(1ll*0,a[i+1]-a[i]+1)+d[1][j-1][0];
               if(j>1)
               {
                   d[3][j][1]=min(d[3][j][1],max(1ll*0,a[i+1]-a[i]+1)-max(1ll*0,a[i-1]-a[i-2]+1)+max(1ll*0,a[i-1]-min(a[i-2],a[i])+1)+d[1][j-1][1]);
               }
               d[3][j][0]=min(d[2][j][0],d[2][j][1]);
           }
            ans[j]=min({ans[j],d[3][j][1],d[3][j][0]});
        }
        dich();
    }
    for(int i=1;i<=(n+1)/2;i++)
        cout<<ans[i]<<" ";
}
