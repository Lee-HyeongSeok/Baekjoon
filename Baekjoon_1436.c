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
			// 666�� ���������� �����ϸ�
			if (arr[i - 2] == 6 && arr[i - 1] == 6 && arr[i] == 6) {
				N--; // ã���� �ϴ� ī��Ʈ �� ���� �� Ż��
				break;
			}
		}
		// �� �������� N�� ° ���� 0���� ���� ��
		if (N == 0) {
			int good = 0;
			for (int i = 9; i >= 0; --i) {
				if (!good) {
					// �� �迭�� 0�̸� �н�, �ٽ� ������
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