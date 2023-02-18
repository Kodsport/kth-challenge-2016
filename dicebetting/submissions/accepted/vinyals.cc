#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

double dp[10010][510];

int main() {
  int n,s,k;
  cin >> n >> s >> k;
  memset(dp,0,sizeof(dp));
  dp[0][0]=1;
  for (int i=0;i<=n;++i) {
    for (int j=0;j<=s;++j) {
      double p=j/double(s);
      double q=(s-j)/double(s);
      dp[i+1][j]+=p*dp[i][j];
      dp[i+1][j+1]+=q*dp[i][j];
    }
  }
  double ans=0;
  for (int j=k;j<=s;++j) ans+=dp[n][j];
  printf("%.10f\n",ans);
}
