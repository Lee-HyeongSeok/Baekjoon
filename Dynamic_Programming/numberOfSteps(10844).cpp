#include <iostream>

using namespace std;

#define MAXN 101
#define MOD 1000000000

long long stepsMemo[MAXN][11];

class StepsClass {
private : 
	int N;
	long long result;
public : 
	StepsClass(int N) : N(N), result(0){}

	void findingNumberOfSteps() {
		stepsMemo[1][0] = 0;
		for (int i = 1; i <= 9; ++i) {
			stepsMemo[1][i] = 1;
		}

		for (int i = 2; i <= N; ++i) {
			for (int j = 0; j <= 9; ++j) {
				if (j == 0) {
					stepsMemo[i][j] = stepsMemo[i - 1][j + 1] % MOD;
				}
				else if (j == 9) {
					stepsMemo[i][j] = stepsMemo[i - 1][j - 1] % MOD;
				}
				else {
					stepsMemo[i][j] = (stepsMemo[i - 1][j - 1] + stepsMemo[i - 1][j + 1]) % MOD;
				}
			}
		}

		for (int i = 0; i < 10; ++i) {
			result += stepsMemo[N][i];
		}
		cout << result % MOD;
	}
};

//int main() {
//	int N = 0;
//	cin >> N;
//	StepsClass scObj(N);
//	scObj.findingNumberOfSteps();
//}