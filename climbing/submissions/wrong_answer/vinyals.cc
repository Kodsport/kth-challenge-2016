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
  config black;
  for (int i=0;i<=t;++i) {
    int j;
    cin >> j;
    --j;
    black.flip(j);
    if (black.test(j)) moves.push_back(j+1);
  }
  mkseq(1,moves.size());
  cout << seq.size() << endl;
  for (int x : seq) {
    cout << moves[x-1] << endl;
  }
}
