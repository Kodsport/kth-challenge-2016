#include <iostream>
#include <numeric>
#include <cstdio>
using namespace std;

#define rep(i,a,b) for(__typeof(b) i=a; i<(b); ++i)

typedef long long ll;
double pr[10001][1001];
int main()
{
    int n, s, k;

    while (scanf("%d %d %d", &n, &s, &k) == 3)
    {
        rep(i,0,n+1) rep(j,0,k+1)
            pr[i][j] = 0;

        pr[0][0] = 1;
        rep(i,0,n) rep(j,0,k)
            if (pr[i][j] > 0)
        {
            double p = double(j) / s;
            pr[i + 1][j + 1] += pr[i][j] * (1 - p);
            pr[i + 1][j] += pr[i][j] * p;
        }

        double res = accumulate(pr[n], pr[n] + k, 0.0);
        printf("%.9lf\n", 1 - res);
    }
}
