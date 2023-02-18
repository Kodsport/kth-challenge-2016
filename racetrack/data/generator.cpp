#include<bits/stdc++.h>
using namespace std;
int main(int argc, char** argv) { // n, maxT, maxC, seed
    if (argc != 5) fprintf(stderr, "Usage: %s <n> <maxT> <maxC> <seed>\n", argv[0]), exit(1);
    assert(argc == 5);
    int n = atoi(argv[1]), maxT = atoi(argv[2]), maxC = atoi(argv[3]), seed = atoi(argv[4]);
    fprintf(stderr, "Input: n=%d, maxT=%d, maxC=%d, seed=%d\n", n, maxT, maxC, seed);
    srand(seed);
    assert(n <= 5000 && maxT <= 1000000 && maxC <= 1000);
    printf("%d\n", n);
    vector<int> times (n); for (int i=0; i<n; i++) times[i] = 1 + rand() % maxT; sort(times.begin(), times.end());
    for (int i=0; i<n; i++) printf("%d %d\n", times[i], 1 + rand() % maxC);
}
