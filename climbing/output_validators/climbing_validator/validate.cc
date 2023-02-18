#include "streamcorr.h"

#include <bitset>
#include <vector>
#include <sstream>
using namespace std;
typedef bitset<1000> config;
typedef vector<int> VI;
typedef vector<VI> VVI;

int main(int argc, char **argv) {
  init_io(argc,argv);

  int n;
  judge_in >> n;
  VVI preds(n);
  for (VI& v : preds) {
    int p;
    judge_in >> p;
    v.resize(p);
    for (int& x : v) {
      judge_in >> x;
      --x;
    }
  }
  int t;
  judge_in >> t;
  size_t s=0;
  config black;
  for (int i=0;i<=t;++i) {
    int j;
    judge_in >> j;
    --j;
    black.flip(j);
    s=max(s,black.count());
  }
  
  if (!(author_out >> t)) report_error("Could not read number of moves");
  if (t>1000000) report_error("Too many moves");
  config reversible;
  config visited;
  size_t rs=0;
  for (int i=0;i<t;++i) {
    int j;
    if (!(author_out >> j)) report_error("Could not read move %d",i+1);
    if (j<1 or j>n) report_error("Move %d out of bounds",i+1);
    --j;
    for (int p : preds[j]) {
      if (!reversible[p]) report_error("Invalid move %d",i+1);
    }
    reversible.flip(j);
    rs=max(rs,reversible.count());
    visited.set(j);
  }

  if (rs>10*s) report_error("Using %d pegs, limit is %d",rs,10*s);
  if (visited.count()!=n) report_error("Did not visit all vertices");

  /* Check for trailing output in author file. */
  string trash;
  if (author_out >> trash) report_error("Trailing output");
  accept();
}
