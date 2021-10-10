#include <stdio.h>

int Fibo(int num) {
	if (num <= 1)
		return 0;
	else if (num == 2)
		return 1;
	return Fibo(num - 1) + Fibo(num - 2);
}
int main() {
	int a=0, b=1;
	int n = 0;
	scanf("%d", &n);
	
	printf("%d", Fibo(n+1));
}