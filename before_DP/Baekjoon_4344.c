#include <stdio.h>
#include <stdlib.h>

int main() {
	int size = 0; // test ����
	int V_size = 0; // ������ �ޱ� ���� ����
	double sum = 0;
	double aver = 0;
	int cnt = 0;

	scanf("%d", &size);

	double *result = (double*)malloc(sizeof(double)*size);

	// �Էµ� �׽�Ʈ ����ŭ loop
	for (int i = 0; i < size; i++) {
		scanf("%d", &V_size); // ������ ���� �Է� ����
		
		// �� ������ �������� ������ �Է� �ޱ����� �迭
		double *V_Result = (double*)malloc(sizeof(double)*V_size);

		// ������ �Է� �޴´�.
		for (int j = 0; j < V_size; j++) {
			scanf("%lf", &V_Result[j]);

			// �Է� ������ ���ÿ� sum������ ������, ����� ���ϱ� ����
			sum += V_Result[j];
		}
		aver = sum / (double)V_size; // ��� ��

		// ��պ��� ū ������ ���� �� ���� cnt �� ����
		for (int j = 0; j < V_size; j++) {
			if (V_Result[j] > aver)
				cnt++;
		}
		// result �迭�� ���� ����
		result[i] = ((double)cnt / (double)V_size) * 100;

		sum = 0;
		V_size = 0;
		aver = 0;
		cnt = 0;
		// �׽�Ʈ ���̽����� �����Ҵ��� ���� ������ �������ش�.
		free(V_Result);
	}

	for (int i = 0; i < size; i++) {
		printf("%.3lf%% \n", result[i]);
	}

	free(result);
}