#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

// 정렬을 위한 매크로 함수선언
#define SWAP(a, b){int t=a; a=b; b=t;}

int main() {
	int size = 0;
	scanf("%d", &size);

	size *= 2; // x와 y좌표를 받기위해 처음받은 테스트 케이스를 2배 해준다.

	// 좌표를 저장하기 위한 배열 선언
	int *arr = (int*)malloc(sizeof(int)*(size));

	// x, y, x, y, x, y... 순으로 입력받는다.
	for (int i = 0; i < size; i++) {
		scanf("%d", &arr[i]);
	}


	for (int i = 0; i < size-1; i++) { // 첫 번째 for문은 주 값을 기준으로

		// 두 번째 for문은 비교할 값을 기준으로 움직인다.
		for (int j = i + 1; j < size; j++) {
			// x좌표들 끼리 비교시키기 위해 2의 배수일 때만 비교한다.
			if (i % 2 == 0 && j % 2 == 0) { //기준값과 비교값이 2의 배수일 때

				// 오름차순 정렬
				if (arr[i] > arr[j]) { // 왼쪽 값이 오른쪽 값보다 클 때
					SWAP(arr[i], arr[j]); // x좌표를 정렬
					SWAP(arr[i + 1], arr[j + 1]); // y좌표도 같이 정렬
				}
				else if (arr[i] == arr[j]) { // 만약 x좌표끼리 같은 수라면
					// y좌표를 비교한다.
					if (arr[i + 1] > arr[j + 1]) {
						SWAP(arr[i], arr[j]);
						SWAP(arr[i + 1], arr[j + 1]);
					}
				}
			}
		}
	}
	// 정렬된 배열 출력
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
		if (i % 2 == 0 && i != 0)
			printf("\n");
	}
	free(arr);
}