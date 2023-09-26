#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll C[250505], N;

// DP[i][0] : 1~i까지 중에서 i번째를 선택하지 않았을 때의 최대
// DP[i][1] : i번째를 선택했을 때의 최대
ll DP[250505][2];

int main() {
	cin.tie(0), ios_base::sync_with_stdio(0);
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> C[i];
	for (int i = 1; i <= N; i++) {
		if (i == N) {
			// 1번째에 쪽방이 있으면 무조건 쪽방을 선택한다고 가정
			// => C[1] != 0이면 DP[1][0]으로 해도 됨
			if (C[1] != 0) DP[i][1] = DP[i - 1][0] + 1;
			DP[i][0] = max(DP[i - 1][0], DP[i - 1][1]) + C[i];
			continue;
		}
		DP[i][0] = max(DP[i - 1][0], DP[i - 1][1]) + C[i];	// 쪽방이 없으면 C[i] == 0이라 상관 없음
		DP[i][1] = DP[i - 1][0] + 1;
	}
	cout << max(DP[N][0], DP[N][1]);
}