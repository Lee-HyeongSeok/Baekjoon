## Dynamic Programming 문제 풀이

***

<br> 

#### 1, 2, 3 더하기 (Top Down 방식)

- 1, 2, 3으로, 각각 자신을 만들 수 있는 경우의 수를 계산
- 4부터는 1, 2, 3을 각각 사용하여 나올 수 있는 모든 경우의 수를 합하여 계산
- 1, 2, 3 까지는 만들고자 하는 각 숫자의 전 단계의 경우의 수로 이루어짐
- 이를 계속 계산하다보면 다음과 같은 점화식이 도출됨
- dp[N] = dp[N-1] + dp[N-2] + dp[N-3]

ex)

1을 만들 수 있는 경우의 수

-> 1	(1개)

2를 만들 수 있는 경우의 수

-> 1 + 1, 2	(2개)

1 + 1은 숫자를 몇 개 써서 만든 것이 중요한게 아님,

1을 사용해서 2를 만들 수 있는 경우의 수로 생각해야 함

따라서 1을 두개 썼다해서 2를 만들 수 있다는 것이 아닌, 1을 두개 사용해서 2를 만들 수 있는 경우가 1개라는 것으로 생각해야 함

3을 만들 수 있는 경우의 수

-> 1 + 1 + 1, 1 + 2, 2 + 1, 3	(4개)

1 + 1 + 1은 곧 1 + 2 또는 2 + 1을 의미함

1 + 1 + 1을 만들기 위해, 

- 1을 세번 또는 1과 2를 함께 사용 가능하다는 것
- 1을 세번 사용한 것은 : 1과 2를 사용해서 3을 만들 수 있는 경우의 수가, 1을 사용해서 3을 만든 경우의 수를 포함한다는 것
- 1과 2를 함께 사용한 것은 : 1을 사용해서 1을 만들 수 있는 경우의 수 + 2를 사용해서 2를 만들 수 있는 경우의 수
- 따라서 1을 만들 수 있는 경우의 수 1개 + 2를 만들 수 있는 경우의 수 2개 + 3 자체만으로 3을 만들 수 있는 경우의 수 1개 -> 총합 4개

이렇게 하다보면 dp[N] = dp[N-1] + dp[N-2] + dp[N-3] 점화식이 나옴





```c++
#include <iostream>
#include <algorithm>

using namespace std;

int dp[100];


int solve(int N)
{
    if(N <= 1)
    {
        return N;
    }

    if(dp[N] != 0)
    {
        return dp[N];
    }

    dp[N] = solve(N-1) + solve(N-2) + solve(N-3);
    return dp[N];
}

int main()
{
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    int test_case;
    cin>>test_case;

    while(test_case--)
    {
        int N;
        cin >> N;
        solve(N);

        cout<<dp[N]<<'\n';
    }
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