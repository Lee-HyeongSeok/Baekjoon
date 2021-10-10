#include <iostream>

using namespace std;

#define MAX_N 101

long long memoization[MAX_N] = { 0, 1, 1, };

class PadovanSequenceClass {
public : 
	long long recursivePadovan(int n) {
		if (n < 3)
			return memoization[n];
		else if (memoization[n] == 0)
			memoization[n] = recursivePadovan(n - 2) + recursivePadovan(n - 3);
		return memoization[n];
	}
	void repeatPadovan(int n) {
		for (int i = 3; i <= n; i++) {
			memoization[i] = memoization[i - 3] + memoization[i - 2];
		}
	}
};

//int main() {
//	int n = 0;
//	int testCase = 0;
//	PadovanSequenceClass pscObj;
//	cin >> testCase;
//
//	/*while (testCase--) {
//		cin >> n;
//		pscObj.repeatPadovan(n);
//		cout << memoization[n] << endl;
//	}*/
//	while (testCase--) {
//		cin >> n;
//		pscObj.recursivePadovan(n);
//		cout << memoization[n] << endl;
//	}
//}