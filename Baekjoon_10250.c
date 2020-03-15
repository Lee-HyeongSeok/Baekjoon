#include <stdio.h>
#include <stdlib.h>

int main() {
	int test = 0;
	scanf("%d", &test);

	int H;
	int W;
	int N;

	int *Room = (int*)malloc(sizeof(int)*test); // ���� ������ ����
	int cnt = 0;

	for (int i = 0; i < test; i++) {
		int R_head = 101;
		scanf("%d %d %d", &H, &W, &N);
		
		for (int i = 1; i <= H*W; i++) {
			if (i == N) {
				Room[cnt] = R_head;
				cnt++;
			}
			else {
				if ((i % H) == 0) {
					R_head += 1;
					R_head = R_head - ((H * 100) - 100); // �� ȣ�� ���ϴ� ����
				}
				else {
					R_head += 100; // 100ȣ�� ����
				}
			}
		}
	}

	for (int i = 0; i < test; i++) {
		printf("%d \n", Room[i]);
	}
	free(Room);
}