#include <stdio.h>

void drawing(int y, int x, int num) {
	// 현재 좌표를 각 주어진 num으로 나눈 몫을 3으로 나눈 나머지가 1일 때
	// x는 1, 4, 7일 때 x%3 == 1, 빈공간이 찍혀야함
	if ((y / num) % 3 == 1 && (x / num) % 3 == 1) {
		printf(" "); /
	}
	else {
		// x는 3, 4, 5 y는 3, 4, 5일 때 
		// 몫%3 == 1일 때
		if (num / 3 == 0)
			printf("*");
		else
			// 주어진 수를 3으로 나눈 몫을 전달하는 재귀
			drawing(y, x, num / 3);
	}
}
int main() {
	int n = 0;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			drawing(i, j, n);
		}
		printf("\n");
	}
	
}