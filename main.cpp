#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	// S[i]: 수열의 1~i번째까지 1의 개수가 짝수면 0, 홀수면 1
	// C[0]: 1~i까지의 누적합이 짝수인 i의 개수, C[1] : 홀수
	ll N, ans = 0, S[101010], C[2] = {1, 0};
	cin >> N;
	for (int t, i = 1; i <= N; i++) cin >> t, S[i] = t ^ S[i - 1];

	for (int i = 1; i <= N; i++) {
		if (S[i] == 1) {
			// 현재까지가 홀수개면 누적합이 짝수개인 수열의 개수를 더해줌
			// 홀수 - 짝수 = 홀수니까
			ans += C[0];
			++C[1];	 // 개수 추가
		} else {
			// 반대인 경우
			ans += C[1];
			++C[0];
		}
	}
	cout << ans;
}