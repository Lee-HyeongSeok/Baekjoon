#include <iostream>
#include <vector>
using namespace std;

int main() {
	char arr1[5];
	char arr2[5];

	scanf("%s", arr1);
	scanf("%s", arr2);

	char temp_arr[3];
	char temp_arr1[3];
	int cnt = 2;

	// null값을 거르면서 거꾸로 값을 입력
	for (int i = 0; i < 5; i++) {
		if (arr1[i] >= '1' || arr1[i] <= '9') {
			if (cnt < 0) {
				break;
			}
			temp_arr[cnt--] = arr1[i];
		}
	}
	cnt = 2;
	// null값을 거르면서 거꾸로 값을 입력
	for (int i = 0; i < 5; i++) {
		if (arr2[i] >= '1' || arr2[i] <= '9') {
			if (cnt < 0)
				break;
			temp_arr1[cnt--] = arr2[i];
		}
	}
	if (temp_arr[0] > temp_arr1[0]) {
		for (int i = 0; i < 3; i++) {
			printf("%c", temp_arr[i]);
		}
	}
	else {
		for (int i = 0; i < 3; i++) {
			printf("%c", temp_arr1[i]);
		}
	}


	
}