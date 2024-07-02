```cpp
#include <bits/stdc++.h>
using namespace std;
int N, A[22], B[22];
int aa = 0, bb = 0;

// A가 크면 1, B가 크면 -1, 같으면 0
int comp() {
	if (aa > bb) return 1;
	if (aa < bb) return -1;

	for (int i = 0; i < aa; i++) {
		if (A[i] > B[i]) return 1;
		if (A[i] < B[i]) return -1;
	}
	return 0;
}

void print(int arr[], int size) {
	for (int i = 0; i < size; i++) cout << arr[i];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int num;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> num;
		if (num >= 10) {
			A[aa] = num / 10;
			num %= 10;
			++aa;
		}
		A[aa] = num;
		++aa;
	}
	for (int i = 1; i <= N; i++) {
		cin >> num;
		if (num >= 10) {
			B[bb] = num / 10;
			num %= 10;
			++bb;
		}
		B[bb] = num;
		++bb;
	}
	if (comp() == 1) {
		print(B, bb);
	} else {
		print(A, aa);
	}
}
```
