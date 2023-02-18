#include <iostream>
#include <vector>
#include <list>
#include <tuple>
#include <algorithm>

using namespace std;
typedef vector<int> VI;
typedef pair<int,VI> PIVI;
typedef list<PIVI> LP;

LP::iterator insert(LP& v, int t, int i, LP::iterator hint) {
  for(;hint!=v.end() and hint->first<t;++hint);
  if (hint==v.end() or hint->first>t) {
    return v.insert(hint,PIVI(t,VI(1,i)));
  }
  else {
    hint->second.push_back(i);
    return hint;
  }
}

int main() {
  int n;
  cin >> n;
  VI ti(n), c(n), ans(n);
  LP next;
  auto hint=next.end();
  for (int i=0;i<n;++i) {
    cin >> ti[i] >> c[i];
    hint = insert(next,ti[i],i,hint);
  }
  for (auto it=next.begin();it!=next.end();++it) {
    int t=it->first;
    VI& v=it->second;
    sort(v.begin(),v.end());
    hint=it;
    for (int i : v) {
      if(--c[i]) {
        int nt=t+ti[i];
        nt=max(nt,next.back().first);
        hint=insert(next,nt,i,hint);
      }
      else ans[i]=t;
    }
  }
  for (int a : ans) cout << a << endl;
}
