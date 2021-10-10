#include <iostream>

using namespace std;

#define MAX_N 1000001
#define MOD 15746

unsigned int memoization[MAX_N];

class BinaryTileClass {
public : 
	int recursiveFibonacci(int n) {
		if (n <= 2)
			return memoization[n];
		else if (memoization[n] != 0)
			return memoization[n];

		memoization[n] = (recursiveFibonacci(n - 1) + recursiveFibonacci(n - 2)) % MOD;
		return memoization[n];
	}

	void repeatFibonacci(int n) {
		for (int i = 3; i <= n; ++i) {
			memoization[i] = (memoization[i - 1] + memoization[i - 2])%MOD;
		}
	}

};

//int main() {
//	int n = 0;
//	BinaryTileClass btcObj;
//	memoization[0] = 0; memoization[1] = 1; memoization[2] = 2;
//
//	cin >> n;
//	btcObj.recursiveFibonacci(n);
//
//	cout << memoization[n];
//}