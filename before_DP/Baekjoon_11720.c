#include <stdio.h>
#include <stdlib.h>

// ������ ���ڿ��� �Է¹޴� ����

int main() {
	int size = 0;
	int sum = 0;
	int cnt = 0;
	char val;
	scanf("%d", &size);
	char * arr = (char*)malloc(sizeof(char) * size);
	
	// ������ ���ڷ� �Է¹޴´�.
	for (int i = 0; i < size +1; i++) {
		scanf("%c", &val);
		// 0���� 9������ ������ ��쿡�� �����Ѵٴ� �ǹ�
		if (val >= '0' && val <= '9') {
			arr[cnt++] = val;
		}
	}
	for (int i = 0; i < size; i++) {
		sum += ((int)arr[i]) - 48; // ���ڸ� ������ �ٲ��ִ� ����
	}
	printf("%d", sum);
	
	free(arr);
}