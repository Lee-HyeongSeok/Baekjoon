## Dynamic Programming 문제 풀이

***

<br> 

#### 연속합

- (직전 연속합 결과 + 현재 값), 현재 값을 비교했을 때 더 큰 값으로 현재 메모리를 초기화
- 이렇게 되면, 연속된 숫자의 합산 결과를 2중 루프 없이 기억 할 수 있음

예제 예시)

5

-1 -2 -3 -4 -5 가 주어졌을 때

dp[0]에는 당연히 0이 존재하는 상태, 그리고 dp의 초기화는 1부터 시작하면 된다

왜냐하면 dp[0]은 어차피 가장 첫 번째 숫자니까..



* dp[1]을 구하는 경우

(dp[1 - 1] + 현재 값 -1)과 현재 값 -1을 비교하여 더 큰 값을 도출 -> -1

따라서 dp[1]에는 -1이 들어감

* dp[2]를 구하는 경우

(dp[2 - 1] + 현재 값 -2)와 현재 값 -2를 비교하여 더 큰 값을 도출 -> -2



위를 반복하면서 최대 값을 계속 갱신해줌



```c++
#include <iostream>
#include <algorithm>

#include <vector>

using namespace std;

int dp[100001];
int sequence[100001];

int main()
{
    int N;

    cin >> N;

    for(int i=0; i<N; ++i)
    {
        cin >> sequence[i];
    }

    int max_number = sequence[0];
    dp[0] = sequence[0];

    for(int i=1; i<N; ++i)
    {
        dp[i] = max(dp[i - 1] + sequence[i], sequence[i]);

        max_number = max(max_number, dp[i]);
    }

    cout<<max_number;
}
```





