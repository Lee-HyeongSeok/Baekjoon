#include <stdio.h>

#define MAX 14

int ReturnApart(int *arr, int K, int N) {
	int temp = 0;
	int arr2[14];

	for (int z = 1; z <= MAX; z++) { // 층
		for (int i = 0; i < MAX; i++) { // 호수
			for (int j = 0; j < i + 1; j++) { // 전 층 전 호수 인원들을 모두 더한다.
				temp += arr[j]; // 사람 수를 더하는 동작
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