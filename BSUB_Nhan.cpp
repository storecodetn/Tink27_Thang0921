#include <bits/stdc++.h>
using namespace std;
FILE *fi = freopen("BSUB.inp", "r", stdin);
FILE *fo = freopen("BSUB.out", "w", stdout);
const int maxn = 1e5+10;
int64_t n, t, a[maxn];

int64_t kadane()
{
  int64_t res_tmp = 0, ans = INT_MIN;
  for (int i=1; i<=n; i++)
  {
    res_tmp += a[i];
    if(ans < res_tmp)
      ans = res_tmp;
    if(res_tmp < 0)
    {
      res_tmp = 0;
    }
  }
  return ans;
}

int64_t calc()
{
  int64_t mx = INT_MIN;
  int64_t ans = 0;
  bool f = 0;
  for (int i=1; i<=n; i++)
  {
    mx = max(mx, a[i]);
    if(a[i] >= 0)
    {
      f = 1;
      ans += a[i];
    }
  }
  if(f == 0)
  {
    return mx;
  }
  else return ans;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(); cout.tie();
  cin>>t;
  while(t--)
  {
    cin>>n;
    for (int i=1; i<=n; i++) cin>>a[i];
    cout<<calc()<<" "<<kadane()<<"\n";
  } 

  return 0;
}