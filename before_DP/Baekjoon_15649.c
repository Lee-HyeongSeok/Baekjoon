#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define SIZE 10
int n, m;
int arr[SIZE];
int ckeck[SIZE];

void DFS(int t) {
	// �Լ��� ���޵� ���ڿ� �� ���� m�� ��ġ�� ��
	// Ž�� �Ϸ����� ��
	if (t == m) {
		for (int i = 0; i < m; i++) {
			printf("%d ", arr[i]); // ���� ���
		}
		printf("\n");
		return; 
	}
	// 1���� n������ �ڿ��� Ž��
	for (int i = 1; i <= n; i++) {
		// �� ��° �� ���� Ž��, 0�� ��
		if (ckeck[i] == 0) {
			ckeck[i] = 1; // üũ, �ߺ� ����
			arr[t] = i; // �迭�� 1���� ����
			DFS(t + 1); // ���� �迭�� ���� ���
			ckeck[i] = 0; // ���� �迭�� �Ѿ������ ����
		}
	}
}
int main() {
	scanf("%d %d", &n, &m);
	DFS(0);
}