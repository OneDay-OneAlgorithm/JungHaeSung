#include <bits/stdc++.h>
using namespace std;
int N, K;

int main() {
	cin >> N >> K;
	if (K > N - 1) {
		cout << "Impossible";
		return 0;
	}
	cout << N - K << ' ';
	for (int i = 1; i <= N - K - 1; i++) cout << i << ' ';
	for (int i = N - K + 1; i <= N; i++) cout << i << ' ';
}