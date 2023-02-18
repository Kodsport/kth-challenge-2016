#include <iostream>
#include <vector>
#include <cassert>
#include <cstdio>
#include <cmath>

using namespace std;

int n;
vector<double> v,y;

double cost(int i, double x) {
  return hypot(x,y[i])/v[i];
}

double opt(int i, double x) {
  if (i==n-1) return cost(i,x);
  double a=0,b=x,ret;
  for (int it=0;it<30;++it) {
    double m1=2*a/3+b/3;
    double m2=a/3+2*b/3;
    double t1=opt(i+1,m1)+cost(i,x-m1);
    double t2=opt(i+1,m2)+cost(i,x-m2);
    if (t1<t2) {
      b=m2;
      ret=t1;
    }
    else {
      a=m1;
      ret=t2;
    }
  }
  return ret;
}

int main() {
  double sx,sy,fx,fy;
  cin >> sx >> sy >> fx >> fy;
  cin >> n;
  v.resize(n);
  y.resize(n);
  for (int i=0;i<n-1;++i) cin >> y[i];
  y[n-1]=fy;
  for (double& xx : v) cin >> xx;
  for (int i=n-1;i>0;--i) y[i]-=y[i-1];
  y[0]-=sy;
  double x=abs(sx-fx);

  printf("%.10f\n",opt(0,x));
}
