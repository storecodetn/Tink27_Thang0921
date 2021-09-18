#include <bits/stdc++.h>
using namespace std;
FILE *fi = freopen("BKMAX.inp", "r", stdin);
FILE *fo = freopen("BKMAX.out", "w", stdout);
const int maxn = 1e6+10;
int n, k;
int a[maxn];
class solve{
private:
  deque<int> dq;
public:
  void sub1(int n, int k)
  {
    vector<int> ans;
    for (int i=1; i<=n-k+1; i++)
    {
      ans.push_back(*max_element(a+i, a+k+i));
    }
    for (auto v:ans)
      cout<<v<<" ";
  }
  void sub2(int n, int k)
  {
    vector <int> ans;
    for (int i = 1; i<=n; i++)
    {
      while(dq.size() && a[dq.back()] <= a[i])
        dq.pop_back();
      dq.push_back(i);
      if(i - dq.front() >= k) dq.pop_front();
      if(i >= k) ans.push_back(a[dq.front()]);
    }
    for (auto v:ans)
      cout<<v<<" ";
  }
}solve;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(); cout.tie();
  cin>>n>>k;
  for (int i=1; i<=n; i++)
  {
    cin>>a[i];
  }
  if(n <= 1000)
    solve.sub1(n, k);
  else solve.sub2(n, k);
  return 0; 
}