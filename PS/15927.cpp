#include <bits/stdc++.h>
using namespace std;

bool isPalin(string& s) {
	int len = s.length();
	for (int i = 0; i < len / 2; i++)
		if (s[i] != s[len - i - 1]) return false;
	return true;
}

bool allSame(string& s) {
	int len = s.length();
	for (int i = 1; i < len; i++)
		if (s[i] != s[0]) return false;
	return true;
}

int main() {
	string s;
	cin >> s;
	if (allSame(s))
		cout << -1;
	else if (isPalin(s))
		cout << s.length() - 1;
	else
		cout << s.length();
}