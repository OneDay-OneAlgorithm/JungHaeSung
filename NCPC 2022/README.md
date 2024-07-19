# NCPC 2022
https://www.acmicpc.net/category/detail/3224

## C
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	string s;
	cin >> N >> s;
	int cup = 0, ans = 0;
	for (char c : s) {
		if (c == '1')
			cup = 2, ++ans;
		else if (cup > 0)
			++ans, --cup;
	}
	cout << ans;
}
```

## D
```cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ll r, ansx, ansy, min_dist = 1e18;
	cin >> r;
	for (ll x = 1, y = r; x <= y; x++) {
		while (x * x + (y - 1) * (y - 1) > r * r) --y;
		ll dist = x * x + y * y;
		if (dist < min_dist) {
			min_dist = dist;
			ansx = x, ansy = y;
		}
	}
	cout << ansx << ' ' << ansy;
}
```
아니 `sqrt`쓰면 왜 안 됨?

## H
```cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll N;
	vector<ll> v;
	bool inc = false;
	cin >> N;
	for (ll i = 1, t; i <= N; i++) {
		cin >> t;
		if (v.empty())
			v.push_back(t);
		else if (v.back() == t || (inc && v.back() < t || !inc && v.back() > t))
			v.pop_back(), v.push_back(t);
		else {
			inc = v.back() < t;
			v.push_back(t);
		}
	}
	ll ans = 0;
	for (int i = 1; i < v.size() - 1; i++) {
		if (v[i - 1] <= v[i] && v[i] >= v[i + 1])
			ans = max(ans, min(v[i] - v[i - 1], v[i] - v[i + 1]));
	}
	cout << ans;
}
```