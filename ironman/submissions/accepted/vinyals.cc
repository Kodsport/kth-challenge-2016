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
  double x=abs(sx-fx);

  double mxs0=1;
  for (int i=0;i<n;++i) mxs0=min(mxs0,v[0]/v[i]);

  double a=0,b=mxs0;
  double t;
  for (int it=0;it<100;++it) {
    double tx=0;
    t=0;
    double s0=(a+b)/2;
    for (int i=0;i<n;++i) {
      double s=s0*v[i]/v[0];
      double c=sqrt(1-s*s);
      double h=y[i]/c;
      double dx=h*s;
      double dt=h/v[i];
      //cerr << s << ' ' << c << ' ' << h << ' ' << dx << ' ' << dt << endl;
      tx+=dx;
      t+=dt;
    }
    if (tx<x) {
      a=s0;
    }
    else {
      b=s0;
    }
    //cerr << tx << endl;
  }
  printf("%.10f\n",t);
}
