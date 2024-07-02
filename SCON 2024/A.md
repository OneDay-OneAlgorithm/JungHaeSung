https://www.acmicpc.net/problem/31831
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
