#include <stdio.h>
#include <stdlib.h>

long long sum(int *a, int n) {
	long long result = 0;
	for (int i = 0; i < n; i++) {
		result += a[i];
	}
	return result;
}
