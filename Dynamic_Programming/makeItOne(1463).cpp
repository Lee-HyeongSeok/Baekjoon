#include <iostream>
#include <algorithm>

using namespace std;

#define MAXN 1000001
int MakeItOneClassMemo[MAXN];

class MakeItOneClass {
public : 
	void findingMinValue(int N) {
		for (int i = 2; i <= N; ++i) {
			MakeItOneClassMemo[i] = MakeItOneClassMemo[i - 1] + 1;
			if (i % 3 == 0)
				MakeItOneClassMemo[i] = min(MakeItOneClassMemo[i / 3] + 1, MakeItOneClassMemo[i]);
			if (i % 2 == 0)
				MakeItOneClassMemo[i] = min(MakeItOneClassMemo[i / 2] + 1, MakeItOneClassMemo[i]);
		}
		cout << MakeItOneClassMemo[N];
	}
};

//int main() {
//	int N = 0;
//	MakeItOneClass mocObj;
//	cin >> N;
//	mocObj.findingMinValue(N);
//}