## Dynamic Programming 문제 풀이

***

<br> 

#### 가장 긴 증가하는 부분 수열

- 현재 위치를 기준으로, 이전 원소들을 탐색한다(2차원)
- 이전 원소 중에 현재 위치에 있는 숫자보다 작은 숫자가 있는 경우
  - 해당 숫자가 가진 수열의 길이와 현재 위치가 가진 수열의 길이 중 가장 긴 것으로 업데이트
  - 왜냐면 위 작업을 반복하다보면, 현재 위치 기준으로 부분 수열이 될 수 있는 숫자들마다 각각 가장 긴 길이를 가지고 있을 것임
  - 따라서 이전 부분 수열이 가진 길이 + 1과 현재 위치가 가진 부분 수열 길이를 비교해서 업데이트 해주면 됨



{10, 20, 10, 30, 40} 의 경우

현재 위치가 20이라면

- 0번 인덱스에 존재하는 10이 가진 가장 긴 부분 수열 + 1과 현재 위치가 가진 부분 수열 1을 비교
- 전자가 더 크므로, 10이 가진 부분 수열 길이 + 1을 업데이트

현재 위치가 30이라면

- 0번 인덱스에 존재하는 10이 가진 가장 긴 부분 수열 + 1과 현재 위치가 가진 부분 수열 1을 비교
- 전자가 더 커서 전자의 경우로 업데이트
- 그리고 1번 인덱스에 존재하는 20이 가진 가장 긴 부분 수열 + 1과 현재 위치가 가진 부분 수열 1을 비교
- 전자가 더 커서 전자의 경우로 업데이트

이를 반복



```c++
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 1001;

int dp[MAXN];
int sequence[MAXN];

void solve(int N)
{
    int answer = 0;

    for(int i=0; i<N; ++i)
    {
        dp[i] = 1;

        for(int j=0; j<i; ++j)
        {
            if(sequence[i] > sequence[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        
        answer = max(dp[i], answer);
    }

    cout<<answer;
}

int main()
{
    int T = 0;
    cin>>T;

    for(int i=0; i<T; ++i)
    {
        cin >> sequence[i];
    }

    solve(T);
}
```





