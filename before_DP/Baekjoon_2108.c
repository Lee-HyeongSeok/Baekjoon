#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define SWAP(a, b){int t=a; a=b; b=t;}

int partition(int *list, int left, int right) {
	int pivot;
	int low, high;

	low = left;
	high = right + 1;
	pivot = list[left];

	do {
		do {
			low++;
			// low�� left�� ����
			// low�� right���� �۰�, list[low] �� pivot, �� list[left]���� ���� ��
		} while (low <= right && list[low] < pivot);
		do {
			high--;
			// high�� right+1�� ����
			// high�� left���� ũ�ų� ����, list[high]�� pivot���� Ŭ ��
			// pivot�� list[left], ���� ��Ƽ�ǿ� �ڽŰ��� �񱳴�󺸴� Ŭ ��
			// high�� ���ҽ�Ų��. (�������� ���Ļ� �� ū ���� �����ʿ� �ֱ� ����)
		} while (high >= left && list[high] > pivot);

		// �� ���ǵ��� �������� �ʾ��� ��
		// ���� ��Ƽ���� ���� ������ ��Ƽ���� �ڽ��� ¦ ���� Ŭ ��
		if (low < high) // low�� high�� ���� �ʾ��� ��
			SWAP(list[low], list[high]); // �ٲ۴�.

	} while (low < high);// low�� high ���� �۾ƾ� �ϱ� ����
	
	SWAP(list[left], list[right]);

	return high;
}

void quick_sort(int *list, int left, int right) {
	if (left < right) {
		int q = partition(list, left, right);
		quick_sort(list, left, q - 1);
		quick_sort(list, q + 1, right);
	}
}
int main() {
	int test = 0; // �׽�Ʈ ���̽� ���� �Է�
	scanf("%d", &test);

	int sum = 0;
	// ���� �Է� �ޱ�
	int *arr = (int*)malloc(sizeof(int)*test);
	for (int i = 0; i < test; i++) {
		scanf("%d", &arr[i]);
		sum += arr[i]; // ����� ���ϱ� ���� �Է� ���� ���Ѵ�.
	}
	// ��� ���
	printf("%d \n", sum / test);
	
	// ���� ������ �̿��� ����
	for (int i = 0; i < test - 1; i++) {
		for (int j = i + 1; j < test; j++) {
			if (arr[i] > arr[j])
				SWAP(arr[i], arr[j]);
		}
	}
	// �� ������ �̿��� ����
	// quick_sort(arr, 0, test-1);

	
	// �߾Ӱ��� ���� index�� �� ���� �̸� ���Ѵ�.
	int mid = test / 2;
	printf("%d \n", arr[mid]);

	int cnt = 1;
	int max = 0; // �ֺ��� ã������ ����
	int head = 0; // �ش� �ֺ��� index�� ����ϱ� ���� ����
	
	for (int i = 0; i < test; i++) {
		for (int j = 0; j < test; j++) {
			// �ڱ� �ڽ��� ����
			if (i != j) {
				// �ڽŰ� ���� ���� ã����
				if (arr[i] == arr[j]) {
					cnt++;
				}
			}
		}
		// �ֺ� �� ���� ū ���� ã������ ����
		if (max <= cnt) {
			max = cnt;
			head = i; // �ش� ���� �ε����� ����
		}
		cnt = 1; // �󵵸� ī��Ʈ�� �� �ٽ� 1�� �ʱ�ȭ
	}

	// �ּ� �󵵴� 1�̹Ƿ� 2�̻��� ��
	// �� Ȯ���ϰԴ� �迭�ϳ� ���� �� ���� ������ �� ��� ���
	if (max >= 2)
		printf("%d\n", arr[head]);
	else
		printf("%d\n", arr[1]);

	int range_max = arr[0];
	int range_min = arr[0];
	for (int i = 1; i < test; i++) {
		// �ִ밪�� ���ϴ� ����
		if (range_max < arr[i])
			range_max = arr[i];
		// �ּҰ��� ���ϴ� ����
		if (range_min > arr[i])
			range_min = arr[i];
	}

	// ���� = �ִ� - �ּҰ�
	printf("%d\n", range_max - range_min);

	free(arr);
}