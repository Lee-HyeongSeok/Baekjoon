#include <stdio.h>

#define MAX 100

int main() {
	int mult = 6;
	int check_num = 0;
	int result = 7;

	scanf("%d", &check_num);

	for (int i = 2; i < MAX; i++) {
		if (result >= check_num) {
			printf("\n%d", (mult / 6) + 1);
			break;
		}
		else if (result <= check_num) {
			mult = mult * i;
			result = result + mult;
			break;
		}
		else if (check_num == 1) {
			printf("\n1");
			break;
		}
	}
}