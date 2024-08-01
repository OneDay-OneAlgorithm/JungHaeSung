# SWERC 2021-2022
https://www.acmicpc.net/category/detail/3100

## A
```cpp
#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, A[11], b, d, sum = 0;
	memset(A, -1, sizeof A);
	cin >> n;
	while (n--) {
		cin >> b >> d;
		A[d] = max(A[d], b);
	}
	for (int i = 1; i <= 10; i++) {
		if (A[i] == -1) {
			cout << "MOREPROBLEMS\n";
			return;
		}
		sum += A[i];
	}
	cout << sum << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) solve();
}
```

## F
```cpp
#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, m, R = 0, W = 0;
	cin >> n >> m;
	for (int i = 1, r, w; i <= m; i++) {
		cin >> r >> w;
		R = max(R, r);
		W = max(W, w);
	}
	if (R + W > n) {
		cout << "IMPOSSIBLE\n";
		return;
	}
	for (int i = 1; i <= R; i++) cout << 'R';
	for (int i = 1; i <= W; i++) cout << 'W';
	for (int i = 1; i <= n - R - W; i++) cout << 'W';
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) solve();
}
```

## J
```cpp
#include <bits/stdc++.h>
using namespace std;

void solve() {
	int w, l;
	cin >> w >> l;
	if (w > l) swap(w, l);
	set<int> ans = {1, 2};
	{
		int g = __gcd(w - 1, l - 1), sg = sqrt(g) + 1;
		for (int i = 1; i <= sg; i++)
			if (g % i == 0) ans.insert(i), ans.insert(g / i);
	}
	{
		int g = __gcd(l - 2, w), sg = sqrt(g) + 1;
		for (int i = 1; i <= sg; i++)
			if (g % i == 0) ans.insert(i), ans.insert(g / i);
	}
	{
		int g = __gcd(l, w - 2), sg = sqrt(g) + 1;
		for (int i = 1; i <= sg; i++)
			if (g % i == 0) ans.insert(i), ans.insert(g / i);
	}
	cout << ans.size() << ' ';
	for (int a : ans) cout << a << ' ';
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) solve();
}
```