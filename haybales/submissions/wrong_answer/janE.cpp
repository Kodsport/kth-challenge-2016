#include<bits/stdc++.h>
using namespace std;

bool sorted(string s) {
    string t = s; sort(t.begin(), t.end()); return s == t;
}

int solution(string s) {
    int answer = 0;
    while (!sorted(s)) {
        for(int i=0;i<(int)s.size()-2;i++)if(!sorted(s.substr(i,3))){sort(s.begin()+i,s.begin()+i+3);goto nxt;}
        nxt:;
        answer++;
    }
    return answer;
}

int main() {
    string s; cin >> s; cout << solution(s) << endl;
}
