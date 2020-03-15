#include <stdio.h>

#define MAX 100

int Checker(char *temp) {
	char val;
	int head = 0;
	int state = 0;
	int minus = 0;

	for (int i = 0; i < MAX-1; i++) {
		val = temp[i];
		head = i;
		for (int j = i + 1; j < MAX; j++) {
			if (val == temp[j]) {
				minus = j - head; 
				head = j; // 같은 문자를 읽지 않기 위해 head를 조정
				if (minus > 1) { // 같은 문자를 읽었을 때
					state = 1;
				}
			}
			else if (val != temp[j]) {
				head = j - 1;
			}
		}
	}
	return state;
}

int main() {
	int size = 0;
	scanf("%d", &size);

	char str[MAX];
	int cnt = 0;
	int state = 0;

	// 테스트 케이스 마다 문자열 입력
	for (int i = 0; i < size; i++) {
		scanf("%s", str);

		state = Checker(str);

		cnt += state;
		
	}
	printf("\n cnt : %d \n", size-cnt);
}