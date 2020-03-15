#include <stdio.h>

int main() {
	int val1 = 5;
	int val2 = 3;
	int num = 0;
	scanf("%d", &num);

	int sum = 0;
	int div = 0;

	if (num < val1) {
		printf("-1");
		return 0;
	}
	
	else if (num > val1) {
		sum = num / val1;
		div = num % val1;
	}
	
	if ((div%val2) > 0) {
		sum += (div / val2) + 1;
	}
	else if((div%val2) == 0){
		sum += div / val2;
	}
	
		
	
	printf("%d", sum);

}