#include <bitset>
#include <iostream>
#include <vector>
using namespace std;

typedef bitset<1000> config;

vector<int> seq;
void mkseq(int a, int b) {
  if (a>b) return;
  if (a==b) {
    seq.push_back(b);
    return;
  }
  int mid=(a+b)/2;
  mkseq(a,mid);
  mkseq(mid+1,b);
  mkseq(a,mid);
}

int main() {
  int n;
  cin >> n;
  string dummy;
  for (int i=0;i<=n;++i) getline(cin,dummy);
  int t;
  cin >> t;
  vector<int> moves;
  vector<config> unsafe;
  config black;
  for (int i=0;i<t;++i) {
    int j;
    cin >> j;
    --j;
    black.flip(j);
    if (black.test(j)) unsafe.push_back(black);
  }
  mkseq(1,unsafe.size());
  config path;
  config prev;
  vector<int> out;
  for (int x : seq) {
    //cerr << x-1 << endl;
    path.flip(x-1);
    config curr;
    for (int i=0;i<t;++i) if (path.test(i)) curr|=unsafe[i];
    for (int i=0;i<n;++i) if (curr.test(i) and not prev.test(i)) out.push_back(i);
    for (int i=0;i<n;++i) if (prev.test(i) and not curr.test(i)) out.push_back(i);
    prev=curr;
  }
  cout << out.size() << endl;
  for (int x: out) cout << x+1 << endl;
}
