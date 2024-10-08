## Dynamic Programming 문제 풀이

***

<br> 

#### 부녀회장이 될테야

- 0층에 사는 사람들은 1부터 14까지 순차적인 인원수를 가짐
- 1층부터 내 왼쪽과 바로 밑에 층 같은 호수에 사는 사람의 인원 수를 더하면 현재 내가 구하고자 하는 호수가 나옴
- DP로 풀려면 2차원 배열에 인원 수 모두 채우고, 내가 구하고자 하는 호수를 인덱싱하면 되는데
- 층 수가 최대 몇층인줄도 모르고, 불필요한 계산도 필요하기 때문에 그냥 재귀로 풀이

solve(k-1, n)은 내 바로 아랫층 같은 호수 사는 사람들의 인원 수를 의미함

solve(k, n-1)은 나랑 같은층 사는 바로 왼쪽 호수 사람들의 인원 수를 의미함

0층부터 2층 3호까지 나열해놓고 보면,

- 내 바로 왼쪽 호수 집의 인원 수가 바로 밑에 층 해당 집과 같은 호수 인원 수 까지 더한 것이기 때문
- 거기다 내 바로 밑에 층 사람들 인원 수를 더하면, 현재 내가 구하고자 하는 우리집 호수에 수용 인원 수가 나옴



```c++
#include <iostream>
#include <algorithm>

using namespace std;

int solve(int k, int n)
{
    // 1호는 무조건 1사람만 들어가기 때문에 1 리턴
    if(n == 1)
    {
        return 1;
    }
	
    // 0층은 무조건 n명의 사람만 들어가기 때문에 n 리턴
    if(k == 0)
    {
        return n;
    }

    return solve(k-1, n) + solve(k, n-1);
}

int main()
{
    int T;
    cin>>T;

    while(T--)
    {
        int k, n;
        cin>>k>>n;
        cout<<solve(k, n)<<'\n';
    }
}
```





