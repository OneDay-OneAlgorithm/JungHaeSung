#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll N;

int main() {
	cin >> N;
	if (N == 0) {
		cout << 0;
		return 0;
	}
	int ans = 0;
	while (N > (ll)1 << ans) ans++;

	if (N == 1 << (ans - 1))
		cout << ans;
	else
		cout << ans + 1;
	return 0;
}