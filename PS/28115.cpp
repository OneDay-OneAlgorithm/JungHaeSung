#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int A[1010101], N;

bool valid() {
	if (N == 1) return true;
	ll d = A[2] - A[1];
	for (int i = 3; i <= N; i++)
		if (A[i] != A[i - 1] + d) return false;
	return true;
}

int main() {
	cin.tie(0), ios_base::sync_with_stdio(0);
	cin >> N;

	for (int i = 1; i <= N; i++) cin >> A[i];
	if (!valid()) {
		cout << "NO";
		return 0;
	}
	cout << "YES\n";
	for (int i = 1; i <= N; i++) cout << A[i] << ' ';
	cout << '\n';
	for (int i = 1; i <= N; i++) cout << "0 ";
}