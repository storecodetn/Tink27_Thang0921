#include <bits/stdc++.h>
using namespace std;
int n,a[1000001],k,ans;
deque<int> q;
int main()
{
    freopen("BKMAX.INP","r",stdin);
    freopen("BKMAX.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        while(!q.empty() && a[q.back()]<=a[i])
            q.pop_back();
        while(!q.empty() && i-q.front()>=k)
            q.pop_front();
        q.push_back(i);
        if(i>=k)
            cout<<a[q.front()]<<" ";
    }
}
