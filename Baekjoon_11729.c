#include <stdio.h>

// a에서 c로 옮기는게 목적
void Hanoi_loop(int a, int b, int c, int num) {
	if (num == 1)
		printf("%d %d \n", a, c);
	else {
		//b와 c자리를 바꿔 재귀
		Hanoi_loop(a, c, b, num - 1);
		printf("%d %d \n", a, c);
		//a와 b자리를 바꿔 재귀
		Hanoi_loop(b, a, c, num - 1);
	}
}
int main() {
	int num = 0;
	scanf("%d", &num);

	Hanoi_loop(1, 2, 3, num);
}