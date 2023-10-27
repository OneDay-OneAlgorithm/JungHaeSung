#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll s, N, K, R1, R2, C1, C2;

int isBlack(ll r, ll c, ll width) {
	if (width == 1) return 0;
	ll seg = width / N;
	ll pad = seg * (N - K) / 2;	 // 흰색 부분 패딩

	if (pad <= c && c < (pad + K) * seg && pad <= r && r < (pad + K) * seg) return 1;
	return isBlack(r % seg, c % seg, width / N);
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> s >> N >> K >> R1 >> R2 >> C1 >> C2;
	ll width = 1;
	for (int i = 1; i <= s; i++) width *= N;

	for (ll r = R1; r <= R2; r++) {
		for (ll c = C1; c <= C2; c++) cout << isBlack(r, c, width);
		cout << '\n';
	}
}