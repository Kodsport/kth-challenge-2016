#include <iostream>
#include <sstream>
#include <vector>
using namespace std;
typedef long long ll;

class bigint {
public:
  vector<int> v;
  bigint(const string& s) {
    v.reserve(s.length()/9+1);
    for (int i=s.length()-1;i>=0;i-=9) {
      int x=0;
      for (int j=max(i-8,0);j<=i;++j) {
        x*=10;
        x+=s[j]-'0';
      }
      v.push_back(x);
    }
  }
  int operator /= (int y) {
    ll x=0;
    for (int i=v.size()-1;i>=0;--i) {
      x*=1000000000;
      x+=v[i];
      v[i]=x/y;
      x%=y;
    }
    return x;
  }
  void print() {
    bool started=false;
    for (int i=v.size()-1;i>=0;--i) {
      int x=v[i];
      if (started) printf("%09d",x);
      else if (x) {
        started=true;
        printf("%d",x);
      }
    }
    if (not started) printf("0");
    printf("\n");
  }
  int digits() {
    for (int i=v.size()-1;i>=0;--i) {
      int x=v[i];
      if (x) {
        int front=0;
        while(x) {
          ++front;
          x/=10;
        }
        return front+i*9;
      }
    }
    return 1;
  }
};

int main() {
  string s;
  cin >> s;
  bigint n(s);
  for (int d=s.length();;--d) {
    bigint ans(n);
    if ((ans/=d)==0 and ans.digits()==d) {
      ans.print();
      break;
    }
  }
}
