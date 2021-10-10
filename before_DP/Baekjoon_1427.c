#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// ������ ���� ��ũ���Լ� ����
#define SWAP(a, b){int t=a; a=b; b=t;}

// �ڸ����� �������� �Լ�
int CountNumber(int n) {
	int cnt = 0;
	int div = 10;
	int temp = 0;

	while (1) {
		// ������ ���� 0�� �� �� ������ �Ұ���, ����
		if (n <= 0)
			break;

		// ������ �������� ���� �����ϴ� temp����
		temp = n % div;
		n = n / div;
		if(temp > 0) // ������ ������ ���� 0�̻��̸� ī��Ʈ
			cnt++;
	}
	return cnt;
}

// ������ �����Ʈ��� ���
void Sorting(int *arr, int size) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j < size; j++) {
			// ���������̹Ƿ� ������ ���� ������ ���� ������ ��ġ��ȯ
			if (arr[i] < arr[j])
				SWAP(arr[i], arr[j]);
		}
	}
}
int main() {
	int num = 0;
	scanf("%d", &num);

	int size = CountNumber(num); // �ڸ��� ��ȯ

	// �� �ڸ����� �����ϱ����� �����Ҵ� ����
	int *arr = (int*)malloc(sizeof(int)*size);

	// �� �ڸ��� ���� �迭�� ����
	for (int i = 0; i < size; i++) {
		arr[i] = num % 10;
		num /= 10;
	}

	// ����� �迭�� ������������ ����
	Sorting(arr, size);

	for (int i = 0; i < size; i++) {
		// ��� �� ���
		printf("%d ", arr[i]);
	}
	free(arr);
}