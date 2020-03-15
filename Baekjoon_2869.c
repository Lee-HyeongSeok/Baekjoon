#include <stdio.h>

int main() {
	int A, B, V;
	scanf("%d %d %d", &A, &B, &V);

	int sum = 0;
	int cnt = 1;

	while (1) {
		sum += A;
		if (sum >= V) {
			printf("%d", cnt);
			break;
		}
		else {
			sum -= B;
			cnt++;
		}
	}
	return 0;
}