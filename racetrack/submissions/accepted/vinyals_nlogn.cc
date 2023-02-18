#include <iostream>
#include <set>
#include <vector>
#include <tuple>

using namespace std;
typedef pair<int,int> PII;

int main() {
  int n;
  cin >> n;
  vector<int> ti(n), c(n), ans(n);
  set<PII> next;
  for (int i=0;i<n;++i) {
    cin >> ti[i] >> c[i];
    next.insert(PII(ti[i],i));
  }
  while(not next.empty()) {
    auto it=next.begin();
    int t,i;
    tie(t,i)=*it;
    next.erase(it);
    if(--c[i]) {
      int nt=t+ti[i];
      if (not next.empty()) {
        nt=max(nt,next.rbegin()->first);
      }
      next.insert(PII(nt,i));
    }
    else ans[i]=t;
  }
  for (int a : ans) cout << a << endl;
}
