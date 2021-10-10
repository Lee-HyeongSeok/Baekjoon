## DP : Dynamic Programming

***

<br> 

### :pushpin: 동적 프로그래밍(DP: Dynamic Programming)

- 큰 문제를 작은 문제로 나누어 해결하는 방법
- 큰 문제를 작은 문제로 분할하여 기억해 놓고 그 보다 더 큰 문제를 해결할 때<br> 기존에 기억해 놓은 메모리를 참조하는 방식
- **메모이제이션(Memoization)** 사용
  - 프로그램이 동일한 계산을 반복할 때 이전에 계산한 값을 메모리에 저장함으로써<br> 동일한 계산의 반복 수행을 제거, 실행 속도를 향상 
- Bottom-up과 Top-down 방식으로 나뉨



### :pushpin: 동적 프로그래밍 Top-down 방식

- 큰 문제를 작은 문제로 분할하며 메모에 계산된 값이 있으면 호출하는 방식
- 재귀로 얻을 수 있는 값과 메모리에서 불러올 수 있는 값으로 크게 나뉨
- 숫자가 커지면 공간 복잡도가 지수적으로 증가하기 때문에 스택 오버플로우가 발생 

```c
int memo[100]{};

int fibonacci(int n){
    if(n <= 1) // 0번째, 1번째 피보나치 수
        return n;
    if(memo[n] != 0) // 메모가 존재하는지 확인(0이 아니면 메모리가 어디선가 사용됐던 것)
        return memo[n];
    memo[n] = fibonacci(n-1)+fibonacci(n-2); // 메모리에 존재하지 않으면 직접 쓴다.
    return memo[n];
}

// 출처 : https://namu.wiki/w/%EB%8F%99%EC%A0%81%20%EA%B3%84%ED%9A%8D%EB%B2%95
```

<br>

### :pushpin: 동적 프로그래밍 Bottom-up 방식

- 작은 문제에서 시작하여 작은 문제를 점점 쌓아 큰 문제를 해결하는 방식

```c
int memo[100] = {1, 1}; // 미리 작은 문제의 값을 메모리에 지정 
int fibonacci(int n){
    if(memo[n-1] == 0){
        for(int i=2; i<n; ++i){
            // 메모리에 저장된 값으로 현재 메모리의 값인 memo[i]를 구한다.
            memo[i] = memo[i-1]+memo[i-2];
        }
    }
    return memo[n-1];
}
```



<br>



### :pushpin: 동적 프로그래밍 - 피보나치 예시

![Untitled Diagram](https://user-images.githubusercontent.com/55940552/136701683-dc567973-a502-4381-a484-be1f1d636cf4.png) 