#include <iostream>
#include <algorithm>

using namespace std;

#define MAXWINE 10001
int wineMemo[MAXWINE];

class WineClass {
private : 
	int wine[MAXWINE];
	int N;
public : 
	WineClass(int N) : N(N){
		for (int i = 0; i < N; ++i) {
			cin >> wine[i];
		}
	}
	void findingWineTasting() {
		int maxValue = 0;
		// n번까지 마셨을 때 최대로 마실 수 있는 포도주의 양 x
		// wineMemo[n] = x;
		wineMemo[0] = wine[0];
		wineMemo[1] = wine[0] + wine[1];
		
		for (int i = 2; i <= N; ++i) {
			wineMemo[i] = max(wineMemo[i-3]+wine[i-1]+wine[i], max(wineMemo[i-2]+wine[i], wineMemo[i-1]));
			if (maxValue < wineMemo[i])
				maxValue = wineMemo[i];
		}
		cout << wineMemo[N];
	}
};

//int main() {
//	int N = 0;
//	cin >> N;
//	WineClass wcObj(N);
//	wcObj.findingWineTasting();
//}