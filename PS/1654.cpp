#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll K, N, A[101010];

ll f(int x) {
	ll cnt = 0;
	for (int i = 1; i <= K; i++) cnt += A[i] / x;
	return cnt;
}

int main() {
	cin.tie(0), ios_base::sync_with_stdio(0);
	cin >> K >> N;
	for (int i = 1; i <= K; i++) cin >> A[i];

	ll l = 1, r = (1 << 31) - 1;
	while (l < r) {
		int m = (l + r + 1) / 2;
		if (f(m) >= N)
			l = m;
		else
			r = m - 1;
	}
	cout << l;
}