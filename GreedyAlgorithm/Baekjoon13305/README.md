## **백준 13305번 - 주유소 문제**

***

<br> 

### :pushpin: 참조해서 풀었던 코드

```c++
#include <iostream>

using namespace std;

#define MAXN 1000000000 // 10억

long long dist[100001];
long long price[100001];

/*https://cocoon1787.tistory.com/337 참조 */

class GasStationClass {
private : 
	long long N; // 도시의 개수
	long long sum; // 최종 주유 비용을 저장하는 변수
	long long init; // 주유 도시를 결정하는 변수
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
        // 항상 싼 도시에서 최소한으로 주유한다면 총 주유 가격은 최소 값이 된다.
		for (int i = 1; i <= N - 1; ++i) {
            // 현재 도시 가격이 이전 도시 가격보다 싸다면
			if (price[i] < this->init)
				init = price[i]; // 이전 도시 가격을 저장
            // 더 싼 가격의 도시가 나타나기 전까지 루프를 반복하며 총 주유 가격을 계산
			sum += (this->init * dist[i]);
		}
		cout << sum << endl;
	}
};

int main() {
	GasStationClass gscObj; // 생성자 생성과 동시에 도시 개수를 입력 받는다.
	gscObj.getDist(); // 각 도시 사이 거리를 입력 받는다.
	gscObj.getPrice(); // 각 도시의 주유 가격을 입력 받는다.
	gscObj.findMinOfPrice(); // 최소 주유 비용을 찾는다.
}
```

<br> 

### :pushpin: 해결 방법

- 항상 주유 비용이 싼 도시에서 다음 도시까지의 거리만큼만 주유하면 총 주유량은 최소 값이 된다.

- 현재 도시 가격과 비교하며 가변적인 변수를 하나 선언하여 이전 도시 가격과 비교한 후에<br> 더 싼 도시의 주유 비용을 저장하고 계산한다.

  > for(;;){
  >
  > ​	if(현재 도시 주유 가격 < 이전 도시 주유 가격)
  >
  > ​		변수 = 현재 도시 주유 가격
  >
  > ​    총 주유값 += (변수 * 거리)
  >
  > }