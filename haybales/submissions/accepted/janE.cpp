#include<bits/stdc++.h>
using namespace std;

bool sorted(string s) { string t = s; sort(t.begin(), t.end()); return s == t; }

int solution(string s) {
    int answer = 0;
    while (!sorted(s)) {
        vector<string> vv = {"PCC", "PPC", "PCP", "CPC"};
        for (string p : vv) if (s.find(p) != string::npos) { int i = s.find(p); sort(s.begin()+i, s.begin()+i+3); goto nxt; }
        nxt:;
        answer++;
    }
    return answer;
}

int main() {
    string s; cin >> s; cout << solution(s) << endl;
}
