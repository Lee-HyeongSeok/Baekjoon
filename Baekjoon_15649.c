#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define SIZE 10
int n, m;
int arr[SIZE];
int ckeck[SIZE];

void DFS(int t) {
	// 함수로 전달된 인자와 고른 수열 m이 일치할 때
	// 탐색 완료했을 때
	if (t == m) {
		for (int i = 0; i < m; i++) {
			printf("%d ", arr[i]); // 수열 출력
		}
		printf("\n");
		return; 
	}
	// 1부터 n까지의 자연수 탐색
	for (int i = 1; i <= n; i++) {
		// 두 번째 수 부터 탐색, 0일 때
		if (ckeck[i] == 0) {
			ckeck[i] = 1; // 체크, 중복 방지
			arr[t] = i; // 배열에 1부터 삽입
			DFS(t + 1); // 다음 배열을 위한 재귀
			ckeck[i] = 0; // 다음 배열로 넘어가기위한 동작
		}
	}
}
int main() {
	scanf("%d %d", &n, &m);
	DFS(0);
}