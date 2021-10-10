#include <stdio.h>

int main() {
	int x, y, w, h;
	scanf("%d %d %d %d", &x, &y, &w, &h);
	int min = 0;
	if (w - x <= h - y) {
		if (w - x < x)
			min = w - x;
		else
			min = x;
	}
	else {
		if (h - y < y)
			min = h - y;
		else
			min = y;
	}
	printf("%d", min);
}