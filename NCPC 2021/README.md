# NCPC 2021
https://www.acmicpc.net/category/detail/2816

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