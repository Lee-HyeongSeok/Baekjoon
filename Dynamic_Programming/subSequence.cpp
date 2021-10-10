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
//			sequenceDP[i] = 1; // 자기 자신부터 무조건 시작할 수 있는 수열
//			for (int j = 0; j < i; ++j) {
//				// sequence[i]는 현재위치, sequence[j]는 현재위치 이전에 위치들(직전위치까지)
//				// 현재위치에 값보다 작은 값이 존재한다면(증가되는 수열이므로)
//				if (sequence[i] > sequence[j]) {
//					/* 
//						현재 위치가 바로 가질 수 있는 길이와 
//						현재 위치에 값보다 작은 값이 가지고 있는 길이+현재위치에 값이 추가되었을 때 길이 중에
//						큰 길이를 현재 위치가 가지는 길이 DP에 저장
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