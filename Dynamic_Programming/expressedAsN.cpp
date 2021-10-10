#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

#define MAXN 8

class SolutionClass {
private :
	vector<unordered_set<int>> memo = vector<unordered_set<int>>(8);
public : 
	SolutionClass(int N) {
		memo[0].insert(N);
	}
	void initSet(int N) {
		int result = N;

		for (int i = 1; i < MAXN; ++i) {
			result = (result * 10) + N;
			memo[i].insert(result);
		}
	}
	int findNumber(int number) {
		for (int i = 1; i < MAXN; ++i) {
			for (int j = 0; j < i; ++j) {
				for (const auto& x : memo[j]) {
					for (const auto& y : memo[i - j - 1]) {
						memo[i].insert(x + y);
						memo[i].insert(x * y);
						if (x >= y) memo[i].insert(x - y);
						if (y != 0) memo[i].insert(x / y);
					}
				}
			}
			if (memo[i].find(number) != memo[i].end()) {
				return i + 1;
			}
		}
		return -1;
	}
};

//int main() {
//	int N, number, answer;
//	cin >> N >> number;
//	SolutionClass scObj(N);
//	scObj.initSet(N);
//
//	if (N == number)
//		return 1;
//
//	answer = scObj.findNumber(number);
//	cout << answer << endl;
//}