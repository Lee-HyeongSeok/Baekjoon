#include <stdio.h>

int main() {
	int arr[10] = { 0 };
	int result[10] = { -1 };
	int index = 0;

	// �� ��° �� ���� ���ڸ� �Է¹޴´�.
	for (int i = 0; i < 10; i++) {
		scanf("%d", &arr[i]);
	}

	// �ش� �迭�� ���ڸ� 42�� ���� �������� �ڽ��� ��ġ�� �迭�� ����
	for (int i = 0; i < 10; i++) {
		arr[i] = arr[i] % 42;
	}

	int temp = 0; // ���� ��� �Ǵµ� �����򰥷��� ���
	int cnt = 0; // ���� �ٸ� �������� ī�����ϱ� ����

	for (int i = 0; i < 9; i++) {
		temp = arr[i];
		for (int j = i + 1; j < 10; j++) {

			// -1�� �����Ų ������ �����̶�� �ǹ̸� �α� ����
			// ���� �������� 0�� ������ ��������
			if (temp == arr[j] && arr[j] != -1) {
				arr[j] = -1;
				cnt++;
			}
		}
	}
	printf("%d", 10 - cnt);
}