#include <stdio.h>

int main() {
	int N, M;
	int sum = 0;
	scanf("%d %d", &N, &M);

	int cnt = 0;
	int temp = 0;
	int first = 0;

	for (int i = N; i <= M; i++) {
		// �Ҽ� ã�� ����
		for (int j = 2; j < i; j++) {
			if (i % j == 0) {
				cnt++;
			}
		}
		if (cnt == 0) {
			sum += i;
			first++;
			// ù ��°�� ã�� �Ҽ��� �ּҰ�
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