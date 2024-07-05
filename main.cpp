#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll N, A[101010], dp[101010];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];

	for (int i = 1; i <= N; i++) {
		dp[i] = dp[i - 1];
		int sum = 0;
		for (int j = i; j >= 1; j--) {
			sum += A[j];
			if (sum % 2 == 1) ++dp[i];
		}
	}
	cout << dp[N];
}