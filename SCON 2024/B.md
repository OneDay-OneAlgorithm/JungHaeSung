https://www.acmicpc.net/problem/31832
```cpp
#include <bits/stdc++.h>
using namespace std;
int N;

bool checkAlpha(const string& s) {
	int a = 0, b = 0, n = 0;
	for (char c : s) {
		if ('a' <= c && c <= 'z') ++a;
		if ('A' <= c && c <= 'Z') ++b;
		if ('0' <= c && c <= '9') ++n;
	}
	return n != s.length() && a >= b;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	while (N--) {
		string s;
		cin >> s;
		if (s.length() <= 10 && checkAlpha(s)) {
			cout << s;
			break;
		}
	}
}
```