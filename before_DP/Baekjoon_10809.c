#include <stdio.h>
#include <stdlib.h>


int main() {
	char arr[100] = { 0 };

	scanf("%s", arr);
	
	for (char i = 'a'; i <= 'z'; i++) {
		for (int z = 0; z < 100; z++) {
			if (arr[z] == i) {
				printf("%d ", z); // 0부터 100까지 해당되는 단어의 인덱스 출력 후 다음
				break;
			}
			else if (arr[z] == NULL && arr[z] == ' ') // 공백 및 NULL값은 패스
				continue;
		}
		printf("%d ", -1); // 위의 if문에 안걸리면 해당되는 문자가 없는 것으로 간주
	}
}