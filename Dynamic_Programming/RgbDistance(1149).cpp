#include <iostream>
#include <algorithm>

using namespace std;

#define MAXN 1001
#define COAST 3

int memo[MAXN][COAST];
int coast[COAST];

class RGBClass {
public : 
	int findCoast(int N) {
		for (int i = 1; i <= N; ++i) {
			cin >> coast[0] >> coast[1] >> coast[2];
			// memo[i]�� ���������� ĥ������ ���ؼ��� ���� ���� �ʷϻ��̳� �Ķ����̾�� �Ѵ�.
			// memo[i]�� �Ķ������� ĥ������ ���ؼ��� ���� ���� �������̳� �ʷϻ��̾�� �Ѵ�.
			// memo[i]�� �ʷϻ����� ĥ������ ���ؼ��� ���� ���� �������̳� �Ķ����̾�� �Ѵ�.
			memo[i][0] = min(memo[i - 1][1], memo[i - 1][2]) + coast[0];
			memo[i][1] = min(memo[i - 1][0], memo[i - 1][2]) + coast[1];
			memo[i][2] = min(memo[i - 1][1], memo[i - 1][0]) + coast[2];
		}
		return min(memo[N][0], min(memo[N][1], memo[N][2]));
	}
};

//int main() {
//	int N;
//	RGBClass rgbObj;
//	cin >> N;
//	cout << rgbObj.findCoast(N) << endl;
//}