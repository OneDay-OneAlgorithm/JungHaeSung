#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int N, M, P[202020];
vector<int> X;

int range(int x) { return x / 100 - (x % 100 == 0 ? 1 : 0); }

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> P[i];
	X.resize(M);
	for (int& x : X) cin >> x;
	sort(X.begin(), X.end());

	ll ans = 0;
	for (int i = 0; i < M; i++) {
		// i번째 가게 바로 왼쪽에 두는 경우
		ll left_tot = 0;
		int cur_range = range(X[i]);
		if (i == 0) {
			for (int k = 0; k <= cur_range; k++) left_tot += P[k];
		} else {
			int p = range(X[i - 1]) + 1;
			for (int k = p; k <= cur_range; k++)
				if (abs(X[i - 1] - k * 100) > abs(X[i] - k * 100)) left_tot += P[k];
		}
		// 오른쪽에 두는 경우
		ll right_tot = 0;
		if (i == M - 1) {
			for (int k = cur_range + 1; k < N; k++) right_tot += P[k];
		} else {
			int p = range(X[i + 1]);
			for (int k = cur_range + 1; k <= p; k++)
				if (abs(X[i + 1] - k * 100) > abs(X[i] - k * 100)) right_tot += P[k];
		}
		ans = max({ans, left_tot, right_tot});
		printf("(%d) %lld %lld\n", i, left_tot, right_tot);
	}
	cout << ans;
}