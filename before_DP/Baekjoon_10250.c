#include <stdio.h>
#include <stdlib.h>

int main() {
	int test = 0;
	scanf("%d", &test);

	int H;
	int W;
	int N;

	int *Room = (int*)malloc(sizeof(int)*test); // 방을 저장할 공간
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
					R_head = R_head - ((H * 100) - 100); // 방 호수 구하는 동작
				}
				else {
					R_head += 100; // 100호씩 증가
				}
			}
		}
	}

	for (int i = 0; i < test; i++) {
		printf("%d \n", Room[i]);
	}
	free(Room);
}