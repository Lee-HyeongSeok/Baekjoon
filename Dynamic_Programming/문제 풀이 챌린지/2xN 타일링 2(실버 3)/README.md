## Dynamic Programming 문제 풀이

***

<br> 

#### 연속합

- N이 1부터 5까지일 때, 경우의 수를 구하면 규칙을 알 수 있음
- dp[N] = dp[N - 1] + dp[N - 2] * 2 의 규칙을 찾아야 함

예제 예시)

N = 1일 때, 2x1 타일링

경우의 수는 1개



N = 2일 때, 2x2 타일링

2x2 타일을 하나만 사용하는 경우

1x2 타일과 1x2 타일을 더하는 경우

2x1 타일과 2x1 타일을 더하는 경우

총 경우의 수는 3개

--- 여기까지는 규칙이 존재하지 않음

N = 3일 때, 2x3 타일링

2x2 타일에 2x1 타일을 더하는 경우

2x1 타일에

- 2x2 타일을 더하는 경우
- 1x2 타일을 두 개 더하는 경우

위에서 2x2 타일의 경우는 N이 2일 때를 의미함

위에서 2x1 타일의 경우는 N이 1일 때를 의미함

따라서 점화식을 세우면,

dp[3] = dp[3 - 1] + dp[3 - 2] * 2가 되고

이를 일반화 하면

dp[N] = dp[N - 1] + dp[N - 2] * 2가 된다.



```c++
#include <iostream>
#include <algorithm>

#include <vector>

using namespace std;

int dp[1001];

int dfs(int N)
{
    if(N <= 1)
    {
        return 1;
    }

    if(dp[N] != 0)
    {
        return dp[N];
    }

    dp[N] = (dfs(N - 1) + dfs(N - 2) * 2) % 10007;
    return dp[N];
}

int main()
{
    int N;

    cin>>N;

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 3;

    cout<< dfs(N);
}
```





