#include <stdio.h>
#include <stdlib.h>

int main() {
	int test, num = 0;
	scanf("%d %d", &test, &num);

	int *arr = (int*)malloc(sizeof(int)*test);
	for (int i = 0; i < test; i++) {
		scanf("%d", &arr[i]);
	}
	int now = 0;
	for (int i = 0; i < test - 2; i++) {
		for (int j = i + 1; j < test - 1; j++) {
			for (int z = j + 1; z < test; z++) {
				// �� ���� ���� �־��� ������ �۰ų� ����,
				// �־��� ��-���� �� ���� ���� �־��� ��-���� �� ���� �պ��� ���� �� = �־��� ������ ���� ���� ���� �� ä��
				if (arr[i] + arr[j] + arr[z] <= num && num - (arr[i] + arr[j] + arr[z]) < num - now) {
					now = arr[i] + arr[j] + arr[z]; // ���� ���� �����ϴ� ����
				}
			}
		}
	}
	printf("%d", now);
	free(arr);
}