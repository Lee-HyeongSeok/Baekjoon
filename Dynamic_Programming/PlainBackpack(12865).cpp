#include <iostream>
#include <algorithm>

using namespace std;

#define MAXK 100001
#define MAXN 110

int backPackWeight[MAXN];
int backPackValue[MAXN];

// MAXN번째 물건의 무게는 MAXK, 이 가방에 담긴 물건의 최고 가치는 backPackDP[MAXN][MAXK]
int backPackDP[MAXN][MAXK];

class BackPackClass {
private : 
	int N;
	int K;
public : 

	void initBackPack() {
		cin >> N >> K;
		
		for (int i = 1; i <= N; ++i) {
			cin >> backPackWeight[i] >> backPackValue[i];
		}
	}

	void findMaxV() {
		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= K; ++j) {
				if (j >= backPackWeight[i]) {
					backPackDP[i][j] = max(backPackDP[i - 1][j], backPackDP[i - 1][j - backPackWeight[i]] + backPackValue[i]);
				}
				else {
					backPackDP[i][j] = backPackDP[i - 1][j];
				}
			}
		}
		cout << backPackDP[N][K] << endl;
	}
};

//int main() {
//	BackPackClass bpcObj;
//	bpcObj.initBackPack();
//	bpcObj.findMaxV();
//}

/*
출처 : https://yabmoons.tistory.com/571
*/