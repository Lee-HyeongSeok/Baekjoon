## Dynamic Programming 문제 풀이

***

<br> 

#### 1로 만들기 (Bottom Up 방식)

- 현재 인덱스를 만들 수 있는 최소 연산 횟수를 계속 저장
- 주어진 N까지 최소 횟수를 만들다보면 답이 나옴

ex)

-1, 나누기 2, 나누기 3으로 1을 사용하여, 현재 인덱스 숫자를 만들 수 있는 최소 횟수를 저장

dp[1]이면, 1을 주어진 연산을 사용해서 1로 만들 수 있는 최소 횟수는 0이다.

아무것도 안해도 만들어지기 때문

dp[2]이면, 2를 -1, /2, /3 연산을 사용해서 1로 만들 수 있는 경우는 아래 두 가지

- 2 - 1
- 2 / 2

이때 점화식은

dp[2] = (dp[2 - 1], dp[2 / 2])

2에서 1을 뺐을 때 결과는 1이며, 1을 만들기 위한 최소 연산 횟수는 0이였고

2에서 2를 나눴을 때 결과는 1이며, 1을 만들기 위한 최소 연산 횟수는 0이였다.

그리고 지금 2에서 1을 만들기 위해 각각 -1, /2 연산을 수행했으므로, 각 결과에 1을 더한 값을 저장해야 하는데, 두 결과 중 가장 작은 값을 저장해야 최소 연산 횟수 전제 조건이 성립한다.

따라서 dp[2]에 대한 최종 점화식은 아래와 같다.

dp[2] = min(dp[2 - 1] + 1, dp[2 / 2] + 1)

이렇게 N까지 구하면 되는데,

문제는 2와 3 둘 다 나눠지는 케이스이다(ex. 6).

이럴 때는 2와 3으로 나눴을 때의 최소 연산 횟수와, -1을 뺐을 때 최소 연산 횟수를 비교하여

가장 작은 값을 넣어준다.

dp[6] = min(dp[6 - 1] + 1, min(dp[6 / 2] + 1), dp[6 / 3] + 1)





```c++
#include <iostream>
#include <algorithm>

using namespace std;

int dp[1000001];

int main()
{
    long long N = 0;
    cin >> N;

    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;

    for(int i=4; i<=N; ++i)
    {
        if(i % 6 == 0) // 2와 3의 최소공배수
        {
            dp[i] = min(dp[i - 1] + 1, min(dp[i / 2] + 1, dp[i / 3] + 1));
        }
        else if(i % 2 == 0)
        {
            dp[i] = min(dp[i - 1] + 1, dp[i / 2] + 1);
        }
        else if(i % 3 == 0)
        {
            dp[i] = min(dp[i - 1] + 1, dp[i / 3] + 1);
        }
        else
        {
            dp[i] = dp[i - 1] + 1;
        }
    }

    cout<<dp[N];
}
```



#### 1로 만들기(Top down 방식)

- 위와 비슷한 방식이다.
- 이번에는 반대로 주어진 숫자를 기준으로,
  - -1을 했을 때 최소 연산 횟수
  - 나누기 2를 했을 때 최소 연산 횟수
  - 나누기 3을 했을 때 최소 연산 횟수
  - -1, 나누기 2, 3을 했을 때 최소 연산 횟수
- 를 각각 최 하단에서부터 계산하여 올라오는 방식이다.
- 예를 들어 N이 10이라면,
  - 호출 스택은 결국 N이 1, 2, 3일 때부터 계산되어
  - N이 4, 5, 6, ... 10 까지 올라오면서 자연스럽게 이전 계산 결과를 사용하게 된다. 



```c++
#include <iostream>
#include <algorithm>

using namespace std;

int dp[1000001];

int dfs(int n)
{
    if(n <= 1)
    {
        return n;
    }

    if(dp[n] != 0)
    {
        return dp[n];
    }

    if(n % 6 == 0) // 2와 3의 최소공배수 6
    {
        dp[n] = min(dfs(n-1) + 1, min(dfs(n / 2) + 1, dfs(n / 3) + 1));
    }
    else if(n % 2 == 0)
    {
        dp[n] = min(dfs(n-1) + 1, dfs(n/2) + 1);
    }
    else if(n % 3 == 0)
    {
        dp[n] = min(dfs(n-1) + 1, dfs(n/3) + 1);
    }
    else
    {
        dp[n] = dfs(n-1) + 1;
    }

    return dp[n];
}

int main()
{
    int N = 0;
    cin >> N;

    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;

    dfs(N);

    cout<<dp[N];
}
```



#### 다른 풀이 참고

- 현재 숫자는 -1을 통해 무조건 1로 만들 수 있고
- 2와 3으로 나누어 지는 숫자가 있는 경우, 2로 나누어 1로 만들었을 때의 결과와 3으로 나누어 1로 만들었을 때 결과를 비교해주면 된다.
- 따라서 -1을 통해 무조건 1로 만드는 행위는 무조건 선행 시키고, 2와 3을 통한 연산은 순차적으로 진행해주면 된다.

아래는 개선된 코드(Bottom up)

```c++
#include <iostream>
#include <algorithm>

using namespace std;

int dp[1000001];

int main()
{
    long long N = 0;
    cin >> N;

    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;

    for(int i=4; i<=N; ++i)
    {
        dp[i] = dp[i - 1] + 1;

        if(i % 2 == 0)
        {
            dp[i] = min(dp[i], dp[i / 2] + 1);
        }

        if(i % 3 == 0)
        {
            dp[i] = min(dp[i], dp[i / 3] + 1);
        }
    }

    cout<<dp[N];
}
```





아래는 개선된 코드(Top down)

```c++
#include <iostream>
#include <algorithm>

using namespace std;

int dp[1000001];

int dfs(int n)
{
    if(n <= 1)
    {
        return n;
    }

    if(dp[n] != 0)
    {
        return dp[n];
    }

    dp[n] = dfs(n-1) + 1;

    if(n % 2 == 0)
    {
        dp[n] = min(dfs(n), dfs(n / 2) + 1);
    }

    if(n % 3 == 0)
    {
        dp[n] = min(dfs(n), dfs(n / 3) + 1);
    }

    return dp[n];
}

int main()
{
    int N = 0;
    cin >> N;

    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;

    dfs(N);

    cout<<dp[N];
}
```


***

#### 참조

- https://velog.io/@matcha_/BOJ-%EB%B0%B1%EC%A4%80-1463-CDP