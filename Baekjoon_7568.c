#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main() {
	int test = 0;
	scanf("%d", &test);

	int **arr;
	arr = (int**)malloc(sizeof(int*)*test); // 몸무게/키 2차원 배열
	// (0,0)에는 몸무게, (1,0)에는 키

	int *rank = (int*)malloc(sizeof(int)*test); // 랭크 배열
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
				// 자신보다 큰 몸무게, 키가 있으면
				if (arr[0][i] < arr[0][j] && arr[1][i] < arr[1][j]) {
					cnt++; // 랭크가 하나씩 늘어난다.
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