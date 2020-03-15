#include <stdio.h>

// a���� c�� �ű�°� ����
void Hanoi_loop(int a, int b, int c, int num) {
	if (num == 1)
		printf("%d %d \n", a, c);
	else {
		//b�� c�ڸ��� �ٲ� ���
		Hanoi_loop(a, c, b, num - 1);
		printf("%d %d \n", a, c);
		//a�� b�ڸ��� �ٲ� ���
		Hanoi_loop(b, a, c, num - 1);
	}
}
int main() {
	int num = 0;
	scanf("%d", &num);

	Hanoi_loop(1, 2, 3, num);
}