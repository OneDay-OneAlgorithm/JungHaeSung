/**
 * 궁금증
 *
 * P_n := n자리 소수 중 최대
 * C_n := P_n의 상위 연속된 9의 개수 (ex: P4 = 9973, C4 = 2)
 * 라 할 때
 *
 * 1. 수열 {C_n}는 증가하는가?
 * 2. 수열 {C_n / n}의 형태는 어떠한가?
 *
 * -> 모르겠다
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool isPrime(ll n) {
	if (n <= 1) return false;
	if (n == 2) return true;
	for (int i = 2; i * i <= n; i++)
		if (n % i == 0) return false;
	return true;
}

int nine(ll n) {
	string s = to_string(n);
	int cnt = 0, i = 0;
	while (i < s.length() && s[i++] == '9') cnt++;
	return cnt;
}

int main() {
	for (ll digit = 9, i = 1e9; i > 1; i /= 10, digit--) {
		ll n = i;
		while (!isPrime(--n))
			;
		cout << nine(n) << "/" << digit << " (" << n << ")\n";
	}
}