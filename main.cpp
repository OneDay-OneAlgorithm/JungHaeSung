#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int N, M, U[101010];
ll tot = 0;
vector<tuple<int, int, int>> E;	 // <w, u, v>

void Init() {
	for (int i = 1; i <= N; i++) U[i] = i;
}

int Find(int v) { return U[v] = U[v] == v ? v : Find(U[v]); }

bool Merge(int u, int v) {
	int p = Find(u), q = Find(v);
	if (p == q) return false;
	U[p] = q;
	return true;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	Init();
	E.resize(M);

	for (auto& [w, u, v] : E) cin >> u >> v >> w, tot += w;
	sort(E.begin(), E.end());

	for (auto [w, u, v] : E) {
		if (Merge(u, v)) tot -= w;
	}

	for (int i = 2; i <= N; i++)
		if (Find(1) != Find(i)) {
			cout << -1;
			return 0;
		}
	cout << tot;
}