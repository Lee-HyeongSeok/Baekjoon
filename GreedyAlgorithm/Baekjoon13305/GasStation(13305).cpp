#include <iostream>

using namespace std;

#define MAXN 1000000000

long long dist[100001];
long long price[100001];

/*https://cocoon1787.tistory.com/337 ÂüÁ¶ */

class GasStationClass {
private : 
	long long N;
	long long sum;
	long long init;
public : 
	GasStationClass() {
		this->init = MAXN;
		this->sum = 0;
		cin >> N;
	}
	void getDist() {
		for (int i = 1; i <= N - 1; ++i) {
			cin >> dist[i];
		}
	}

	void getPrice() {
		for (int i = 1; i <= N; ++i) {
			cin >> price[i];
		}
	}
	void findMinOfPrice() {
		for (int i = 1; i <= N - 1; ++i) {
			if (price[i] < this->init)
				init = price[i];
			sum += (this->init * dist[i]);
		}
		cout << sum << endl;
	}
};

int main() {
	GasStationClass gscObj;
	gscObj.getDist();
	gscObj.getPrice();
	gscObj.findMinOfPrice();
}