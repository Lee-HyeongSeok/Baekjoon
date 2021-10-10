#include <iostream>
#include <algorithm>

using namespace std;

#define MAXN 501

int electricCordDP[MAXN];
int electricCordArry[MAXN];

class ElectricCordClass {
private : 
	int N;
	int top;
	int numberOfMaxSequence;
	int emptyValue;
public : 
	ElectricCordClass(int N) : N(N) { numberOfMaxSequence = 0; emptyValue = 0; }

	void initValue() {
		int x, y;

		while (N--) {
			cin >> x >> y;
			// x : x 전봇대의 번호, y : y 전봇대의 번호 
			electricCordArry[x] = y;
			top = max(top, x);
		}

		for (int i = 1; i <= top; ++i) {
			if (electricCordArry[i] == 0)
				emptyValue++;
		}
	}

	void figureOutSequence() {
		for (int i = 1; i <= top; ++i) {
			electricCordDP[i] = 1;

			if (electricCordArry[i] != 0) {
				for (int j = 1; j < i; ++j) {
					if ((electricCordArry[i] > electricCordArry[j]) && (electricCordArry[j] != 0)) {
						electricCordDP[i] = max(electricCordDP[i], electricCordDP[j] + 1);
					}
				}
				numberOfMaxSequence = max(electricCordDP[i], numberOfMaxSequence);
			}
		}
		cout << top-(numberOfMaxSequence+emptyValue);
	}
};

//int main() {
//	int testCase = 0;
//	cin >> testCase;
//	ElectricCordClass eccObj(testCase);
//	eccObj.initValue();
//	eccObj.figureOutSequence();
//	return 0;
//}