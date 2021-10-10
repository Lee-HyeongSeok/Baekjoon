#include <iostream>

using namespace std;

#define MAX_N 41

// 메모이제이션 공간
int memo[MAX_N];

class FibonacciClass {
private : 
	int one;
	int zero;
public : 
	FibonacciClass() : one(0), zero(0){ }

	void initMemo() {
		for (int i = 0; i < MAX_N; ++i)
			memo[i] = 0;
		one = zero = 0;
	}

	int fibonacci(unsigned int n) {
		if (n <= 1){
			if (n) {
				memo[n] = 1;
				++one;
			}
			else {
				memo[n] = 0;
				++zero;
			}
			return n;
		}
		if (memo[n] != 0){ // 메모리가 있는지 확인
			return memo[n]; // 메모리 리턴, 재귀 함수 호출 횟수 차감
		}
		// 작은 문제로 분할
		memo[n] = fibonacci(n - 1) + fibonacci(n - 2);
		return memo[n]; // 계산된 재귀함수 결과 리턴
	}

	void printResult() {
		cout << zero << ' ' << one << endl;
	}
};

//int main() {
//	int n = 0;
//	int testCase = 0;
//	FibonacciClass fcObj;
//
//	cin >> testCase;
//
//	while (testCase--) {
//		cin >> n;
//		fcObj.initMemo();
//		fcObj.fibonacci(n);
//		if (n == 0 || n == 1)
//			fcObj.printResult();
//		else {
//			cout << memo[n - 1] << " " << memo[n] << endl;
//		}
//	}
//	return 0;
//}