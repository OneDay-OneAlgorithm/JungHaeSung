# Sub-Regional Brasil do ACM ICPC
https://www.acmicpc.net/category/detail/3902

## A
<details>
<summary>c++</summary>

```cpp
#include <bits/stdc++.h>
using namespace std;
int N, H;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> H;
	int ans = 0, a;
	while (N--) {
		cin >> a;
		if (a <= H) ++ans;
	}
	cout << ans;
}
```
</details>

## C
<details>
<summary>c++</summary>

```cpp
#include <bits/stdc++.h>
using namespace std;
int N, A[101010], ans[101010], len[101010];
vector<int> G[101010];
vector<int> V;

void dfs(int k) {
	if (ans[k]) return;
	ans[k] = true;
	V.push_back(k);

	// LIS
	int a = 0;
	len[k] = 1;
	for (int t : V) {
		a = max(a, len[t]);
		if (A[t] < A[k]) len[k] = max(len[k], len[t] + 1);
	}
	ans[k] = max(len[k], a);

	for (int nn : G[k]) {
		dfs(nn);
	}
	V.pop_back();
}

int main() {
    ... 아래랑 같음
}
```
$n^2$ LIS로 하면 시간초과

```cpp
#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
int N, A[101010], ans[101010];
vector<int> G[101010];
vector<int> vt = {-inf};

void dfs(int k) {
	if (ans[k]) return;

	// LIS
	int before = -1, i = -1;
	if (vt.back() < A[k]) {
		vt.push_back(A[k]);
	} else {
		i = lower_bound(vt.begin(), vt.end(), A[k]) - vt.begin();
		if (vt.size() == i) {
			vt.push_back(A[k]);
		} else {
			before = vt[i];
			vt[i] = A[k];
		}
	}
	ans[k] = vt.size() - 1;

	for (int nn : G[k]) {
		dfs(nn);
	}

	// 복원
	if (before == -1)
		vt.pop_back();
	else
		vt[i] = before;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 2; i <= N; i++) {
		int u;
		cin >> u;
		G[i].push_back(u);
		G[u].push_back(i);
	}
	for (int i = 1; i <= N; i++) cin >> A[i];

	dfs(1);
	for (int i = 2; i <= N; i++) cout << ans[i] << ' ';
}
```
$n \log n$ LIS가 아직 좀 낯설음
</details>

## F
<details>
<summary>c++</summary>

```cpp
#include <bits/stdc++.h>
using namespace std;
int D, C, R;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int tmp;
	cin >> D >> C >> R;
	queue<int> cc, rr;
	for (int i = 1; i <= C; i++) {
		cin >> tmp;
		cc.push(tmp);
	}
	for (int i = 1; i <= R; i++) {
		cin >> tmp;
		rr.push(tmp);
	}

	int ans = 0;
	bool flag = true;
	while (flag && (!cc.empty() || !rr.empty())) {
		while (!cc.empty()) {
			int c = cc.front();
			if (c > D) {
				flag = !rr.empty();
				break;
			}
			D -= c;
			cc.pop();
			++ans;
		}
		while (!rr.empty()) {
			D += rr.front();
			rr.pop();
			++ans;
		}
	}
	cout << ans;
}
```
</details>

<!-- ## I
<details>
<summary>c++</summary>

```cpp
```
</details> -->

## L
<details>
<summary>c++</summary>

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string S;
	int K, len;
	cin >> S >> K;
	len = S.length();

	vector<vector<char>> V;

	for (int i = 0; i < K; i++) {
		vector<char> tmp;
		for (int j = i; j < len; j += K) {
			tmp.push_back(S[j]);
		}
		V.push_back(tmp);
	}
	for (auto& v : V) {
		if (v.size() != 1) sort(v.begin(), v.end());
	}

	for (int i = 0; i < len / K + 1; i++) {
		for (auto& v : V) {
			if (v.size() > i) cout << v[i];
		}
	}
}
```

출력할 때 `auto&` 대신에 `auto`썼더니 시간초과.

백준은 제한 시간이 0.5초라 상관 없음 (원래 문제는 제한시간 0.3초)

`&` 안 붙이면 400ms 정도 나오는데 붙이면 8ms 나옴. 생각보다 차이 엄청 크다

이 문제가 브론즈1 밖에 안 된다고?
</details>

## M
<details>
<summary>c++</summary>

```cpp
#include <bits/stdc++.h>
using namespace std;
int N, D[101][101];
bool del[101][101];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) cin >> D[i][j];
	}

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (D[i][j] > D[i][k] + D[k][j]) {
					cout << -1;
					return 0;
				}
				if (i != k && j != k)
					if (D[i][j] == D[i][k] + D[k][j]) del[i][j] = true;
			}
		}
	}

	int ans = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = i + 1; j <= N; j++)
			if (del[i][j]) ++ans;
	}
	cout << ans;
}
```
플로이드 와샬 조금 응용
</details>