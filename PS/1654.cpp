#include <bits/stdc++.h>
using namespace std;
int K, N, A[101010];

int f(int x) {
	int cnt = 0;
	for (int i = 1; i <= K; i++) cnt += A[i] / x;
	return cnt;
}

int main() {
	cin.tie(0), ios_base::sync_with_stdio(0);
	cin >> K >> N;
	for (int i = 1; i <= K; i++) cin >> A[i];

	int l = 1, r = (1 << 30) - 1;
	while (l < r) {
		int m = (l + r + 1) / 2;
		if (f(m) >= N)
			l = m;
		else
			r = m - 1;
	}
	cout << l;
}