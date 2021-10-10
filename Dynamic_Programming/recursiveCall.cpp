#include <iostream>

using namespace std;

#define MAX_N 21 

int memo[MAX_N][MAX_N][MAX_N];

class RecursiveCallClass {
private : 
	long result;
public : 
	RecursiveCallClass():result(0){}

	void startW(int a, int b, int c) {
		result = w(a, b, c);
	}
	int w(int a, int b, int c) {
		if ((a <= 0) || (b <= 0) || (c <= 0))
			return 1;
		else if ((a > 20) || (b > 20) || (c > 20)){
			if (memo[20][20][20] != 0)
				return memo[20][20][20];
			memo[20][20][20] = w(20, 20, 20);
			return memo[20][20][20];
		}
		else if ((a < b) && (b < c)) {
			if (memo[a][b][c] != 0)
				return memo[a][b][c];
			memo[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
			return memo[a][b][c];
		}
		else {
			if (memo[a][b][c] != 0)
				return memo[a][b][c];
			memo[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
			return memo[a][b][c];
		}
	}
	long getResult() {
		return result;
	}
};

//int main() {
//	int a, b, c;
//	RecursiveCallClass rcObj;
//
//	while (true) {
//		cin >> a >> b >> c;
//		if ((a == -1) && (b == -1) && (c == -1))
//			break;
//		rcObj.startW(a, b, c);
//		cout << "w(" << a << ", " << b << ", " << c << ") = " << rcObj.getResult() << endl;
//	}
//}