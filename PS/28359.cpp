#include <bits/stdc++.h>
using namespace std;
int A[1010], M[1010], N, sum;

int main() {
	cin.tie(0), ios_base::sync_with_stdio(0);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i], sum += A[i], M[A[i]] += A[i];
	int mx = 0, f = 0;
	for (int i = 1; i <= N; i++) {
		if (mx < M[i]) {
			mx = M[i];
			f = i;
		}
	}
	sort(A, A + N);
	cout << sum + mx;
	cout << '\n';
	for (int i = 0; i < N; i++) cout << A[i] << ' ';
}