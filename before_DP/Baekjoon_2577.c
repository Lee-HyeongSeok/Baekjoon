#include <stdio.h>
#include <stdlib.h>

/* �� ���� �ڿ��� �Է� �ް� 0 ���� 9������ �� ���ڰ� �� ���� ������� ��� */
int main() {
	int num1, num2, num3;
	scanf("%d %d %d", &num1, &num2, &num3);
	int result = 0;
	int cnt = 0;

	result = num1 * num2 * num3;
	int temp = result;

	while (1) {
		temp = temp / 10;
		cnt++;
		if (temp <= 10)
			break;
	}
	int NCnt = 1;
	temp = result;
	for (int i = 0; i < cnt; i++) {
		NCnt *= 10;
	}
	int *arr = (int*)malloc(sizeof(int)*(cnt + 1));
	for (int i = 0; i < cnt + 1; i++) {
		arr[i] = temp / NCnt;
		temp = temp % NCnt;
		NCnt = NCnt / 10;
	} 
	NCnt = 0;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < cnt + 1; j++) {
			if (i == arr[j]) {
				NCnt++;
			}
		}
		printf("\n %d�� %d�� \n", i, NCnt);
		NCnt = 0;
	}
	free(arr);
}
