#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll ans = (ll)1 << 60;
int N, M;
vector<pair<ll, int>> G[303030];  // <u, weight, v>
bool vis[303030];

ll dist = 0;
void dfs(int v) {
	if (v == N) {
		ans = min(ans, dist);
		return;
	}
	if (vis[v]) return;
	vis[v] = true;

	for (auto [w, u] : G[v]) {
		if (w >= ans) continue;
		ll tmp = dist;
		dist |= w;
		dfs(u);
		dist = tmp;
	}
	vis[v] = false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for (ll i = 1, u, v, w; i <= M; i++) {
		cin >> u >> v >> w;
		G[u].emplace_back(w, v);
		G[v].emplace_back(w, u);
	}
	for (int i = 1; i <= N; i++) sort(G[i].begin(), G[i].end());
	dfs(1);
	cout << ans;
}