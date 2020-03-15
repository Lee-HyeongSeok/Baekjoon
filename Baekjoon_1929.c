#include <stdio.h>
#include <stdlib.h>


int main() {
	int N, M;
	scanf("%d %d", &N, &M);

	int *arr = (int*)malloc(sizeof(int) * ((M - N) + 1));
	int cnt = 0;

	for (int i = N; i <= M; i++) {
		arr[cnt++] = i;
	}
	int temp = 0;
	cnt = 0;

	for (int i = 0; i < (M - N) + 1; i++) {
		temp = arr[i];
		for (int j = 2; j < temp; j++) {
			if (temp % j == 0)
				cnt++;
		}
		if (cnt == 0) { // 소수일 때
			for (int j = 2; j < (M-N)+1; j++) {
				for (int z = i; z < (M - N) + 1; z++) {
					if (temp * j == arr[z]) {
						arr[z] = 0;
						break;
					}
				}
			}
		}
		else {
			arr[i] = 0;
		}
		cnt = 0;
	}
	for (int i = 0; i < (M - N) + 1; i++) {
		if (arr[i] != 0)
			printf("%d\n", arr[i]);
	}
	free(arr);
}