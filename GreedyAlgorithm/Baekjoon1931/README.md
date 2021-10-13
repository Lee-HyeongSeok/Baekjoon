## 백준 1931번 - 회의실 배정 문제

***

<br> 

### :pushpin: 도전 코드(시간초과)

```c++
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 회의실 시작과 끝 시간을 저장할 클래스
class MeetingClass {
private : 
	int start;
	int end;
	int maxConf; // 각 회의가 선택되었을 때 가질 수 있는 최대 회의 수
public : 
	void setStart() { cin >> start; }
	void setEnd() { cin >> end; }
	int getStart() { return start; }
	int getEnd() { return end; }
	void setMaxConf(int cnt) { maxConf = cnt; }
	int getMaxConf() { return maxConf; }
};

int main() {
	int N = 0;
	int temp = 0, cnt = 0;
	vector<MeetingClass> schedule; // 회의 배정 스케줄을 저장할 벡터
	MeetingClass mcObj; // 회의 시작과 끝 시간을 저장할 클래스

    // 최대 회의 입력 받기
	cin >> N;

    // 입력 받은 최대 회의만큼 시작과 끝 시간 입력 받기
	while (N--) {
		mcObj.setStart(); mcObj.setEnd();
		schedule.push_back(mcObj);
	}

	// 시작과 시간을 기준으로 오름차순 정렬
	// 시작 시간이 같으면 끝 시간을 기준으로 오름차순 정렬
    // 클래스를 정렬해야 하므로 insert sort를 사용하여 정렬
	for (int i = 1; i < schedule.size(); ++i) {
		for (int j = 0; j < i; ++j) {
            // 시작 시간 기준으로 정렬
			if (schedule[i].getStart() < schedule[j].getStart()) {
				iter_swap(schedule.begin() + j, schedule.begin() + i);
			}
            // 시작 시간이 일치하는 회의 일정이 있다면
			else if (schedule[i].getStart() == schedule[j].getStart()) {
				// 해당 두 회의 일정의 끝 시간을 비교하여 오름차순 정렬
                  if (schedule[i].getEnd() < schedule[j].getEnd()) {
					iter_swap(schedule.begin() + j, schedule.begin() + i);
				}
			}
		}
	}

	for (int i = 0; i < schedule.size(); ++i) {
        // 무조건적으로 자신을 먼저 선택
        // temp는 끝 시간을 기억하기 위한 변수
		temp = schedule[i].getEnd();
		cnt++;

        // 지금 당장의 회의 시간이 위에서 정해지고, 다음 회의를 진행할 수 있는 일정을 찾는다.
		for (int j = 0; j < schedule.size(); ++j) {
            // 끝나는 시간과 다음 회의의 시작 시간을 비교
			if ((temp <= schedule[j].getStart()) && (i != j)) {
                // 해당 회의가 선택되었을 때 그 회의의 끝 시간으로 temp를 초기화
				temp = schedule[j].getEnd(); 
				cnt++;
			}
		}
        // 각 일정이 가질 수 있는 최대 회의 수를 삽입
		schedule[i].setMaxConf(cnt);
		cnt = 0;
	}

    // 회의의 일정 중 최대 가능한 회의 수를 max 함수로 비교
	int maxConf = 0;
	for (int i = 0; i < schedule.size(); ++i) {
		maxConf = max(maxConf, schedule[i].getMaxConf());
	}
	cout << maxConf << endl;
}
```

<br>

### :pushpin: 예상되는 이유

- insertion sort에서 시간 초과
  - 최선의 경우 : O(n), 최악의 경우 : O(n^2)

<br> 

### :pushpin: 해결 방안

- 클래스 설계 대신 pair 객체를 사용
- 퀵 정렬을 사용하는 Algorithm Header의 sort()를 사용한 vector 정렬

<br> 

### :pushpin: 맞은 답

```c++
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAXN 100000

class MeetingClass {
private : 
	int start;
	int end;
	int maxConf;
public : 
	void setStart() { cin >> start; }
	void setEnd() { cin >> end; }
	int getStart() { return start; }
	int getEnd() { return end; }
	void setMaxConf(int cnt) { maxConf = cnt; }
	int getMaxConf() { return maxConf; }
};

MeetingClass mcObj[MAXN];

bool compareEndTime(MeetingClass& c1, MeetingClass& c2) {
	return c1.getEnd() < c2.getEnd();
}

bool compareStartTime(MeetingClass& c1, MeetingClass& c2) {
	return c1.getStart() < c2.getStart();
}

int main() {
	int N = 0;
	int temp = 0, cnt = 0, maxConf = 0;

	cin >> N;

	
	for (int i = 0; i < N; ++i) {
		mcObj[i].setStart(); mcObj[i].setEnd();
	}

	// 시작 시간 오름차순 기준으로 정렬, 시작 시간이 같다면 끝 시간 기준으로 정렬
	sort(mcObj, mcObj+N, compareEndTime);


	for (int i = 0; i < N; ++i) {
		// 현재 선택된 회의의 끝 시간보다 크거나 같은 다른 회의 시작 시간이 있다면
		if (temp <= mcObj[i].getStart()) {
			int j = i + 1;
			while ((j < N) && (mcObj[i].getEnd() == mcObj[j].getEnd())) {
				j++;
			}
			sort(mcObj + i, mcObj + j, compareStartTime);
			temp = mcObj[i].getEnd();
			maxConf++;
		}
	}
	cout << maxConf << endl;
}

// 출처 : http://melonicedlatte.com/algorithm/2018/02/02/014531.html
```

<br> 

### :pushpin: 바뀐 부분

- vector에 삽입하지 않고 전역 변수로 Class 배열을 선언
- 100,000개의 데이터를 처리해야 하므로 O(n^2) 시간 복잡도는 시간 초과를 발생시킴
  - O(nlogn) 시간 복잡도로 해결해야 함
- 회의의 끝 시간을 기준으로 정렬 후, 현재 기준에서 가능한 회의가 빨리 끝나는 회의 일정을 선택
  - 1. 회의 끝 시간 기준 정렬
    2. 끝 시간이 같은 회의들에 대해 회의 시작 시간 기준으로 재정렬
  - 모든 회의의 끝나는 시간이 같다고 가정(8 8, 7 8 형식으로 데이터가 삽입될 수 있기 때문)