## Dynamic Programming 문제 풀이

***

<br> 

#### 포도주 시식

- 일반적으로 알고 있는 피보나치 수(DP 버전)으로 풀면 틀린다.
- 이유는, N이 최대 90인 것에 있는데
- N이 90의 경우 피보나치 수는 2,880,067,194,370,816,120가 된다.
- 이는 INT형의 범위를 훨씬 넘어선다.
- 따라서 계산되는 데이터 타입을 long long 타입으로 해줘야 통과한다.



```c++
#include <iostream>
#include <algorithm>

long long dp[100];

using namespace std;

long long solve(int N)
{
    if(N <= 1)
    {
        return N;
    }
    
    if(dp[N])
    {
        return dp[N];
    }
    
    dp[N] = solve(N - 1) + solve(N - 2);
    return dp[N];
}

int main()
{
    int N;
    cin >> N;
    
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;
    
    cout<< solve(N);
}
```





