#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#define SWAP(a, b){int t=a; a=b; b=t;}

void Permutations(int *a, const int k, const int m) {
	if (k == m) {
		for (int i = 0; i <= m; i++) {
			printf("%d ", a[i]);
		}
		printf("\n");
	}
	else {
		for (int i = k; i <= m; i++) {
			SWAP(a[k], a[i]);
			Permutations(a, k + 1, m);
			SWAP(a[k], a[i]);
		}
	}
}
int main() {
	int size = 0;
	scanf("%d", &size);
	int *arr = (int*)malloc(sizeof(int)*size);
	for (int i = 0; i < size; i++) {
		arr[i] = i + 1;
	}
	
	Permutations(arr, 0, size - 1);
	
	free(arr);
}