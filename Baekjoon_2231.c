#include <stdio.h>


int main() {
	int num = 0;
	scanf("%d", &num);

	int sum = 0;
	int temp = num;

	for (int i = 0; i < 3; i++) {
		sum += temp % 10;
		temp = temp / 10;
	}
	
	int result = num - sum; // 첫 생성자
	int s = 0, tmp = 0;
	int t = result;
	int min = 0;

	// 구한 생성자를 1씩 감소시키며 가장 작은 생성자를 구하는 동작
	for (int i = 0; t >= 100; i++) {
		t = result - i; // 생성자를 1씩 감소
		tmp = t; // 감소된 생성자를 변형시키지 않기 위함

		// 생성자를 자리수대로 분리하여 모두 더한 값을 찾는 동작
		for (int j = 0; j < 3; j++) {
			s += tmp % 10;
			tmp = tmp / 10;
		}
		// 자연수 N과 감소된 생성자를 뺀 값이 
		// 위에 모두 더한 값과 같다면 자연수 N의 생성자임
		if (num - t == s) {
			min = t; // 맨 마지막으로 구해진 감소된 생성자가 가장 작은 생성자
		}
		s = 0, tmp = 0;
	}
	if (min == 0) {
		printf("0");
	}
	else {
		printf("%d", min);
	}
}