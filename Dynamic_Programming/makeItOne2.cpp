#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

#define MAX 1000000

int main() {
	int N = 0;
	cin >> N;
	vector<unordered_set<int>> memo = vector<unordered_set<int>>(N);

	if (N == 1) {
		cout << 0;
		return 0;
	}
	else if (N <= 3) {
		cout << 1;
		return 0;
	}

	if (N % 3 == 0) {
		memo[0].insert(N / 3);
	}
	if (N % 2 == 0) {
		memo[0].insert(N / 2);
	}
	memo[0].insert(N - 1);


	for (int i = 1; i <= MAX; ++i) {
		for (const auto& prev : memo[i - 1]) { // 5, 9
			if (prev % 3 == 0) {
				memo[i].insert(prev / 3);
			}
			if (prev % 2 == 0) {
				memo[i].insert(prev / 2);
			}
			memo[i].insert(prev - 1);
		}
		if (memo[i].find(1) != memo[i].end()) {
			cout << i;
			return 0;
		}
	}
	return 0;
}