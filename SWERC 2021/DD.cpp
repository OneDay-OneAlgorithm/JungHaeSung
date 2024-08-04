#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll N, M, S[202020];
vector<int> X;

ll range(ll x) {
	ll ret = x / 100 - (x % 100 == 0 ? 1 : 0);
	return min(ret, N - 1);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	cin >> S[0];
	for (int i = 1; i < N; i++) cin >> S[i], S[i] += S[i - 1];
	X.resize(M);
	for (int& x : X) cin >> x;
	sort(X.begin(), X.end());

	ll ans = max(S[range(X[0])], S[range(X[M - 1])]);

	for (int i = 0; i < M - 1; i++) {
		// i ~ i+1
		int l = range(X[i]), r = range(X[i + 1]);
		ll tot = 0;
		if (l == r) continue;
		if (l + 1 == r) {
			tot = S[r] - S[r - 1];
		} else {
			int _l = (l + 1) * 100 * 2 - X[i];
			int _r = r * 100 * 2 - X[i + 1];
			if (_l <= _r) {
				tot = S[_r / 100] - S[_l / 100];
				tot += max(S[_l / 100] - S[l], S[r] - S[_r / 100]);
			} else {
				tot = S[r] - S[l];
			}
		}
		printf("(%d) %lld\n", i, tot);
		ans = max(ans, tot);
	}
	cout << ans;
}