#include <bits/stdc++.h>
using namespace std;
int usedNum[20], slot[30], n, cnt;

void f(int choose, int cur) {
	if (choose == n) {
		cnt++;
		return;
	}
	if (slot[cur]) {
		f(choose, cur + 1);
		return;
	}
	for (int c = 1; c <= n; c++) {
		int j = cur + c + 1;
		if (!usedNum[c] && j <= 2 * n && !slot[j]) {
			slot[cur] = slot[j] = usedNum[c] = c;
			f(choose + 1, cur + 1);
			slot[cur] = slot[j] = usedNum[c] = 0;
		}
	}
}

int main() {
	int x, y;
	cin >> n >> x >> y;
	int num = y - x - 1;
	slot[x] = slot[y] = usedNum[num] = num;
	f(1, 1);
	cout << cnt;
}