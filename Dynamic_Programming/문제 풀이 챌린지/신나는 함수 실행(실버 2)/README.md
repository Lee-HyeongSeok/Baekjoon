## Dynamic Programming 문제 풀이

***

<br> 

#### 신나는 함수 실행

- 현재 재귀 함수의 인자로 주어진 a, b, c에 대한 연산 결과가 존재하면 메모리에서 리턴
- 존재하지 않으면, 재귀 연산들을 계산하고 결과를 메모리에 삽입, 그리고 메모리에서 리턴
- 어차피 최하단 재귀 스택에서 계산되어 올라오는데, 각 재귀 수행 결과는 다른 호출 스택에서 재사용된다.

ex) 2, 2, 2의 경우

1. 가장 하단 조건식에 의해
   - 현재 a, b, c는 2, 2, 2일 때 : (1, 2, 2) + (1, 1, 2) + (1, 2, 1) - (1, 1, 1)이 됨
   - 위 결과에 대한 재귀 중 첫 번째 호출 a, b, c는 (1, 2, 2)일 때 : (0, 2, 2) + (0, 1, 2) + (0, 2, 1) - (0, 1, 1)이 됨
   - 위 결과에 대한 재귀 중 두 번째 호출 a, b, c는 (1, 1, 2)일 때 : (0, 1, 2) + (0, 0, 2) + (0, 1, 1,) - (0, 0, 1)이 됨
   - ...
   - 이렇게 반복했을 때, 위 재귀 호출에서 겹치는 부분은 (0, 1, 2)와 (0, 1, 1)임
2. 이를 반복했을 경우 재귀 호출 스택에서 겹치는 부분이 상당히 많다는 것을 확인 가능함
3. 이는 곧 메모이제이션을 수행하면, 재귀 호출 없이 결과를 반환할 수 있다는 의미



```c++
#include <iostream>

using namespace std;

int dp[21][21][21];

int recursive(int a, int b, int c)
{
    if(a <= 0 || b <= 0 || c <= 0)
    {
        return 1;
    }

    if(a > 20 || b > 20 || c > 20)
    {
        dp[20][20][20] = recursive(20, 20, 20);
        return dp[20][20][20];
    }

    if(dp[a][b][c])
    {
        return dp[a][b][c];
    }

    if(a < b && b < c)
    {
        dp[a][b][c] = recursive(a, b, c-1) + recursive(a, b-1, c-1) - recursive(a, b-1, c);
        return dp[a][b][c];
    }

    dp[a][b][c] = recursive(a-1, b, c) + recursive(a-1, b-1, c) + recursive(a-1, b, c-1) - recursive(a-1, b-1, c-1);
    return dp[a][b][c];
}

int main()
{
    int a, b, c;
    while(true)
    {
        cin >>a>>b>>c;

        if(a == -1 && b == -1 && c == -1)
        {
            break;
        }

        cout<<"w("<<a<<", "<<b<<", "<<c<<") = "<<recursive(a, b, c)<<'\n';
    }
}
```





