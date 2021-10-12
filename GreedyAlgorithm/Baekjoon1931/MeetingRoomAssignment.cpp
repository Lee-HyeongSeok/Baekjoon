#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAXN 100000

int confRoom[MAXN];

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

int main() {
	int N = 0;
	int temp = 0, cnt = 0;
	vector<MeetingClass> schedule;
	MeetingClass mcObj;

	cin >> N;

	while (N--) {
		mcObj.setStart(); mcObj.setEnd();
		schedule.push_back(mcObj);
	}

	// 시작과 시간을 기준으로 오름차순 정렬
	// 시작 시간이 같으면 끝 시간을 기준으로 오름차순 정렬 
	for (int i = 1; i < schedule.size(); ++i) {
		for (int j = 0; j < i; ++j) {
			if (schedule[i].getStart() < schedule[j].getStart()) {
				iter_swap(schedule.begin() + j, schedule.begin() + i);
			}
			else if (schedule[i].getStart() == schedule[j].getStart()) {
				if (schedule[i].getEnd() < schedule[j].getEnd()) {
					iter_swap(schedule.begin() + j, schedule.begin() + i);
				}
			}
		}
	}

	for (int i = 0; i < schedule.size(); ++i) {
		temp = schedule[i].getEnd();
		cnt++;

		for (int j = 0; j < schedule.size(); ++j) {
			if ((temp <= schedule[j].getStart()) && (i != j)) {
				temp = schedule[j].getEnd();
				cnt++;
			}
		}
		schedule[i].setMaxConf(cnt);
		cnt = 0;
	}

	int maxConf = 0;
	for (int i = 0; i < schedule.size(); ++i) {
		maxConf = max(maxConf, schedule[i].getMaxConf());
	}
	cout << maxConf << endl;
}