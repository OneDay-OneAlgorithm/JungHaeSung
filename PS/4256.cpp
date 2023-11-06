#include <bits/stdc++.h>
using namespace std;
int n, P[1010], I[1010];  // preorder, inorder
int p = 1;				  // preorder 읽기 순서

void Tree(int s, int e) {
	if (s > e) return;
	int root = P[p++];
	int idx = find(begin(I), end(I), root) - begin(I);
	Tree(s, idx - 1);
	Tree(idx + 1, e);
	cout << root << ' ';
}

void solve() {
	memset(P, 0, sizeof(P));
	memset(I, 0, sizeof(I));
	p = 1;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> P[i];
	for (int i = 1; i <= n; i++) cin >> I[i];

	Tree(1, n);
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int T;
	cin >> T;
	while (T--) solve();
}