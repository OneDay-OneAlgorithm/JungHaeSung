# NCPC 2021
https://www.acmicpc.net/category/detail/2816

## D
```cpp
#include <bits/stdc++.h>
using namespace std;
const int di[] = {-1, 0, 1, 0}, dj[] = {0, -1, 0, 1};
int W, H, dist[1010][1010];	 // dist[i][j] : S부터 (i, j)까지 최단 경로의 길이
bool vis[1010][1010];
char M[1010][1010];

int dir(char d) {
	switch (d) {
		case 'N':
			return 0;
		case 'W':
			return 1;
		case 'S':
			return 2;
		case 'E':
			return 3;
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	memset(dist, -1, sizeof(dist));
	int start_i, start_j;
	cin >> W >> H;
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) {
			cin >> M[i][j];
			if (M[i][j] == 'S') {
				start_i = i;
				start_j = j;
			}
		}
	}
	string I;
	cin >> I;

	queue<tuple<int, int, int>> q;

	// dist 배열을 먼저 계산해줌
	memset(vis, 0, sizeof(vis));
	q.emplace(start_i, start_j, 0);
	vis[start_i][start_j] = true;
	while (!q.empty()) {
		auto [i, j, n] = q.front();
		q.pop();
		dist[i][j] = n;
		for (int t = 0; t < 4; t++) {
			int ii = i + di[t], jj = j + dj[t];
			if (M[ii][jj] != '#' && !vis[ii][jj]) {
				vis[ii][jj] = true;
				q.emplace(ii, jj, n + 1);
			}
		}
	}

	// I 문자열을 보고 따라감
	memset(vis, 0, sizeof(vis));
	q.emplace(start_i, start_j, 0);
	vis[start_i][start_j] = true;
	while (!q.empty()) {
		auto [i, j, n] = q.front();
		q.pop();

		if (n == I.size() && n == dist[i][j]) {
			// 최단 경로의 길이와도 같아야 함
			M[i][j] = '!';
			continue;
		}
		int d = dir(I[n]);
		for (int t = 0; t < 4; t++) {
			if (d == t) continue;
			int ii = i + di[t], jj = j + dj[t];
			if (M[ii][jj] != '#' && !vis[ii][jj]) {
				vis[ii][jj] = true;
				q.emplace(ii, jj, n + 1);
			}
		}
	}
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) cout << M[i][j];
		cout << '\n';
	}
}
```
- bfs 두 번 돌리면 풀 수 있는 문젠데 dist 배열을 생각을 못해서 연습 때 못 푼 문제.
- dist 배열이 필요한 이유는
  - S부터 보물까지의 거리가 항상 최소여야 하기 때문인데
  - 그렇지 않으면 조금 돌아가는 경로로 갔을 때의 위치도 보물의 위치라고 보기 때문에 답이 될 수 없음
  - 좀만 생각하면 알 수 있는 거긴 한데 반례 찾기가 빡세네

반례:
```
7 5
#######
#.....#
#..S..#
#.....#
#######
ENN
```

정답:
```
#######
#!...!#
#..S..#
#!...!#
#######
```

오답(dist 배열 없을 때):
```
#######
#!...!#
#..S!.#
#!...!#
#######
```
-> 경로의 길이는 3인데, S 오른쪽에도 '!'가 찍혀있는 것을 볼 수 있음.
만약 해당 '!'에 보물이 존재했다면 경로의 길이는 1이었을 것


## G
```cpp
#include <bits/stdc++.h>
using namespace std;
int A[101][101];

int dist(int x1, int y1, int x2, int y2) { return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2); }

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	while (N--) {
		int x, y, r;
		cin >> x >> y >> r;
		x += 10;
		y += 10;
		for (int i = y - r; i < y + r; i++) {
			for (int j = x - r; j < x + r; j++)
				if (dist(x, y, j, i) <= r * r) A[i][j] = 1;
		}
	}

	int sum = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) sum += A[i][j];
	}
	cout << sum;
}
```

## J
```cpp
#include <bits/stdc++.h>
using namespace std;
typedef struct {
	int x, y;
} Point;

double dist(Point& a, Point& b) {
	return sqrt((double)(a.x - b.x) * (a.x - b.x) + (double)(a.y - b.y) * (a.y - b.y));
}

int main() {
	Point A, B, C, D;
	cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y >> D.x >> D.y;
	printf("%.9lf", max(dist(A, B), dist(C, D)));
}
```

## K
```cpp
#include <bits/stdc++.h>
using namespace std;
bool v[1010];
int N, A[55];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];
	for (int i = 1, t; i <= N-1; i++) cin >> t, v[t] = true;
	for (int i = 1; i <= N; i++) 
		if (!v[A[i]]) cout << A[i];
}
```

## L
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int ans = 1e9, N;
	cin >> N;
	while (N--) {
		int y, c1, c2;
		cin >> y >> c1 >> c2;
		ans = min(ans, y + c1 * c2 / __gcd(c1, c2));
	}
	cout << ans;
}
```