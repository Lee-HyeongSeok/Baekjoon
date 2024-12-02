## Dynamic Programming 문제 풀이

***

<br> 

#### 포도주 시식

- 연속으로 놓여 있는 3잔을 마실 수 없는 조건을 통해 점화식을 세워야 함
- 현재 잔을 선택했을 때의 기준으로는
  - 바로 왼쪽에 있는 잔을 선택했을 때 + 현재 잔 기준으로 연속되지 않는 잔 중에 선택했을 때 가질 수 있는 최대 용량
  - 바로 왼쪽에 있는 잔을 선택하지 않았을 때 연속되지 않는 잔 중에 선택했을 때 가질 수 있는 최대 용량
- 현재 잔을 선택하지 않았을 때의 기준으로는
  - 바로 왼쪽에 있는 잔을 선택했을 때 여태까지 얻을 수 있는 최대 용량



바로 왼쪽에 있는 잔을 선택했을 경우)

- 현재 잔을 포함하므로 sequence[index]
- 바로 왼쪽에 있는 잔을 선택했으므로 sequence[index - 1]
- 연속되지 않는 잔 중에 선택이 가능하며, 가질 수 있는 최대 용량이 저장되어 있는 것을 선택한다면 dp[index - 3]

바로 왼쪽에 있는 잔을 선택하지 않았고 연속되지 않는 잔 중에 선택했을 때 가질 수 있는 최대 용량)

- 현재 잔을 포함하므로 sequence[index]
- 연속되지 않는 잔 중에 선택이 가능하며, 가질 수 있는 최대 용량이 저장되어 있는 것을 선택한다면 dp[index - 2]

현재 잔을 선택하지 않았을 경우)

- 현재 잔을 선택하지 않았으므로
- 현재 기준으로 선택 가능한 왼쪽 최대 용량중, 가장 큰 값을 가지고 있을 dp[index - 1]

위 세 가지 경우 중에, 가장 큰 값을 현재 dp 배열에 저장하면 끝





```c++
#include <iostream>
#include <algorithm>

#include <vector>

using namespace std;

int dp[10001];
int sequence[10001];

int main()
{
    int N;

    cin>>N;

    for(int i=0; i<N; ++i)
    {
        cin >> sequence[i];
    }

    dp[0] = sequence[0];
    dp[1] = sequence[0] + sequence[1];

    for(int i=2; i<N; ++i)
    {
        dp[i] = max(dp[i - 3] + sequence[i - 1] + sequence[i], max(dp[i - 2] + sequence[i], dp[i - 1]));
    }

    cout<<dp[N-1];
}
```





