#include <stdio.h>
#include <math.h>

int main() {
	int test = 0;
	scanf("%d", &test);

	while (test--) {
		int start, end;
		scanf("%d %d", &start, &end);

		long long dist = end - start;

		long long jump = 1;
		for (;; jump++) {
			// ó���� �� �Ÿ����� Ŭ ��� ���� Ż��
			if (jump*jump > dist)
				break;
		}
		
		jump--;

		long long left = dist - (jump * jump);
		left = (long)ceil((double)left / (double)jump);

		printf("%lld", jump * 2 - 1 + left);
	}
	return 0;
}