#include <stdio.h>

int ReturnDouble(int n) {
	return n * n;
}
int main() {
	int max, mid, min;
	int a, b, c;

	while (1) {
		scanf("%d %d %d", &a, &b, &c);

		if (a == 0 && b == 0 && c == 0)
			break;

		//�ִ� ���� ���ϴ� ����
		max = a >= b ? a : b;
		max = max >= c ? max : c;

		//�ּҰ��� ���ϴ� ����
		min = a >= b ? b : a;
		min = min > c ? c : min;

		//�߾Ӱ��� ���ϴ� ����
		int sum = a + b + c;
		mid = sum - (max + min);

		printf("\n");
		if (ReturnDouble(max) == ReturnDouble(mid) + ReturnDouble(min))
			printf("Right \n");
		else
			printf("wrong \n");
	}
	
}