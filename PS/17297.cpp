#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll L[101010], M;

char messi(int n, ll x) {
	if (x <= 13) return "Messi Gimossi"[x - 1];
	if (x <= L[n - 1]) return messi(n - 1, x);
	if (x == L[n - 1] + 1) return ' ';
	return messi(n - 2, x - L[n - 1] - 1);
}

int main() {
	L[1] = 5;
	L[2] = 13;
	cin >> M;

	int i = 2;
	while (M > L[i++]) {
		L[i] = L[i - 1] + L[i - 2] + 1;
	}
	char ans = messi(i - 1, M);
	if (ans == ' ')
		cout << "Messi Messi Gimossi";
	else
		cout << ans;
}