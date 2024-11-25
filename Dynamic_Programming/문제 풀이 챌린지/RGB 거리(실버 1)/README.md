## Dynamic Programming 문제 풀이

***

<br> 

#### RGB 거리

- i번째 집을 빨강, 초록, 파랑으로 칠했을 때의 비용의 최소값을 구해야 함
- dp[i]\[0\] : i 번째 집을 빨간색으로 칠했을 때의 최소 비용
- dp[i]\[1\] : i 번째 집을 초록색으로 칠했을 때의 최소 비용
- dp[i]\[2\] : i  번째 집을 파란색으로 칠했을 때의 최소 비용

제시된 조건에 따르면,

dp[i]가 빨간색으로 칠해지기 위해서는 이전 집이 초록색이거나 파란색이어야 함

dp[i]가 초록색으로 칠해지기 위해서는 이전 집이 빨간색이거나 파란색이어야 함

dp[i]가 파란색으로 칠해지기 위해서는 이전 집이 빨간색이거나 초록색이어야 함



```c++
#include <iostream>
#include <algorithm>

using namespace std;

// dp[i][0] : i번째 집을 빨간색으로 칠할 때
// dp[i][1] : i번째 집을 초록색으로 칠할 때
// dp[i][2] : i번째 집을 파란색으로 칠할 때
int dp[1001][3];

int main()
{
    int N = 0;
    int cost[3];
    
    cin >> N;

    for(int i=1; i<=N; ++i)
    {
        cin >> cost[0] >> cost[1] >> cost[2];

        dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + cost[0];
        dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + cost[1];
        dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + cost[2];
    }

    cout<<min(dp[N][0], min(dp[N][1], dp[N][2]));
}
```





