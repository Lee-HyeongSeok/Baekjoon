#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// 정렬을 위한 매크로함수 선언
#define SWAP(a, b){int t=a; a=b; b=t;}

// 자리수를 세기위한 함수
int CountNumber(int n) {
	int cnt = 0;
	int div = 10;
	int temp = 0;

	while (1) {
		// 나누는 수가 0이 될 때 나누기 불가능, 종료
		if (n <= 0)
			break;

		// 나누어 떨어지는 수를 저장하는 temp변수
		temp = n % div;
		n = n / div;
		if(temp > 0) // 나누어 떨어진 수가 0이상이면 카운트
			cnt++;
	}
	return cnt;
}

// 정렬은 버블솔트기법 사용
void Sorting(int *arr, int size) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j < size; j++) {
			// 내림차순이므로 왼쪽의 수가 오른쪽 보다 작으면 위치교환
			if (arr[i] < arr[j])
				SWAP(arr[i], arr[j]);
		}
	}
}
int main() {
	int num = 0;
	scanf("%d", &num);

	int size = CountNumber(num); // 자리수 반환

	// 각 자리수를 저장하기위한 동적할당 선언
	int *arr = (int*)malloc(sizeof(int)*size);

	// 각 자리수 별로 배열에 저장
	for (int i = 0; i < size; i++) {
		arr[i] = num % 10;
		num /= 10;
	}

	// 저장된 배열을 내림차순으로 정렬
	Sorting(arr, size);

	for (int i = 0; i < size; i++) {
		// 모든 값 출력
		printf("%d ", arr[i]);
	}
	free(arr);
}