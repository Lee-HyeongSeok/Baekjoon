#include <stdio.h>

#define MAX 15

int main() {
	char alpha[26];
	char dial[MAX];

	for (int i = 0; i < 26; i++) {
		alpha[i] = (char)(i + 65);
	}
	
	scanf("%s", dial);
	
	char temp;
	int sec = 0;

	for (int i = 0; i < MAX; i++) {
		temp = dial[i];

		switch (temp) {
		case 'A':
		case 'B':
		case 'C': 
			sec += 3;
			break;

		case 'D':
		case 'E':
		case 'F':
			sec += 4;
			break;
			
		case 'G':
		case 'H':
		case 'I':
			sec += 5;
			break;

		case 'J':
		case 'K':
		case 'L':
			sec += 6;
			break;
			
		case 'M':
		case 'N':
		case 'O':
			sec += 7;
			break;

		case 'P':
		case 'Q':
		case 'R':
		case 'S':
			sec += 8;
			break;

		case 'T':
		case 'U':
		case 'V':
			sec += 9;
			break;

		case 'W':
		case 'X':
		case 'Y':
		case 'Z':
			sec += 10;
			break;

		default :
			printf("%d", sec);
			return 0;
		}
	}
}