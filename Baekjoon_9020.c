#include <stdio.h>
#include <stdlib.h>

int Prime(int n) {
	// 소수 판정
	if (n <= 1)
		return 0;
	else if (n == 2)
		return 1;
	for (int i = 2; i < n; i++) {
		if (n%i == 0)
			return 0;
	}
	return 1;
}

int main() {
	int test = 0;
	scanf("%d", &test);

	int temp = 0;
	int part1 = 0, part2 = 0;
	for (int i = 0; i < test; i++) {
		scanf("%d", &temp);

		// 수를 반으로 쪼개서 소수 검사
		for (int j = 2; j <= temp / 2; j++) {
			if (temp < j)
				break;
			if (Prime(j) && Prime(temp - j)) {
				part1 = j;
				part2 = temp - j;
			}
		}
		printf("%d %d \n", part1, part2);
		temp = 0;
	}
}