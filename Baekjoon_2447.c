#include <stdio.h>

void drawing(int y, int x, int num) {
	// ���� ��ǥ�� �� �־��� num���� ���� ���� 3���� ���� �������� 1�� ��
	// x�� 1, 4, 7�� �� x%3 == 1, ������� ��������
	if ((y / num) % 3 == 1 && (x / num) % 3 == 1) {
		printf(" "); /
	}
	else {
		// x�� 3, 4, 5 y�� 3, 4, 5�� �� 
		// ��%3 == 1�� ��
		if (num / 3 == 0)
			printf("*");
		else
			// �־��� ���� 3���� ���� ���� �����ϴ� ���
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