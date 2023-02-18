#include <bitset>
#include <iostream>
#include <vector>
using namespace std;

typedef bitset<1000> config;
typedef vector<int> VI;
typedef vector<VI> VVI;

int main() {
  int n;
  cin >> n;
  VVI preds(n);
  for (VI& v : preds) {
    int p;
    cin >> p;
    v.resize(p);
    for (int& x : v) {
      cin >> x;
      --x;
    }
  }
  int t;
  cin >> t;
  config black;
  for (int i=0;i<t;++i) {
    int j;
    cin >> j;
    --j;
    black.flip(j);
    if (black.test(j)) {
      for (int p : preds[j]) {
        if (not black.test(p)) {
          cerr << "Error at move " << (i+1) << endl;
          cerr << "Predecessor " << p << " of " << j << " is not pebbled" << endl;
          return 43;
        }
      }
    }
  }
  return 42;
}
