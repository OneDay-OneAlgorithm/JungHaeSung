#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int A[404040];
	ll N, C;
	cin >> N >> C;
	for (int i = 1; i <= N; i++) cin >> A[i];

	for (int i = 1; i <= N; i++) {
		ll mx = 0;
		for (int j = i; j >= 1; j--) mx = max(mx, abs(A[i] - A[j]) - C * (i - j));
		cout << mx << ' ';
	}
}