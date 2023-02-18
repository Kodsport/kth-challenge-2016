#include <iostream>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	string ss;
	cin >> ss;
	int n = ss.size();
	if (ss == "0") printf("0\n");
	else {
		int numlen = max(0, n - 7);
		while (true) {
			string nlstr = to_string(numlen + 1);
			int slen = nlstr.size() + numlen;
			if (slen > n) break;
			if (slen == n && nlstr > ss.substr(0, nlstr.size())) {
				break;
			}
			numlen++;
		}
		bool leading = true;
		int cur = 0;
		for (char c : ss) {
			cur = 10 * cur + c - '0';
			int div = cur / numlen;
			cur %= numlen;
			if (div != 0) {
				putchar(div + '0');
				leading = false;
			} else if (!leading) putchar('0');
		}
		puts("");
	}
}
