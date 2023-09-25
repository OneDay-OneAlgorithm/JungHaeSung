#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll L[55], P[55];

ll Patty(int level, ll layer) {
	if (level == 0 && layer > 0) return 1;
	if (layer >= L[level]) return P[level];
	if (layer >= 2 + L[level - 1])
		return P[level - 1] + Patty(level - 1, layer - L[level - 1] - 2) + 1;
	if (layer > 1) return Patty(level - 1, layer - 1);
	return 0;
}

int main() {
	P[0] = L[0] = 1;
	for (int i = 1; i <= 50; i++) {
		L[i] = 2 * L[i - 1] + 3;
		P[i] = 2 * P[i - 1] + 1;
	}
	ll N, X;
	cin >> N >> X;
	cout << Patty(N, X);
}