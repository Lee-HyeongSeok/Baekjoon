#include <iostream>
#include <algorithm>
using namespace std;

#define MAXN 300

class StairsClass {
private : 
	int stairs[MAXN];
	int stairsDP[MAXN];
	int N;
public : 
	StairsClass(int N) : N(N){}

	void setStairs() {
		for (int i = 0; i < N; ++i) {
			cin >> stairs[i];
		}
	}

	void findingMaxScore() {
		stairsDP[0] = stairs[0];
		stairsDP[1] = max(stairs[1], stairs[0] + stairs[1]);
		stairsDP[2] = max(stairs[0] + stairs[2], stairs[1] + stairs[2]);

		for (int i = 3; i < N; ++i) {
			stairsDP[i] = max(stairs[i] + stairsDP[i-2], stairs[i] + stairs[i-1] + stairsDP[i-3]);
		}

		cout << stairsDP[N-1];
	}
};

//int main() {
//	int N;
//	cin >> N;
//	StairsClass scObj(N);
//	scObj.setStairs();
//	scObj.findingMaxScore();
//}