#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 1001

int sequenceDP[MAX][MAX];

class bitonicSubSequenceClass {
private :
	int sequence[MAX];
	int N;
public:
	bitonicSubSequenceClass(int N) : N(N) {}

	void initValue() {
		for (int i = 0; i < N; ++i) {
			cin >> sequence[i];
		}
	}

	void findLongSequence() {
		int maxLength = 0;

		for (int i = 0; i < N; ++i) {
			
			sequenceDP[0][i] = 1; // �ڱ� �ڽź��� ������ ������ �� �ִ� ����
			for (int j = 0; j < i; ++j) {
				// sequence[i]�� ������ġ, sequence[j]�� ������ġ ������ ��ġ��(������ġ����)
				// ������ġ�� ������ ���� ���� �����Ѵٸ�(�����Ǵ� �����̹Ƿ�)
				if (sequence[i] > sequence[j]) {
					/*
						���� ��ġ�� �ٷ� ���� �� �ִ� ���̿�
						���� ��ġ�� ������ ���� ���� ������ �ִ� ����+������ġ�� ���� �߰��Ǿ��� �� ���� �߿�
						ū ���̸� ���� ��ġ�� ������ ���� DP�� ����
					*/
					sequenceDP[0][i] = max(sequenceDP[0][i], sequenceDP[0][j] + 1);
				}
			}
		}

		for (int i = N - 1; i >= 0; --i) {
			sequenceDP[1][i] = 1;
			for (int j = N - 1; j > i; --j) {
				if (sequence[i] > sequence[j]) {
					sequenceDP[1][i] = max(sequenceDP[1][i], sequenceDP[1][j] + 1);
				}
			}
		}

		for (int i = 0; i < N; ++i) {
			maxLength = max(maxLength, sequenceDP[0][i] + sequenceDP[1][i] - 1);
		}
		cout << maxLength;
	}
};

//int main() {
//	int N = 0;
//	cin >> N;
//	bitonicSubSequenceClass bsscObj(N);
//	bsscObj.initValue();
//	bsscObj.findLongSequence();
//}