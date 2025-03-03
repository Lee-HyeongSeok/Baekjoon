## Dynamic Programming 문제 풀이

***

<br> 

#### 피보나치 수

- N이 90의 경우 피보나치 수는 2,880,067,194,370,816,120가 된다.
- 이는 INT형의 범위를 훨씬 넘어선다.
- 따라서 계산되는 데이터 타입을 long long 타입으로 해줘야 통과한다.
- 하지만 해당 문제에서는 N이 45 이므로, 이때 피보나치 수는 1,134,903,170 이다.
- 그리고 INT형의 범위는 -2,147,483,648 ~ 2,147,483,647 이므로, 최대 피보나치 수는 INT형의 범위 내에 있다.
- 따라서 DP를 INT로 선언해도 된다.



```c++
#include <iostream>

using namespace std;

int dp[46];

int solve(int N)
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

    solve(N);

    cout << dp[N] << '\n';
}
```





