#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int N, L, W, H;
const double e = 1e-10;

ll f(double w) {
	ll a = L / w, b = W / w, c = H / w;
	return a * b * c;
}

int main() {
	cin >> N >> L >> W >> H;
	int t = 0;
	double l = 0, r = 1e9;
	while (l < r - e) {
		double m = (l + r) / 2;
		if (f(m) < N)
			r = m - e;
		else
			l = m;
		if (t++ > 10000) break;
	}
	printf("%.10lf", l);
}