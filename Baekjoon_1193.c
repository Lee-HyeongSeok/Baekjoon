#include <stdio.h>

int main() {
	int denominator; // �и�
	int numerator; // ����

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
					denominator = j; // ¦���� �� �и�� ����
					numerator = uper++; // ¦���� �� ���ڴ� ����
				}
				else if ((i % 2) == 1) {
					denominator = uper++; // Ȧ���� �� �и�� ����
					numerator = j; // Ȧ���� �� ���ڴ� ����
				}
				cnt++;
				
			}
			uper = 1;
		}
	}
	printf("%d / %d", numerator, denominator);
}