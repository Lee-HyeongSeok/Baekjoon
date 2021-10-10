#include <iostream>
#include <algorithm>

using namespace std;

#define MAXN 500

int triangle[MAXN][MAXN];
int triangleMemo[MAXN][MAXN];

class TriangleClass {
private : 
	int N;
	int maxNum;
public : 
	void setN(int N) { this->N = N; }
	void inputValue() {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < i + 1; j++) {
				cin >> triangle[i][j];
			}
		}
	}

	void findPath() {
		triangleMemo[0][0] = triangle[0][0];
		
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j <= i; ++j) {
				// 현재 자신을 기준으로 자신과 연결된 부모를 검사
				// 가끔 왼쪽과 오른쪽 부모가 없는 인덱스 오버플로우 상황은 알아서 인덱스 조절이 되므로 오류 x
				// [0, 0]일때 DP에 저장된 [-1][-1]과 [-1][0]을 확인하여 가장 큰 값과 0, 0 자신의 값을 더한 값을 DP에 추가
				// [2, 1]일때 DP에 저장된 [1, 0]과 [1, 1]인 두 부모의 값 중 가장 큰 값과 자신의 값을 더한 값을 DP에 추가
				triangleMemo[i][j] = max(triangleMemo[i - 1][j - 1], triangleMemo[i - 1][j]) + triangle[i][j];
				maxNum = max(maxNum, triangleMemo[i][j]);
			}
		}
		cout << maxNum;
	}
};

//int main() {
//	int N;
//	TriangleClass tcObj;
//	cin >> N;
//	tcObj.setN(N);
//	tcObj.inputValue();
//	tcObj.findPath();
//}