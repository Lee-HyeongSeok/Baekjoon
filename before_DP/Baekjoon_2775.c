#include <stdio.h>

#define MAX 14

int ReturnApart(int *arr, int K, int N) {
	int temp = 0;
	int arr2[14];

	for (int z = 1; z <= MAX; z++) { // ��
		for (int i = 0; i < MAX; i++) { // ȣ��
			for (int j = 0; j < i + 1; j++) { // �� �� �� ȣ�� �ο����� ��� ���Ѵ�.
				temp += arr[j]; // ��� ���� ���ϴ� ����
			}
			arr2[i] = temp;
			temp = 0;
			if (z == K && i == N - 1)
				return arr2[i];
		}
		for (int i = 0; i < MAX; i++) {
			arr[i] = arr2[i];
		}
	}
}
int main() {
	int arr[14];
	int sum = 0;
	int test = 0;

	for (int i = 1; i <= MAX; i++) {
		arr[i - 1] = i;
	}

	scanf("%d", &test);
	int K, N;
	int Amount = 0;

	for (int i = 0; i < test; i++) {
		scanf("%d %d", &K, &N);

		Amount = ReturnApart(arr, K, N);
		printf("%d", Amount);
	}
}