## Dynamic Programming 문제 풀이

***

<br> 

#### 설탕 배달

- 18 kg을 기준으로, 3kg과 5kg 각각 운반했을 때 나올 수 있는 경우의 수를 저장
- 즉, 현재 인덱스는 3kg과 5kg으로 만들 수 있는 무게를 뜻함

![dp1](https://github.com/user-attachments/assets/3ae27bf6-6400-4931-a63e-9133a951b4e2)

처음에 leaf 노드를 초기화 해줌

dp[3] = 1, dp[5] = 1

그리고 6부터 N까지 증가하면서, 각 인덱스에 해당하는 값을 최신화 시켜주면 되는데,

여기서 인덱스는 3, 5kg으로 만들 수 있는 무게를 뜻하고, 값은 봉지 개수를 뜻한다.

- 위 초기화 식에서는 3kg을 만들기 위해 봉지 1개, 5kg을 만들기 위해 봉지 1개가 필요하다는 뜻

이때 3kg 봉지부터 최신화를 시켜준 다음, 5kg 봉지로 가능한 개수로 최신화를 한 번 더 시켜줘야 하는데,

- 3kg보다 5kg 봉지로 운반하는게 더 개수가 적기 때문



```c++
#include <iostream>
#include <algorithm>

using namespace std;

int dp[5001];

int main()
{
    int N = 0;
    cin>>N;

    dp[3] = 1;
    dp[5] = 1;

    for(int i=6; i<=N; ++i)
    {
        if(dp[i - 3] > 0)
        {
            dp[i] = dp[i - 3] + 1;
        }

        if(dp[i - 5] > 0)
        {
            dp[i] = dp[i - 5] + 1;
        }
    }

    if(dp[N] > 0)
    {
        cout<<dp[N];
    }
    else
    {
        cout<<-1;
    }
}
```





