#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll N, A[101010];

ll rect(const ll s, const ll e) {
	if (s >= e) return A[s];

	ll m = (s + e) / 2, l = m, r = m;
	ll ret = A[m], h = A[m], len = 1;

	while (l >= s && r <= e) {
		if (A[l - 1] > A[r + 1])
			h = min(h, A[--l]);
		else
			h = min(h, A[++r]);
		ret = max(ret, h * ++len);
	}
	while (l >= s) {
		h = min(h, A[--l]);
		ret = max(ret, h * ++len);
	}
	while (r <= e) {
		h = min(h, A[++r]);
		ret = max(ret, h * ++len);
	}
	ret = max(ret, rect(s, m - 1));
	ret = max(ret, rect(m + 1, e));
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];
	cout << rect(1, N);
}