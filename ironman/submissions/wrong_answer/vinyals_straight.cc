#include <iostream>
#include <vector>
#include <cassert>
#include <cstdio>
#include <cmath>

using namespace std;

int main() {
  double sx,sy,fx,fy;
  cin >> sx >> sy >> fx >> fy;
  int n;
  cin >> n;
  vector<double> v(n), y(n);
  for (int i=0;i<n-1;++i) cin >> y[i];
  y[n-1]=fy;
  for (double& xx : v) cin >> xx;
  for (int i=n-1;i>0;--i) y[i]-=y[i-1];
  y[0]-=sy;

  double dx=abs(sx-fx);
  double dy=fy-sy;
  double hy=hypot(dx,dy)/dy;

  double t=0;
  for (int i=0;i<n;++i) t+=y[i]*hy/v[i];

  printf("%.10f\n",t);
}
