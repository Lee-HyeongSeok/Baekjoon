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
				// ���� �ڽ��� �������� �ڽŰ� ����� �θ� �˻�
				// ���� ���ʰ� ������ �θ� ���� �ε��� �����÷ο� ��Ȳ�� �˾Ƽ� �ε��� ������ �ǹǷ� ���� x
				// [0, 0]�϶� DP�� ����� [-1][-1]�� [-1][0]�� Ȯ���Ͽ� ���� ū ���� 0, 0 �ڽ��� ���� ���� ���� DP�� �߰�
				// [2, 1]�϶� DP�� ����� [1, 0]�� [1, 1]�� �� �θ��� �� �� ���� ū ���� �ڽ��� ���� ���� ���� DP�� �߰�
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