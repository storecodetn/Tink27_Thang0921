#include <bits/stdc++.h>
using namespace std;
int t,r,n,a,b,c,o;
int main(){
    freopen("BACTOR.inp","r",stdin);
    freopen("BACTOR.out","w",stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>r;
    cin>>t;
    while(t--){
        cin>>n>>a>>b>>c;
        if (r==1){
            o=3*n-(a+b+c);
            if(o>=n) cout<<0<<"\n";
            else cout<<n-o<<"\n";
        }
        else{
            cout<<min(a,min(b,c))<<"\n";
        }
    }
}
