#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define SWAP(a, b){int t=a; a=b; b=t;}

int partition(int *list, int left, int right) {
	int pivot;
	int low, high;

	low = left;
	high = right + 1;
	pivot = list[left];
	do {
		do {
			low++;
		} while (low <= right && list[low] < pivot);
		do {
			high--;
		} while (high >= left && list[high] > pivot);
		if (low < high)
			SWAP(list[low], list[high]);
	} while (low < high);

	SWAP(list[left], list[high]);

	return high;
}
void quick_sort(int *list, int left, int right) {
	if (left < right) {
		int q = partition(list, left, right);
		quick_sort(list, left, q - 1);
		quick_sort(list, q + 1, right);
	}
}
int main() {
	int n;
	scanf("%d", &n);

	int *arr = (int*)malloc(sizeof(int)*n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	printf("\n");
	quick_sort(arr, 0, n-1);
	
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	
	free(arr);

}