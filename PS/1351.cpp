#include <bits/stdc++.h>
using namespace std;
using ll = long long;
map<ll, ll> M;
ll N, P, Q;

ll f(ll n) {
	if (M.find(n) == M.end()) {
		return M[n] = f(n / P) + f(n / Q);
	}
	return M[n];
}

int main() {
	cin >> N >> P >> Q;
	M[0] = 1;
	cout << f(N);
}