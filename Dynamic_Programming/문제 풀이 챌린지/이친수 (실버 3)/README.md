## Dynamic Programming 문제 풀이

***

<br> 

#### 이친수

- 각 자리수 변화에 따른 개수를 세다보면, 피보나치 수와 동일한 흐름의 규칙을 가진 것을 알게됨

N이 1일 때,

- 1

1개 발생



N이 2일 때,

- 10

1개 발생



N이 3일 때,

- 100
- 101

2개 발생



N이 4일 때,

- 1000
- 1001
- 1010

3개 발생



N이 5일 때,

- 10000
- 10001
- 10010
- 10100
- 10101

5개 발생



N이 6일 때,

- 100000
- 100001
- 100010
- 100100
- 100101
- 101000
- 101001
- 101010

8개 발생,

이를 종합해보면

1, 1, 2, 3, 5, 8, 13... 

피보나치수와 같음



하지만 주의점은, 

N이 90이므로, 이때 피보나치 수는 int 형 범위를 넘음



```c++
#include <iostream>
#include <algorithm>

long long dp[91];

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
    
    solve(N);

    cout<<dp[N]<<'\n';
}
```





