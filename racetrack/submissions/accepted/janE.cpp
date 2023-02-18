#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> t (n), c (n);
    for (int i = 0; i < n; i++) cin >> t[i] >> c[i];

    vector<int> start (n, 0);
    deque<int> Q;
    for (int i = 0; i < n; i++) Q.push_back(i);

    while (!Q.empty()) {
        int t_finish = start[Q[0]]+t[Q[0]];
        vector<int> players;
        while (!Q.empty() && start[Q[0]]+t[Q[0]] <= t_finish) players.push_back(Q[0]), Q.pop_front();
        sort(players.begin(),players.end());
        for (int i : players) {
            start[i] = t_finish;
            c[i]--; if (c[i] > 0) Q.push_back(i);
        }
    }

    for (int i = 0; i < n; i++) printf("%d\n", start[i]);
}
