#include <stdio.h>

int main() {
	int arr[10] = { 0 };
	int result[10] = { -1 };
	int index = 0;

	// 열 번째 줄 까지 숫자를 입력받는다.
	for (int i = 0; i < 10; i++) {
		scanf("%d", &arr[i]);
	}

	// 해당 배열의 숫자를 42로 나눈 나머지를 자신의 위치인 배열에 저장
	for (int i = 0; i < 10; i++) {
		arr[i] = arr[i] % 42;
	}

	int temp = 0; // 굳이 없어도 되는데 내가헷갈려서 사용
	int cnt = 0; // 서로 다른 나머지를 카운팅하기 위함

	for (int i = 0; i < 9; i++) {
		temp = arr[i];
		for (int j = i + 1; j < 10; j++) {

			// -1을 저장시킨 이유는 공백이라는 의미를 두기 위함
			// 나눠 떨어지면 0이 나오기 때문에임
			if (temp == arr[j] && arr[j] != -1) {
				arr[j] = -1;
				cnt++;
			}
		}
	}
	printf("%d", 10 - cnt);
}