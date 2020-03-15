#include <stdio.h>

int main() {
	long long test = 0;
	int cnt = 0;
	int prime = 0;

	do {
		scanf("%lld", &test);

		for (long long i = test + 1; i <= 2*test; i++) {
			for (long int j = 2; j < i; j++) {
				if (i % j == 0) {
					cnt++;
				}
			}
			if (cnt == 0) {
				prime++;
			}
			cnt=0;
		}
		printf("%d \n", prime);
		prime = 0;
	} while (test != 0);
}