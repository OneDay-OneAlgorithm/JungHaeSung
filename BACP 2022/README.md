# BAPC 2022
https://www.acmicpc.net/category/detail/3222

## B
```cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	const double PI = 3.14159265358979323846;
	int num = 0, left_end = 0, right_end = 0;
	double tan = 0;
	cin >> num;

	vector<pair<int, int>> points(num);
	for (auto& [x, y] : points) cin >> x >> y;
	left_end = points[0].first;
	right_end = points.back().first;

	for (auto [x, y] : points) {
		tan = max(tan, (double)y / (x - left_end));
		tan = max(tan, (double)y / (right_end - x));
	}

	cout << fixed << setprecision(6) << atan(tan) * 180 / PI;
}
```
최대가 되려면 무조건 해안선을 포함해야 한다는 관찰을 하는 게 어려웠던 문제.

## E
```cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll N, x, A[101010], sum = 0;
	cin >> N >> x;
	for (int i = 1; i <= N; i++) cin >> A[i], sum += A[i] * A[i];
	double t = sum == 0 ? 0 : sqrt((double)x * N / sum);
	for (int i = 1; i <= N; i++) printf("%.9lf ", A[i] * t);
}
```

## F
```cpp
#include <bits/stdc++.h>
using namespace std;
map<char, int> m = {{'N', 0}, {'E', 90}, {'S', 180}, {'W', 270}};

double parse(string dir) {
	double angle = m[dir[0]], d = 45;
	if (dir.length() == 1) return angle;

	string sub = dir.substr(0, 2);
	for (int i = 1; i < dir.length(); i++) {
		if (sub == "EN") {
			if (dir[i] == 'N')
				angle -= d;
			else
				angle += d;
		} else if (sub == "ES") {
			if (dir[i] == 'S')
				angle += d;
			else
				angle -= d;
		} else if (sub == "WN") {
			if (dir[i] == 'N')
				angle += d;
			else
				angle -= d;
		} else if (sub == "WS") {
			if (dir[i] == 'S')
				angle -= d;
			else
				angle += d;
		}
		d /= 2;
	}
	return angle;
}

int main() {
	string X, Y;
	cin >> X >> Y;
	reverse(X.begin(), X.end());
	reverse(Y.begin(), Y.end());
	double x = parse(X), y = parse(Y);
	if (x > y) swap(x, y);
	cout << fixed << setprecision(9) << min(y - x, 360 - (y - x));
}
```

## I
```cpp
#include <bits/stdc++.h>
using namespace std;
int N, Q;
map<string, vector<pair<string, double>>> G;
map<string, bool> vis;

// if impassible, return -1
double dfs(string& v, string& to_unit, double co = 1) {
	if (v == to_unit) return co;
	if (vis[v]) return -1;
	vis[v] = true;

	for (auto& [to, t] : G[v]) {
		double ret = dfs(to, to_unit, co * t);
		if (ret > 0) return ret;
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string from, to, tmp;
	double f, t;
	cin >> N >> Q;

	while (N--) {
		cin >> tmp >> from >> tmp >> t >> to;
		G[from].emplace_back(to, t);
		G[to].emplace_back(from, 1 / t);
	}

	while (Q--) {
		vis.clear();
		cin >> f >> from >> tmp >> to;
		double co = dfs(from, to);
		if (co < 0) {
			cout << "impossible\n";
			continue;
		}
		cout.precision(16);
		cout << co * f << '\n';
	}
}
```

## K
```cpp
#include <bits/stdc++.h>
using namespace std;
const int di[] = {1, -1, 0, 0}, dj[] = {0, 0, 1, -1};
pair<int, int> loc[2020];
int H, W, A[44][44], dp[2020][2020];  // dp[i][j]: i~j로 가는 경로의 길이
bool vis[2020][2020];

int dfs(int v, int target) {
	int& ret = dp[target][v];
	if (ret < H * W) return ret;
	if (v == target) return ret = 0;
	if (vis[target][v]) return ret;
	vis[target][v] = true;

	auto [i, j] = loc[v];
	vector<tuple<int, int, int>> V;
	for (int t = 0; t < 4; t++) {
		int ii = i + di[t], jj = j + dj[t];
		if (1 <= ii && ii <= H && 1 <= jj && jj <= W) {
			V.emplace_back(abs(A[ii][jj] - target), ii, jj);
		}
	}
	sort(V.begin(), V.end());
	auto [diff0, i0, j0] = V[0];
	auto [diff1, i1, j1] = V[1];
	if (diff0 == diff1 && abs(A[i][j] - A[i0][j0]) > abs(A[i][j] - A[i1][j1])) {
		i0 = i1, j0 = j1;
	}
	return ret = dfs(A[i0][j0], target) + 1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	memset(dp, 0x3f, sizeof dp);
	cin >> H >> W;
	for (int i = 1; i <= H; i++)
		for (int j = 1; j <= W; j++) {
			cin >> A[i][j];
			loc[A[i][j]] = make_pair(i, j);
		}

	// for (int i = 1; i <= H * W; i++) {
	// 	for (int j = 1; j <= H * W; j++) cout << dfs(i, j) << ' ';
	// 	cout << '\n';
	// }

	int min_dist = 0x3f3f3f3f, ans = -1;
	for (int i = 1; i <= H * W; i++) {
		int dist = 0;
		memset(vis, 0, sizeof vis);
		for (int j = 1; j <= H * W; j++) dist = max(dist, dfs(i, j));
		if (min_dist > dist) {
			min_dist = dist;
			ans = i;
		}
	}
	if (ans == -1)
		cout << "impossible";
	else
		cout << ans << ' ' << min_dist;
}
```
백준에서는 풀리는데 코드포스에서는 시간초과뜸

시간복잡도를 더 줄일 수 있는지 고민해봐야 할 것 같음.