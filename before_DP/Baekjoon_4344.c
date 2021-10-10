#include <stdio.h>
#include <stdlib.h>

int main() {
	int size = 0; // test 개수
	int V_size = 0; // 점수를 받기 위한 변수
	double sum = 0;
	double aver = 0;
	int cnt = 0;

	scanf("%d", &size);

	double *result = (double*)malloc(sizeof(double)*size);

	// 입력된 테스트 수만큼 loop
	for (int i = 0; i < size; i++) {
		scanf("%d", &V_size); // 점수의 개수 입력 받음
		
		// 각 점수의 개수마다 점수를 입력 받기위한 배열
		double *V_Result = (double*)malloc(sizeof(double)*V_size);

		// 점수를 입력 받는다.
		for (int j = 0; j < V_size; j++) {
			scanf("%lf", &V_Result[j]);

			// 입력 받음과 동시에 sum변수에 더해짐, 평균을 구하기 위함
			sum += V_Result[j];
		}
		aver = sum / (double)V_size; // 평균 값

		// 평균보다 큰 점수가 있을 때 마다 cnt 값 증가
		for (int j = 0; j < V_size; j++) {
			if (V_Result[j] > aver)
				cnt++;
		}
		// result 배열에 비율 저장
		result[i] = ((double)cnt / (double)V_size) * 100;

		sum = 0;
		V_size = 0;
		aver = 0;
		cnt = 0;
		// 테스트 케이스마다 동적할당을 위해 끝에서 해제해준다.
		free(V_Result);
	}

	for (int i = 0; i < size; i++) {
		printf("%.3lf%% \n", result[i]);
	}

	free(result);
}