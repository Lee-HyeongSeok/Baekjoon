#include <stdio.h>

int main() {
	int N, M;
	int sum = 0;
	scanf("%d %d", &N, &M);

	int cnt = 0;
	int temp = 0;
	int first = 0;

	for (int i = N; i <= M; i++) {
		// 소수 찾는 과정
		for (int j = 2; j < i; j++) {
			if (i % j == 0) {
				cnt++;
			}
		}
		if (cnt == 0) {
			sum += i;
			first++;
			// 첫 번째로 찾는 소수가 최소값
			if (first == 1)
				temp = i;
		}
		cnt = 0;
	}
	if (sum == 0)
		printf("-1");
	else {
		printf("%d \n %d", sum, temp);
	}
}