#include <stdio.h>
#include <stdlib.h>

#define MAX 10000

int main() {
	char arr[MAX];
	int alphabet[26];
	char val = 'a';
	int cnt = 0;

	scanf("%s", arr);

	for (int j = 0; j < 26; j++) {
		for (int i = 0; i < MAX; i++) {
			// �ҹ����̰ų� �빮�ڸ� ī��Ʈ
			if (val == arr[i] || (val+32) == arr[i]) {
				cnt++;
			}
		}
		alphabet[j] = cnt;
		cnt = 0;
		val += 1;
	}

	int use_cnt = 0;
	int max_cnt = 0;
	int location = 0;

	max_cnt = alphabet[0];

	for (int i = 1; i < 26; i++) {
		if (max_cnt < alphabet[i]) {
			max_cnt = alphabet[i];
			location = i;
		}
	}
	for (int i = 0; i < 26; i++) {
		// ���� ���� ���� ���ĺ��� ������ �����ϸ�
		if (max_cnt == alphabet[i])
			use_cnt++;
	}
	if (use_cnt > 1) {
		printf("%c \n", '?');
	}
	else if (use_cnt < 2) {
		printf("%c \n", (char)alphabet[location] + 65);
	}
	
}