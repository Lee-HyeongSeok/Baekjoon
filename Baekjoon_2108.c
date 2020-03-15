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
			// low는 left를 가짐
			// low가 right보다 작고, list[low] 가 pivot, 즉 list[left]보다 작을 때
		} while (low <= right && list[low] < pivot);
		do {
			high--;
			// high는 right+1을 가짐
			// high가 left보다 크거나 같고, list[high]가 pivot보다 클 때
			// pivot은 list[left], 왼쪽 파티션에 자신과의 비교대상보다 클 때
			// high를 감소시킨다. (오름차순 정렬상 더 큰 수가 오른쪽에 있기 때문)
		} while (high >= left && list[high] > pivot);

		// 위 조건들이 충족되지 않았을 때
		// 왼쪽 파티션의 값이 오른쪽 파티션의 자신의 짝 보다 클 때
		if (low < high) // low가 high를 넘지 않았을 때
			SWAP(list[low], list[high]); // 바꾼다.

	} while (low < high);// low는 high 보다 작아야 하기 때문
	
	SWAP(list[left], list[right]);

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
	int test = 0; // 테스트 케이스 개수 입력
	scanf("%d", &test);

	int sum = 0;
	// 숫자 입력 받기
	int *arr = (int*)malloc(sizeof(int)*test);
	for (int i = 0; i < test; i++) {
		scanf("%d", &arr[i]);
		sum += arr[i]; // 평균을 구하기 위해 입력 마다 더한다.
	}
	// 산술 평균
	printf("%d \n", sum / test);
	
	// 버블 정렬을 이용한 정렬
	for (int i = 0; i < test - 1; i++) {
		for (int j = i + 1; j < test; j++) {
			if (arr[i] > arr[j])
				SWAP(arr[i], arr[j]);
		}
	}
	// 퀵 정렬을 이용한 정렬
	// quick_sort(arr, 0, test-1);

	
	// 중앙값을 위해 index가 될 값을 미리 구한다.
	int mid = test / 2;
	printf("%d \n", arr[mid]);

	int cnt = 1;
	int max = 0; // 최빈값을 찾기위한 변수
	int head = 0; // 해당 최빈값의 index를 기억하기 위한 변수
	
	for (int i = 0; i < test; i++) {
		for (int j = 0; j < test; j++) {
			// 자기 자신을 제외
			if (i != j) {
				// 자신과 같은 값을 찾으면
				if (arr[i] == arr[j]) {
					cnt++;
				}
			}
		}
		// 최빈값 중 가장 큰 값을 찾기위한 동작
		if (max <= cnt) {
			max = cnt;
			head = i; // 해당 값의 인덱스를 저장
		}
		cnt = 1; // 빈도를 카운트한 후 다시 1로 초기화
	}

	// 최소 빈도는 1이므로 2이상일 때
	// 더 확실하게는 배열하나 만들어서 빈도 수를 저장한 후 결과 출력
	if (max >= 2)
		printf("%d\n", arr[head]);
	else
		printf("%d\n", arr[1]);

	int range_max = arr[0];
	int range_min = arr[0];
	for (int i = 1; i < test; i++) {
		// 최대값을 구하는 동작
		if (range_max < arr[i])
			range_max = arr[i];
		// 최소값을 구하는 동작
		if (range_min > arr[i])
			range_min = arr[i];
	}

	// 범위 = 최대 - 최소값
	printf("%d\n", range_max - range_min);

	free(arr);
}