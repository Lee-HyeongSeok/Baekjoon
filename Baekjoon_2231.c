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
	
	int result = num - sum; // ù ������
	int s = 0, tmp = 0;
	int t = result;
	int min = 0;

	// ���� �����ڸ� 1�� ���ҽ�Ű�� ���� ���� �����ڸ� ���ϴ� ����
	for (int i = 0; t >= 100; i++) {
		t = result - i; // �����ڸ� 1�� ����
		tmp = t; // ���ҵ� �����ڸ� ������Ű�� �ʱ� ����

		// �����ڸ� �ڸ������ �и��Ͽ� ��� ���� ���� ã�� ����
		for (int j = 0; j < 3; j++) {
			s += tmp % 10;
			tmp = tmp / 10;
		}
		// �ڿ��� N�� ���ҵ� �����ڸ� �� ���� 
		// ���� ��� ���� ���� ���ٸ� �ڿ��� N�� ��������
		if (num - t == s) {
			min = t; // �� ���������� ������ ���ҵ� �����ڰ� ���� ���� ������
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