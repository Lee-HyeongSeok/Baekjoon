#include <stdio.h>
#include <stdlib.h>
// 각 점수 / 최고점수 * 100
// 평균 조작

int main() {
	int size = 0;
	scanf("%d", &size);

	// 입력된 사이즈만큼 동적할당
	int *arr = (int*)malloc(sizeof(int)*size);

	// 점수를 입력받는다.
	for (int i = 0; i < size; i++) {
		scanf("%d", &arr[i]);
	}
	int max = 0;

	// 최고 점수를 찾아준다.
	max = arr[0];
	for (int i = 1; i < size; i++) {
		if (max < arr[i])
			max = arr[i];
	}

	// 각 점수 / 최고점수 * 100
	double sum = 0;
	for (int i = 0; i < size; i++) {
		sum += ((double)arr[i] / (double)max) * 100;
	}
	printf("%g", sum / size);

}