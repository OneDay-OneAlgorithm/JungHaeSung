#include <bits/stdc++.h>
using namespace std;

double f(double d) { return floor(d + 0.5); }

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N, sum = 0;
	cin >> N;
	vector<int> v(N);
	for (int& n : v) cin >> n, sum += n;
	sort(v.begin(), v.end());

	int ig = f(N * 0.15);
	for (int i = 0; i < ig; i++) sum -= v[i];
	for (int i = N - 1; i >= N - ig; i--) sum -= v[i];
	cout << f((double)sum / (N - 2 * ig));
}