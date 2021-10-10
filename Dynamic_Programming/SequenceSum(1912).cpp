#include <iostream>
#include <algorithm>

using namespace std;

#define MAXN 100001

int sequenceSumDP[MAXN];

class SequenceSumClass{
private : 
	int N;
	int sequence[MAXN];
	int maxSum;
public : 
	SequenceSumClass(int N) : N(N){ }

	void init() {
		for (int i=0; i<N; ++i){
			cin >> sequence[i];
			sequenceSumDP[i] = sequence[i];
		}
	}

	void findSequenceSum() {
		maxSum = sequenceSumDP[0];

		for (int i = 1; i < N; ++i) {
			sequenceSumDP[i] = max(sequenceSumDP[i - 1] + sequence[i], sequenceSumDP[i]);
			
			maxSum = max(maxSum, sequenceSumDP[i]);
		}

		cout << maxSum << endl;
	}
};

//int main() {
//	int N = 0;
//	cin >> N;
//
//	SequenceSumClass sscObj(N);
//	sscObj.init();
//	sscObj.findSequenceSum();
//
//	return 0;
//}