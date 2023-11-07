#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9;
int N, A[101][10];

int main() {
	cin >> N;
	for (int i = 0; i <= 9; i++) A[1][i] = 1;
	for (int i = 2; i <= N; i++) {
		for (int j = 1; j <= 8; j++) A[i][j] = (A[i - 1][j - 1] + A[i - 1][j + 1]) % mod;
		A[i][0] = A[i - 1][1];
		A[i][9] = A[i - 1][8];
	}
	int sum = 0;
	for (int i = 1; i <= 9; i++) sum = (sum + A[N][i]) % mod;
	cout << sum;
}