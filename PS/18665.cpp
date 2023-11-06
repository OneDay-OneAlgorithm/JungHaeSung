#include <bits/stdc++.h>
using namespace std;
using ll = long long;
set<ll> s = {0, 1, 2};

void Get(ll n) {
	ll x = 0, y;
	while (x * x < n) x++;
	y = x * x - n;
	if (s.count(x) == 0) Get(x), s.insert(x);
	if (s.count(y) == 0) Get(y), s.insert(y);
	cout << x << ' ' << y << '\n';
}

int main() {
	ll N;
	cin >> N;
	Get(N);
}