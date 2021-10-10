#include <stdio.h>
#include <stdlib.h>

int main() {
	int test, num = 0;
	scanf("%d %d", &test, &num);

	int *arr = (int*)malloc(sizeof(int)*test);
	for (int i = 0; i < test; i++) {
		scanf("%d", &arr[i]);
	}
	int now = 0;
	for (int i = 0; i < test - 2; i++) {
		for (int j = i + 1; j < test - 1; j++) {
			for (int z = j + 1; z < test; z++) {
				// 세 수의 합이 주어진 수보다 작거나 같고,
				// 주어진 수-현재 세 수의 합이 주어진 수-이전 세 수의 합보다 작을 때 = 주어진 수와의 차가 제일 작은 수 채택
				if (arr[i] + arr[j] + arr[z] <= num && num - (arr[i] + arr[j] + arr[z]) < num - now) {
					now = arr[i] + arr[j] + arr[z]; // 이전 합을 저장하는 동작
				}
			}
		}
	}
	printf("%d", now);
	free(arr);
}