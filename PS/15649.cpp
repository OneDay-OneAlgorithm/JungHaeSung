#include <bits/stdc++.h>
using namespace std;
int n, m, A[10], B[10];

void f(int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++) cout << A[i] << ' ';
		cout << '\n';
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!B[i]) {
			A[cnt] = i;
			B[i] = 1;
			f(cnt + 1);
			B[i] = 0;
		}
	}
}

int main() {
	cin >> n >> m;
	f(0);
}