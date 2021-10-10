#include <stdio.h>
#include <stdlib.h>

int main() {
	int size = 0;
	int han_number = 0;
	int arr[3];
	int num = 100;
	int using_num = 0;

	scanf("%d", &using_num);

	for (int i = 0; i <= using_num; i++) {
		if (0 < i && i < 100)
			han_number = i;
		else if(i >= 100){
			size = i;
			num = 100;
			for (int j = 0; j < 3; j++) {
				arr[j] = size / num;
				size = size % num;
				num /= 10;
			}
			if (arr[0] - arr[1] == arr[1] - arr[2])
				han_number++;
		}
	}
	printf("%d", han_number);
}