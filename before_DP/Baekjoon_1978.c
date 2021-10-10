#include <stdio.h>
#include <stdlib.h>

int main() {
	int test = 0;
	scanf("%d", &test);
	int *arr = (int*)malloc(sizeof(int)*test);
	int temp = 0;

	for (int i = 0; i < test; i++) {
		scanf("%d", &arr[i]);
	}
	int cnt = 0;
	int af_cnt = 0;

	for (int i = 0; i < test; i++) {
		temp = arr[i];

		for (int j = 2; j < temp; j++) {
			if ((temp % j) == 0) {
				cnt++; // 약수가 있으면
			}
		}
		if (temp > 1 && cnt == 0) { // 1과 자기자신이 아닌 약수가 없을 때 소수 판정
			af_cnt++;
		}
		cnt = 0;
		temp = 0;

	}
	printf("%d", af_cnt);
	free(arr);
}