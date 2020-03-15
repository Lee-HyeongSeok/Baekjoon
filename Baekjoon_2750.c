#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define SWAP(a, b){int t=a; a=b; b=t;}

int main() {
	int n;
	scanf("%d", &n);

	int *arr = (int*)malloc(sizeof(int)*n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (arr[i] > arr[j])
				SWAP(arr[i], arr[j]);
		}
	}
	for (int i = 0; i < n; i++) {
		printf("%d", arr[i]);
	}
	free(arr);
}