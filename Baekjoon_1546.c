#include <stdio.h>
#include <stdlib.h>
// �� ���� / �ְ����� * 100
// ��� ����

int main() {
	int size = 0;
	scanf("%d", &size);

	// �Էµ� �����ŭ �����Ҵ�
	int *arr = (int*)malloc(sizeof(int)*size);

	// ������ �Է¹޴´�.
	for (int i = 0; i < size; i++) {
		scanf("%d", &arr[i]);
	}
	int max = 0;

	// �ְ� ������ ã���ش�.
	max = arr[0];
	for (int i = 1; i < size; i++) {
		if (max < arr[i])
			max = arr[i];
	}

	// �� ���� / �ְ����� * 100
	double sum = 0;
	for (int i = 0; i < size; i++) {
		sum += ((double)arr[i] / (double)max) * 100;
	}
	printf("%g", sum / size);

}