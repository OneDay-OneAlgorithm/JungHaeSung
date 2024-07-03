# SCON 2024
https://www.acmicpc.net/contest/view/1263

## A

<details>
<summary>c++</summary>

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
</details>

## B
<details>
<summary>c++</summary>

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
</details>

## C
<details>
<summary>c++</summary>

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
</details>

## D
<details>
<summary>c++</summary>

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
</details>

## E
<details>
<summary>c++</summary>

```cpp
```
</details>

## F
<details>
<summary>c++</summary>

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
</details>

## G
<details>
<summary>c++</summary>

```cpp
```
</details>

## H
<details>
<summary>c++</summary>

```cpp
```
</details>

## I
<details>
<summary>c++</summary>

```cpp
```
</details>

## J
<details>
<summary>c++</summary>

```cpp
```
</details>