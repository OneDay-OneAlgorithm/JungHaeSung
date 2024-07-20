#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll inf = 1L << 60;
int N, M;
ll dist[303030];
vector<pair<int, ll>> G[303030];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for (ll i = 1, u, v, w; i <= M; i++) {
		cin >> u >> v >> w;
		G[u].emplace_back(v, w);
		G[v].emplace_back(u, w);
	}
	fill(dist, dist + N + 1, inf);

	priority_queue<pair<ll, int>> pq;  // <dist, node>
	dist[1] = 0;
	pq.emplace(0, 1);

	while (!pq.empty()) {
		auto [d, node] = pq.top();
		pq.pop();
		d = -d;

		if (d > dist[node]) continue;

		for (auto [next, w] : G[node]) {
			if ((d | w) < dist[next]) {
				dist[next] = d | w;
				pq.emplace(-dist[next], next);
			}
		}
	}
	cout << dist[N];
}