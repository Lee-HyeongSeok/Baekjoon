#include <stdio.h>
#include <stdlib.h>


int main() {
	char arr[100] = { 0 };

	scanf("%s", arr);
	
	for (char i = 'a'; i <= 'z'; i++) {
		for (int z = 0; z < 100; z++) {
			if (arr[z] == i) {
				printf("%d ", z); // 0���� 100���� �ش�Ǵ� �ܾ��� �ε��� ��� �� ����
				break;
			}
			else if (arr[z] == NULL && arr[z] == ' ') // ���� �� NULL���� �н�
				continue;
		}
		printf("%d ", -1); // ���� if���� �Ȱɸ��� �ش�Ǵ� ���ڰ� ���� ������ ����
	}
}