#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll C[250505], N, sum = 0;
vector<int> idx;

int main() {
	cin.tie(0), ios_base::sync_with_stdio(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> C[i];
		sum += C[i];
		if (C[i] != 0) idx.push_back(i);
	}
	if (idx.size() <= 1)
		cout << sum + N / 2;
	else {
		for (int i = 0; i < idx.size() - 1; i++) {
			sum += (idx[i + 1] - idx[i]) / 2;
		}
		sum += (N - idx.back() + idx[0]) / 2;
		cout << sum;
	}
}