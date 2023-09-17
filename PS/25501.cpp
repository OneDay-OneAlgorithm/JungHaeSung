#include <bits/stdc++.h>
using namespace std;
int cnt;

int recursion(const string& s, int l, int r) {
	cnt++;
	if (l >= r) return 1;
	if (s[l] != s[r]) return 0;
	return recursion(s, l + 1, r - 1);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int T;
	cin >> T;
	while (T--) {
		cnt = 0;
		string s;
		cin >> s;
		cout << recursion(s, 0, s.length() - 1) << ' ' << cnt << '\n';
	}
}