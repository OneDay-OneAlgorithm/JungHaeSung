#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> A, B;

	while (N >= 3) {
		B.push_back(N);
		A.push_back(N - 1);
		A.push_back(N - 2);
		N -= 3;
	}
	if (N == 2) {
		A.push_back(1);
		B.push_back(2);
	}
	cout << A.size() << '\n';
	for (int a : A) cout << a << ' ';
	cout << '\n';
	cout << B.size() << '\n';
	for (int b : B) cout << b << ' ';
	cout << '\n';
}