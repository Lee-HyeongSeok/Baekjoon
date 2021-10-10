#include <stdio.h>
#include <stdlib.h>

// 정수를 문자열로 입력받는 문제

int main() {
	int size = 0;
	int sum = 0;
	int cnt = 0;
	char val;
	scanf("%d", &size);
	char * arr = (char*)malloc(sizeof(char) * size);
	
	// 정수를 문자로 입력받는다.
	for (int i = 0; i < size +1; i++) {
		scanf("%c", &val);
		// 0부터 9까지의 문자일 경우에만 저장한다는 의미
		if (val >= '0' && val <= '9') {
			arr[cnt++] = val;
		}
	}
	for (int i = 0; i < size; i++) {
		sum += ((int)arr[i]) - 48; // 문자를 정수로 바꿔주는 동작
	}
	printf("%d", sum);
	
	free(arr);
}