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
$n^2$ LIS : 시간초과

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
$n \log n$ LIS 풀이
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

## I
<details>
<summary>c++</summary>

```cpp
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
```
단순 dp : 시간초과

```cpp
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
```
누적합(prefix xor) 사용

풀이 설명:
- 위처럼 S 배열을 계산해주면 1부터 i번째까지 1의 개수가 짝수인지 홀수인지 알 수 있음
- 이 S 배열을 활용하면 [l, r]에서 1의 개수가 짝수인지 홀수인지도 알 수 있음
  - 짝수 - 짝수 = 짝수
  - 짝수 - 홀수 = 홀수
  - 홀수 - 짝수 = 홀수
  - 홀수 - 홀수 = 짝수 => 이 성질 이용하면 됨
  - 근데 이게 xor이랑 똑같음 (짝수 = 0, 홀수 = 1이라고 생각)
  - 그러니까 S[l-1] xor S[r]만 계산하면 알 수 있다
- 모든 r마다 S[l-1] xor S[r] = 1인 l의 개수를 구하면 되긴 함 => 이렇게만 하면 n^2이라서 시간초과
- 그래서 그 개수를 C 배열에 저장해둬서 시간복잡도를 줄일 수 있다
  - 이건 조금만 생각해보면 알 수 있긴 한데 설명하자면
  - S[r] = 1이면 그 앞에서 S[l-1] = 0인 l의 개수가 궁금한거고 이걸 C[0]에 저장
  - 반대도 마찬가지
</details>

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