#include <bits/stdc++.h>
using namespace std;
int N;
vector<pair<int, int>> v;

int main() {
	cin.tie(0), ios_base::sync_with_stdio(0);
	cin >> N;
	while (N--) {
		int a, b;
		cin >> a >> b;
		v.emplace_back(a, b);
	}
	sort(v.begin(), v.end(), [](auto a, auto b) {
		if (a.first == b.first) return a.second < b.second;
		return a.first < b.first;
	});
	for (auto i : v) cout << i.first << ' ' << i.second << '\n';
}