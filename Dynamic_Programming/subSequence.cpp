//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//#define MAXN 1001
//
//class subSequenceClass {
//private : 
//	int sequenceDP[MAXN];
//	int sequence[MAXN];
//	int N;
//public : 
//	subSequenceClass(int N) : N(N){}
//
//	void initValue() {
//		for (int i = 0; i < N; ++i) {
//			cin >> sequence[i];
//		}
//	}
//
//	void findLongSequence() {
//		int maxLength = 0;
//
//		for (int i = 0; i < N; ++i) {
//			sequenceDP[i] = 1; // �ڱ� �ڽź��� ������ ������ �� �ִ� ����
//			for (int j = 0; j < i; ++j) {
//				// sequence[i]�� ������ġ, sequence[j]�� ������ġ ������ ��ġ��(������ġ����)
//				// ������ġ�� ������ ���� ���� �����Ѵٸ�(�����Ǵ� �����̹Ƿ�)
//				if (sequence[i] > sequence[j]) {
//					/* 
//						���� ��ġ�� �ٷ� ���� �� �ִ� ���̿� 
//						���� ��ġ�� ������ ���� ���� ������ �ִ� ����+������ġ�� ���� �߰��Ǿ��� �� ���� �߿�
//						ū ���̸� ���� ��ġ�� ������ ���� DP�� ����
//					*/
//					sequenceDP[i] = max(sequenceDP[i], sequenceDP[j] + 1);
//				}
//			}
//			maxLength = max(sequenceDP[i], maxLength);
//		}
//		cout << maxLength;
//	}
//};
//
//int main() {
//	int N = 0;
//	cin >> N;
//	subSequenceClass sscObj(N);
//	sscObj.initValue();
//	sscObj.findLongSequence();
//}