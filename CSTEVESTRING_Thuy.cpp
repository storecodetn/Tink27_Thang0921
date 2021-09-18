#include <bits/stdc++.h>
using namespace std;
int t,f[105][5],n,res,b[105][105][5];
string s;
bool checker;
bool sol(int l, int r, int o){
    if (b[l][r][o]!=-1) return b[l][r][o];
    if (l==r){
        if (o==s[l]-'a'+1) return b[l][r][o]=1;
        else return b[l][r][o]=0;
    }
    bool che=0;
    int o1=1; int o2=2;
    if (o==1) o1=3;
    if (o==2) o2=3;
    for (int i=l; i<r; i++){
        if (sol(l,i,o1)==1 && sol(i+1,r,o2)==1){
            che=1; break;
        }
        if (sol(l,i,o2)==1 && sol(i+1,r,o1)==1){
            che=1; break;
        }
    }
    return b[l][r][o]=che;
}
int main(){
    freopen("CSTEVESTRING.inp","r",stdin);
    freopen("CSTEVESTRING.out","w",stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        cin>>s; n=s.size(); s=" "+s;
        for (int i=1; i<=n; i++){
            for (int j=1; j<=3; j++){
                f[i][j]=n+1;
                for (int k=1; k<=n; k++){
                    b[i][k][j]=-1;
                }
            }
            b[i][i][s[i]-'a'+1]=1;
        }
        f[1][s[1]-'a'+1]=1;
        for (int i=2; i<=n; i++){
            for (int j=0; j<i; j++){
                for (int k=1; k<=3; k++){
                    checker=sol(j+1,i,k);
                    if (checker==1){
                        f[i][k]=min(f[i][k],f[j][k]+1);
                    }
                }
            }
        }
        cout<<min(f[n][1],min(f[n][2],f[n][3]))<<"\n";
    }
}
