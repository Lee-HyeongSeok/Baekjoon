#include <stdio.h>
#include <stdlib.h>
//#define min(a,b) (((a) < (b)) ? (a) : (b))
const int INF = 987654321;
#define MAX 50

int M, N;
char **board;

char whiteFirst[8][8] = {
	{"WBWBWBWB"},
	{"BWBWBWBW"},
	{"WBWBWBWB"},
	{"BWBWBWBW"},
	{"WBWBWBWB"},
	{"BWBWBWBW"},
	{"WBWBWBWB"},
	{"BWBWBWBW"}
};

char blackFirst[8][8] = {
	{"BWBWBWBW"},
{"WBWBWBWB"},
{"BWBWBWBW"},
{"WBWBWBWB"},
{"BWBWBWBW"},
{"WBWBWBWB"},
{"BWBWBWBW"},
{"WBWBWBWB"}
};

int whiteFirstChange(int y, int x) {
	int cnt = 0;
	for (int i = y; i < y + 8; i++) {
		for (int j = x; j < x + 8; j++) {
			if (board[i][j] != whiteFirst[i - y][j - x])
				cnt++;
		}
	}
	return cnt;
}

int blackFirstChange(int y, int x) {
	int cnt = 0;
	for (int i = y; i < y + 8; i++) {
		for (int j = x; j < x + 8; j++) {
			if (board[i][j] != blackFirst[i - y][j - x])
				cnt++;
		}
	}
	return cnt;
}
int main() {
	scanf("%d %d", &N, &M);

	board = (char**)malloc(sizeof(char*)*N);
	for (int i = 0; i < N; i++) {
		board[i] = (char*)malloc(sizeof(char)*M);
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%c", &board[i][j]);
		}
	}
	int result = INF;

	for (int i = 0; i + 7 < N; i++) {
		for (int j = 0; j + 7 < M; j++) {
			result = min(result, min(whiteFirstChange(i, j), blackFirstChange(i, j)));
		}
	}

	printf("%d", result);

	for (int i = 0; i < N; i++) {
		free(board[i]);
	}
	free(board);
	return 0;
}