#include <stdio.h>

int main() {
	int arr[6] = { 0 };
	int max=0, min=0;

	for (int i = 0; i < 6; i++) {
		scanf("%d", &arr[i]);
	}
	max = arr[0];
	min = arr[1];
	for (int i = 0; i < 6; i++) {
		if ((i % 2) == 0) {
			if (max < arr[i])
				max = arr[i];
		}
		else {
			if (min > arr[i])
				min = arr[i];
		}
	}
	printf("%d %d", max, min);
}