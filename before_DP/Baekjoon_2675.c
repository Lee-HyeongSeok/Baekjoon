#include <stdio.h>
#include <stdlib.h>

void PrintChar(char val, int size) {
	if (val != 0 && val != NULL && val != ' ') {
		for (int i = 0; i < size; i++) {
			printf("%c", val);
		}
	}
}


int main() {
	int test = 0;
	int size = 0;
	scanf("%d", &test);

	// 각 테스트 케이스마다 문자열 반복
	for (int i = 0; i < test; i++) {
		scanf("%d", &size); // 반복 크기 입력받음
		
		char *arr = (char*)malloc(sizeof(char)*size+1);

		for (int j = 0; j < size+1; j++) {
			scanf("%c", &arr[j]); // 문자입력 받음
		}
		for (int j = 0; j < size+1; j++) {
			PrintChar(arr[j], size);
		}
		printf("\n");
		size = 0;
		free(arr);
	}
}