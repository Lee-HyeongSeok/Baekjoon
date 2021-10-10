#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
	int test = 0;
	scanf("%d", &test);

	// 단어를 저장하기 위한 2차원 배열
	char **arr;
	arr = (char**)malloc(sizeof(char*) * test);
	for (int i = 0; i < test; i++) {
		arr[i] = (char*)malloc(sizeof(char) * 51);
	}

	for (int i = 0; i < test; i++) {
		scanf("%s", arr[i]);
	}
	
	
	// 정렬된 단어를 저장하기 위한 동적할당
	
	
	char *temp = NULL;

	printf("*************************************\n");
	for (int i = 0; i < test-1; i++) {
		for (int j = i + 1; j < test; j++) {
			if (strlen(arr[i]) > strlen(arr[j])) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
				temp = NULL;
			}
		}
	}
	


	// 같은 길이 사전순 정렬
	
	int size = 0;
	temp = NULL; // 교환을 위한 재사용

	for (int i = 0; i < test - 1; i++) {
		for (int j = i + 1; j < test; j++) {
			// 길이가 같을 때
			if (strlen(arr[i]) == strlen(arr[j])) {
				size = strlen(arr[i]);
				
				// 앞, 뒤 단어 한 문자씩 비교한다.
				for (int z = 0; z < size; z++) {

					// 첫 문자가 더 크면 정렬
					if (arr[i][z] > arr[j][z]) {
						temp = arr[i];
						arr[i] = arr[j];
						arr[j] = temp;
						temp = NULL;
						break;
				
					} // 첫 문자가 더 작거나 같으면 반복문 탈출
					else {
						break;
					}
				}
			}
		}
	}
	
	// 중복을 제거하기 위한 표시
	int *rank = (int*)malloc(sizeof(int)*test);
	// 모든 값을 0으로 처리
	for (int i = 0; i < test; i++) {
		rank[i] = 0;
	}

	// 중복되는 부분을 검출
	for (int i = 0; i < test - 1; i++) {
		for (int j = i + 1; j < test; j++) {
			// 길이가 같고, 자신의 다음 단어가 같지 않은 것
			if ((strlen(arr[i]) == strlen(arr[j])) && !memcmp(arr[i], arr[j], strlen(arr[i]))) {
				rank[j] = 1; // 현재 자신이 중복되는 값이기 때문에 검출 표시
			}
		}
	}
	for (int i = 0; i < test; i++) {
		// 중복제거 표시가 안된 부분만 출력
		if (!rank[i]) {
			printf("%s\n", arr[i]);
		}
	}
	
	// 2차원 배열, 1차원 배열 메모리 해제
	for (int i = 0; i < test; i++) {
		free(arr[i]);
	}

	free(rank);
	free(arr);
}