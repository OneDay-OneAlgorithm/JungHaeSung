#include <bits/stdc++.h>
using namespace std;
int A[2020202], N;
const int offset = 1'000'000;

int main() {
	cin.tie(0), ios_base::sync_with_stdio(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int n;
		cin >> n;
		A[n + offset] = 1;
	}
	for (int i = 0; i <= 2 * offset; i++)
		if (A[i]) cout << i - offset << '\n';
}