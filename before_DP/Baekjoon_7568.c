#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main() {
	int test = 0;
	scanf("%d", &test);

	int **arr;
	arr = (int**)malloc(sizeof(int*)*test); // ������/Ű 2���� �迭
	// (0,0)���� ������, (1,0)���� Ű

	int *rank = (int*)malloc(sizeof(int)*test); // ��ũ �迭
	int cnt = 1;

	for (int i = 0; i < 2; i++) {
		arr[i] = (int*)malloc(sizeof(int) * 2);
	}
	for (int i = 0; i < test; i++) {
		scanf("%d %d", &arr[0][i], &arr[1][i]);
	}
	for (int i = 0; i < test; i++) {
		for (int j = 0; j < test; j++) {
			if (i != j) {
				// �ڽź��� ū ������, Ű�� ������
				if (arr[0][i] < arr[0][j] && arr[1][i] < arr[1][j]) {
					cnt++; // ��ũ�� �ϳ��� �þ��.
				}
				
			}
		}
		rank[i] = cnt;
		cnt = 1;
	}
	for (int i = 0; i < test; i++) {
		printf("%d", rank[i]);
	}
	for (int i = 0; i < test; i++) {
		free(arr[i]);
	}
	free(arr);
	free(rank);
}