## Dynamic Programming 문제 풀이

***

<br> 

#### 다리 놓기

- 조합 문제
- N개의 사이트가 항상 일정한 순서대로 M개의 사이트와 연결되어야 해서, 순서를 고려하지 않는 경우의 수만 구하면 된다.
- 동쪽 사이트의 개수 중 서쪽 사이트의 개수를 선택하는 것
  - nCM이 된다.



```c++
#include <iostream>
#include <algorithm>

#include <vector>

using namespace std;

int main()
{
    int T;
    int N, M;

    cin >> T;
    while(T--)
    {
        cin >> N >> M;

        int k=1, result = 1;

        for(int j=M; j>M-N; j--)
        {
            result = result * j;
            result = result / k;
            k++;
        }

        cout<<result<<'\n';
    }
}
```





