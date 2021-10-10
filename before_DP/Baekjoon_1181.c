#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
	int test = 0;
	scanf("%d", &test);

	// �ܾ �����ϱ� ���� 2���� �迭
	char **arr;
	arr = (char**)malloc(sizeof(char*) * test);
	for (int i = 0; i < test; i++) {
		arr[i] = (char*)malloc(sizeof(char) * 51);
	}

	for (int i = 0; i < test; i++) {
		scanf("%s", arr[i]);
	}
	
	
	// ���ĵ� �ܾ �����ϱ� ���� �����Ҵ�
	
	
	char *temp = NULL;

	printf("*************************************\n");
	for (int i = 0; i < test-1; i++) {
		for (int j = i + 1; j < test; j++) {
			if (strlen(arr[i]) > strlen(arr[j])) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
				temp = NULL;
			}
		}
	}
	


	// ���� ���� ������ ����
	
	int size = 0;
	temp = NULL; // ��ȯ�� ���� ����

	for (int i = 0; i < test - 1; i++) {
		for (int j = i + 1; j < test; j++) {
			// ���̰� ���� ��
			if (strlen(arr[i]) == strlen(arr[j])) {
				size = strlen(arr[i]);
				
				// ��, �� �ܾ� �� ���ھ� ���Ѵ�.
				for (int z = 0; z < size; z++) {

					// ù ���ڰ� �� ũ�� ����
					if (arr[i][z] > arr[j][z]) {
						temp = arr[i];
						arr[i] = arr[j];
						arr[j] = temp;
						temp = NULL;
						break;
				
					} // ù ���ڰ� �� �۰ų� ������ �ݺ��� Ż��
					else {
						break;
					}
				}
			}
		}
	}
	
	// �ߺ��� �����ϱ� ���� ǥ��
	int *rank = (int*)malloc(sizeof(int)*test);
	// ��� ���� 0���� ó��
	for (int i = 0; i < test; i++) {
		rank[i] = 0;
	}

	// �ߺ��Ǵ� �κ��� ����
	for (int i = 0; i < test - 1; i++) {
		for (int j = i + 1; j < test; j++) {
			// ���̰� ����, �ڽ��� ���� �ܾ ���� ���� ��
			if ((strlen(arr[i]) == strlen(arr[j])) && !memcmp(arr[i], arr[j], strlen(arr[i]))) {
				rank[j] = 1; // ���� �ڽ��� �ߺ��Ǵ� ���̱� ������ ���� ǥ��
			}
		}
	}
	for (int i = 0; i < test; i++) {
		// �ߺ����� ǥ�ð� �ȵ� �κи� ���
		if (!rank[i]) {
			printf("%s\n", arr[i]);
		}
	}
	
	// 2���� �迭, 1���� �迭 �޸� ����
	for (int i = 0; i < test; i++) {
		free(arr[i]);
	}

	free(rank);
	free(arr);
}