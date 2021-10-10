#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void CountingArr(int *arr, int n) {
	int max = 0;
	int cnt = 0;
	int Sum_max = 0;

	max = arr[0];
	for (int i = 1; i < n; i++) {
		if (max < arr[i])
			max = arr[i];
	}
	int *temp = (int*)malloc(sizeof(int)*(max+1));

	for (int i = 0; i < max+1; i++) {
		for (int j = 0; j < n; j++) {
			if (i == arr[j]) {
				cnt++;
			}
		}
		temp[i] = cnt;
		cnt = 0;
	}
	int *Sum = (int*)malloc(sizeof(int)*(max + 1));

	Sum[0] = temp[0];
	for (int i = 1; i < max + 1; i++) {
		Sum[i] = Sum[i - 1] + temp[i];
		if (max < Sum[i])
			Sum_max = Sum[i];
	}
	int *result = (int*)malloc(sizeof(int)*(Sum_max + 1));
	int index = 0;
	int value = 0;
	for (int i = n-1; i >= 0; i--) {
		value = arr[i];
		index = Sum[value];
		result[index] = value;
		Sum[value] = Sum[value] - 1;
	}
	for (int i = 0; i < Sum_max + 1; i++) {
		if(result[i] >= 0)
			printf("%d ", result[i]);
	}
	free(result);
	free(Sum);
	free(temp);

}
int main() {
	int n;
	scanf("%d", &n);

	int *arr = (int*)malloc(sizeof(int)*n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	CountingArr(arr, n);

	free(arr);
}