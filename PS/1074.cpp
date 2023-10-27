#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll N, R, C;

ll Z(ll r, ll c, ll width, ll init) {
	if (width == 1) return init;
	ll h = width / 2;
	ll s = h * h;
	if (r >= h)
		if (c >= h)
			return Z(r - h, c - h, h, init + s * 3);
		else
			return Z(r - h, c, h, init + s * 2);

	if (c >= h) return Z(r, c - h, h, init + s);
	return Z(r, c, h, init);
}

int main() {
	cin >> N >> R >> C;
	cout << Z(R, C, 1 << N, 0);
}