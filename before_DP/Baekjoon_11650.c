#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

// ������ ���� ��ũ�� �Լ�����
#define SWAP(a, b){int t=a; a=b; b=t;}

int main() {
	int size = 0;
	scanf("%d", &size);

	size *= 2; // x�� y��ǥ�� �ޱ����� ó������ �׽�Ʈ ���̽��� 2�� ���ش�.

	// ��ǥ�� �����ϱ� ���� �迭 ����
	int *arr = (int*)malloc(sizeof(int)*(size));

	// x, y, x, y, x, y... ������ �Է¹޴´�.
	for (int i = 0; i < size; i++) {
		scanf("%d", &arr[i]);
	}


	for (int i = 0; i < size-1; i++) { // ù ��° for���� �� ���� ��������

		// �� ��° for���� ���� ���� �������� �����δ�.
		for (int j = i + 1; j < size; j++) {
			// x��ǥ�� ���� �񱳽�Ű�� ���� 2�� ����� ���� ���Ѵ�.
			if (i % 2 == 0 && j % 2 == 0) { //���ذ��� �񱳰��� 2�� ����� ��

				// �������� ����
				if (arr[i] > arr[j]) { // ���� ���� ������ ������ Ŭ ��
					SWAP(arr[i], arr[j]); // x��ǥ�� ����
					SWAP(arr[i + 1], arr[j + 1]); // y��ǥ�� ���� ����
				}
				else if (arr[i] == arr[j]) { // ���� x��ǥ���� ���� �����
					// y��ǥ�� ���Ѵ�.
					if (arr[i + 1] > arr[j + 1]) {
						SWAP(arr[i], arr[j]);
						SWAP(arr[i + 1], arr[j + 1]);
					}
				}
			}
		}
	}
	// ���ĵ� �迭 ���
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
		if (i % 2 == 0 && i != 0)
			printf("\n");
	}
	free(arr);
}