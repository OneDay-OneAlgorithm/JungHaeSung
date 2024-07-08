#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// 가중치가 0인 아이템이 앞뒤로 K개 있다고 생각
// dp[1][i]: i번째를 선택하는 최대값, dp[0][i]: i번째를 선택하지 않는 최대값
ll N, K, S[2020202], dp[2][2020202];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> K;

	for (int i = K + 1; i <= N + K; i++) cin >> S[i], S[i] += S[i - 1];
	for (int i = N + K + 1; i <= N + K * 2; i++) S[i] = S[i - 1];
	for (int i = K + 1; i <= N + K * 2; i++) {
		dp[0][i] = max(dp[0][i - 1], dp[1][i - 1]);

		// i번째를 기준으로 K개 잡든지
		dp[1][i] = S[i] - S[i - K] + max(dp[0][i - K], dp[1][i - K]);
		// i-1번째 잡은거에서 이어가든지
		dp[1][i] = max(dp[1][i], dp[1][i - 1] + S[i] - S[i - 1]);  //
	}

	cout << max(dp[0][N + K * 2], dp[1][N + K * 2]);
}