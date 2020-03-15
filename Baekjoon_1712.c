#include <stdio.h>

int main() {
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	int cnt = 1;
	int result = 0;
	int Break_Point = 0;

	while (1) {
		result = a + (b * cnt);
		Break_Point = c * cnt;
		cnt++;
		if (result < Break_Point) {
			printf("%d", cnt-1);
			return 0;
		}
	}
}