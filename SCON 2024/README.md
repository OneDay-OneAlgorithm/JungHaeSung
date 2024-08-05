# SCON 2024
https://www.acmicpc.net/category/detail/4206

## A
```cpp
#include <bits/stdc++.h>
using namespace std;
int N, M;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	int ans = 0, tot = 0;
	while (N--) {
		int a;
		cin >> a;
		tot = max(tot + a, 0);
		if (tot >= M) ++ans;
	}
	cout << ans;
}
```

## B
```cpp
#include <bits/stdc++.h>
using namespace std;
int N;

bool checkAlpha(const string& s) {
	int a = 0, b = 0, n = 0;
	for (char c : s) {
		if ('a' <= c && c <= 'z') ++a;
		if ('A' <= c && c <= 'Z') ++b;
		if ('0' <= c && c <= '9') ++n;
	}
	return n != s.length() && a >= b;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	while (N--) {
		string s;
		cin >> s;
		if (s.length() <= 10 && checkAlpha(s)) {
			cout << s;
			break;
		}
	}
}
```

## C
```cpp
#include <bits/stdc++.h>
using namespace std;
int N, A[22], B[22];
int aa = 0, bb = 0;

// A가 크면 1, B가 크면 -1, 같으면 0
int comp() {
	if (aa > bb) return 1;
	if (aa < bb) return -1;

	for (int i = 0; i < aa; i++) {
		if (A[i] > B[i]) return 1;
		if (A[i] < B[i]) return -1;
	}
	return 0;
}

void print(int arr[], int size) {
	for (int i = 0; i < size; i++) cout << arr[i];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int num;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> num;
		if (num >= 10) {
			A[aa] = num / 10;
			num %= 10;
			++aa;
		}
		A[aa] = num;
		++aa;
	}
	for (int i = 1; i <= N; i++) {
		cin >> num;
		if (num >= 10) {
			B[bb] = num / 10;
			num %= 10;
			++bb;
		}p
		B[bb] = num;
		++bb;
	}
	if (comp() == 1) {
		print(B, bb);
	} else {
		print(A, aa);
	}
}
```

## D
```cpp
#include <bits/stdc++.h>
using namespace std;
int T, N, S, E;

int solve() {
	cin >> N >> S >> E;
	if (min(S, E) == 1 && max(S, E) == N) return 0;
	if (S == 1 || S == N || abs(S - E) == 1) return 1;
	return 2;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) cout << solve() << '\n';
}
```

## E
```cpp
#include <bits/stdc++.h>
using namespace std;
int N;
char target, A[2020];

int solve(int n, char t) {
	if (n == 1) return A[1] == t ? 0 : 1;
	if (t == 'T') {
		if (A[n] == 'T' && A[n - 1] == '&') return min(1, solve(n - 2, 'T'));
		if (A[n] == 'T' && A[n - 1] == '|') return 0;
		if (A[n] == 'F' && A[n - 1] == '&') return min(2, 1 + solve(n - 2, 'T'));
		if (A[n] == 'F' && A[n - 1] == '|') return min(1, solve(n - 2, 'T'));
	} else if (t == 'F') {
		if (A[n] == 'T' && A[n - 1] == '&') return min(1, solve(n - 2, 'F'));
		if (A[n] == 'T' && A[n - 1] == '|') return min(2, 1 + solve(n - 2, 'F'));
		if (A[n] == 'F' && A[n - 1] == '&') return 0;
		if (A[n] == 'F' && A[n - 1] == '|') return min(1, solve(n - 2, 'F'));
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];
	cin >> target;
	cout << solve(N, target);
}
```
배열 길이 1010으로 했을 떄 런타임 에러 뜨는게 아니라 시간초과가 떴음.
그거 때문에 배열 길이 못보고 한참 헤맴.. 어이없네.. 왜 시간초과가 뜬거지

## F
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> A, B;

	while (N >= 3) {
		B.push_back(N);
		A.push_back(N - 1);
		A.push_back(N - 2);
		N -= 3;
	}
	if (N == 2) {
		A.push_back(1);
		B.push_back(2);
	}
	cout << A.size() << '\n';
	for (int a : A) cout << a << ' ';
	cout << '\n';
	cout << B.size() << '\n';
	for (int b : B) cout << b << ' ';
	cout << '\n';
}
```

## G

## H
```cpp
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
```

## I
<!-- <details>
<summary>c++</summary>

```cpp
```
</details> -->

## J
```cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int N, M;
vector<pair<int, ll>> G[303030];
bool vis[303030];

// x으로 1->N에 도달할 수 있는지 여부
bool dfs(int v, ll x) {
	if (v == N) return true;
	if (vis[v]) return false;
	vis[v] = true;
	for (auto [u, w] : G[v])
		if ((w & x) == w && dfs(u, x)) return true;
	return false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for (ll i = 1, u, v, w; i <= M; i++) {
		cin >> u >> v >> w;
		G[u].emplace_back(v, w);
		G[v].emplace_back(u, w);
	}

	ll ans = (1L << 60) - 1;
	for (int i = 59; i >= 0; i--) {
		memset(vis, 0, sizeof vis);
		ans -= 1L << i;
		if (!dfs(1, ans)) ans += 1L << i;
	}
	cout << ans;
}
```