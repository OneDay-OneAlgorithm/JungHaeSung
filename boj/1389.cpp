#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N, M, D[101][101];
	memset(D, 0x3f, sizeof D);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) D[i][i] = 0;
	for (int i = 1, a, b; i <= M; i++) {
		cin >> a >> b;
		D[a][b] = D[b][a] = 1;
	}
	for (int k = 1; k <= N; k++)
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++) D[i][j] = min(D[i][j], D[i][k] + D[k][j]);

	int m = 0x3f3f3f3f, ans = -1;
	for (int i = 1; i <= N; i++) {
		int tot = 0;
		for (int j = 1; j <= N; j++) tot += D[i][j];
		if (tot < m) {
			ans = i;
			m = tot;
		}
	}
	cout << ans;
}