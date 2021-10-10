#include <stdio.h>

int main() {
	int denominator; // 분모
	int numerator; // 분자

	int find_num;
	int cnt = 0;
	int uper = 1;

	scanf("%d", &find_num);

	for (int i = 1; i <= find_num; i++) {
		if (i == 1) {
			denominator = 1;
			numerator = 1;
			cnt++;
		}
		else {
			for (int j = i; j > 0; j--) {
				if (cnt == find_num) {
					printf("%d / %d\n", numerator, denominator);
					return;
				}
				if ((i % 2) == 0) {
					denominator = j; // 짝수일 때 분모는 역순
					numerator = uper++; // 짝수일 때 분자는 정순
				}
				else if ((i % 2) == 1) {
					denominator = uper++; // 홀수일 때 분모는 정순
					numerator = j; // 홀수일 때 분자는 역순
				}
				cnt++;
				
			}
			uper = 1;
		}
	}
	printf("%d / %d", numerator, denominator);
}