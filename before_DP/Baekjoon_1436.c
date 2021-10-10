#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int arr[10];

void up(int n) {
	if (arr[n] == 9) {
		arr[n] = 0;
		up(n + 1);
	}
	else
		arr[n]++;
}
int main() {
	int N;
	scanf("%d", &N);

	arr[0] = 6; arr[1] = 6; arr[2] = 6;

	while (1) {
		for (int i = 2; i < 10; ++i) {
			// 666이 순차적으로 존재하면
			if (arr[i - 2] == 6 && arr[i - 1] == 6 && arr[i] == 6) {
				N--; // 찾고자 하는 카운트 수 감소 후 탈출
				break;
			}
		}
		// 위 루프에서 N번 째 수가 0으로 됐을 때
		if (N == 0) {
			int good = 0;
			for (int i = 9; i >= 0; --i) {
				if (!good) {
					// 끝 배열이 0이면 패스, 다시 루프로
					if (arr[i] == 0)
						continue;
					else {
						good = 1;
						printf("%d", arr[i]);
					}
				}
				else
					printf("%d", arr[i]);

			}
			break;
		}
		else
			up(0);
	}
	
}