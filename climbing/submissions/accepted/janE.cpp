#include <bits/stdc++.h>
using namespace std;

vector<int> sequence(int ofs, int n) {
	if (n == 1) {
		return vector<int> (1, 1+ofs);
	} else {
		vector<int> a = sequence(ofs, n/2);
		vector<int> b = sequence(ofs + n/2, n - n/2);
		vector<int> re;
		re.insert(re.end(),a.begin(),a.end());
		re.insert(re.end(),b.begin(),b.end());
		re.insert(re.end(),a.rbegin(),a.rend());
		return re;
	}
}

/*int main() {
	int n = 1000;
	int space = 0;
	string s = "x"; for (int i=0;i<n;i++) s += '.';
	for (int pos : sequence(0, n)) {
		assert(s[pos-1]=='x');
		s[pos] = s[pos] == 'x' ? '.' : 'x';
		space = max(space, (int)count(s.begin()+1, s.end(), 'x'));
	}
	cout << space << endl;
}*/

int n;
vector<int> preds[1005];
bool active[1005][1005];

int main() {
	cin >> n;
	for (int x=1; x<=n; x++) {
		int npreds; cin >> npreds;
		preds[x].resize(npreds);
		for (int i=0; i<npreds; i++) cin >> preds[x][i];
	}
	int le; cin >> le;
	vector<int> seq (1+le);
	memset(active,0,sizeof active);
	for (int i=1;i<=le;i++){
		cin>>seq[i];
		for(int x=1;x<=n;x++)active[i][x]=active[i-1][x];
		active[i][seq[i]]=!active[i][seq[i]];
	}
	
	string s = "x"; for (int i=0;i<le;i++) s += '.';
	vector<int> counter (n+1, 0);
	vector<int> answer;
	for (int pos : sequence(0, le)) {
		if (s[pos] == '.') {
			s[pos] = 'x';
			for (int x=1;x<=n;x++) if (active[pos][x]) {
				if (counter[x]==0) answer.push_back(x);
				counter[x]++;
			}
		} else {
			s[pos] = '.';
			for (int x=1;x<=n;x++) if (active[pos][x]) {
				if (counter[x]==1) answer.push_back(x);
				counter[x]--;
			}
		}
	}
	cout << (int) answer.size() << endl;
	for (int x : answer) cout << x << endl;
}
