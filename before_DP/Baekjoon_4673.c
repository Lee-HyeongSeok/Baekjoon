#include <stdio.h>

int SelfNumber(int n) {
	int sum = 0;
	int temp = n;
	if (n > 10000) {
		sum += temp / 10000;
		temp = temp % 10000;
	}
	if (n > 1000) {
		sum += temp / 1000;
		temp %= 1000;
	}
	if (n > 100) {
		sum += temp / 100;
		temp %= 100;
	}
	if (n >= 10) {
		sum += temp / 10;
		temp %= 10;
	}
	sum = sum + n + temp;
	return sum;
}
int main() {
	int arr[10000] = { 0 };
	int n = 0;
	int cnt = 0;

	for (int i = 0; i < 10000; i++) {
		arr[i] = SelfNumber(i+1);
	}
	for (int i = 0; i <= 10000; i++) {
		n = i+1;
		for (int j = 0; j < 10000; j++) {
			if (n == arr[j]) {
				cnt++;
			}
		}
		if (cnt == 0) {
			printf("%d\n", n);
		}
		else {
			cnt = 0;
		}
	}
	
}