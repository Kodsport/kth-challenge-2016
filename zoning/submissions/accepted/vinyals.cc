#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
typedef queue<int> QI;
const int INF=1<<29;
const int di[4]={1,0,-1,0};
const int dj[4]={0,1,0,-1};

char board[1510][1510];
char seen[1510][1510];
int d[1510][1510];

int main() {
  memset(seen,0,sizeof(seen));
  int n;
  cin >> n;
  for (int i=0;i<n;++i) cin >> board[i];
  QI curr,next;
  for (int i=0;i<n;++i) {
    for (int j=0;j<n;++j) {
      if (board[i][j]=='3') {
        d[i][j]=0;
        curr.push(i);curr.push(j);
      }
      else {
        d[i][j]=INF;
      }
    }
  }
  int ans=0;
  int t=0;
  while(not curr.empty()) {
    while(not curr.empty()) {
      int i=curr.front();curr.pop();
      int j=curr.front();curr.pop();
      if (seen[i][j]) continue;
      seen[i][j]=true;
      if (board[i][j]=='1') ans=max(ans,d[i][j]);
      //      cerr << t << ' ' << i << ' ' << j << endl;
      for (int k=0;k<4;++k) {
        int ni=i+di[k];
        int nj=j+dj[k];
        if (ni<0 or ni>=n or nj<0 or nj>=n) continue;
        bool samezone = board[i][j]==board[ni][nj];
        samezone=false;
        int nt=t+(samezone?0:1);
        if (nt>=d[ni][nj]) continue;
        d[ni][nj]=nt;
        if (samezone) {
          curr.push(ni);
          curr.push(nj);
        }
        else {
          next.push(ni);
          next.push(nj);
        }
      }
    }
    ++t;
    swap(curr,next);  
  }
  cout << ans << endl;
}
