#include <bits/stdc++.h>
using namespace std;
int N, K, S;
double dp[10005][505];
int main() {
	cin >> N >> S >> K;
	fill(dp[0],dp[0]+S,0); dp[0][0] = 1;
	for (int i=0; i<N; i++) {
		fill(dp[i+1],dp[i+1]+S,0);
		for (int at=0; at<=S; at++) dp[i+1][at] += dp[i][at] * (double)at/(double)S, dp[i+1][at+1] += dp[i][at] * (double)(S-at)/(double)S;
	}
	double answer = 0; for (int i=K; i<=S; i++) answer += dp[N][i];
	printf("%.9lf\n",answer);
}
