## Dynamic Programming 문제 풀이
***

#### 구간 합 구하기 5
  - 주어진 map에서 각 구간마다 가져야 하는 누적 합을 미리 계산
  - 계산을 완료하면, 
    - (구해야 하는 최대 구간 합 - 빼야 하는 구간 합 + 중복으로 제거된 구간 합)을 계산해주면 된다.


배열의 시작 인덱스가 0이 아니라고 할 때,
각 인덱스에 존재하는 값은, 해당 구간까지의 누적합을 의미한다.

예를 들어,
아래 사진에서 1, 2 지점에 값이 존재한다고 하자.
그렇다면 1, 1 ~ 1, 2 까지의 누적합을 의미하게 된다.

![Image](https://github.com/user-attachments/assets/6bef2c66-ebd8-424d-9e8e-acece1dfa5d5)


이번에는 2, 2 지점에 값이 존재한다고 할 때,
1, 1 ~ 2, 2 까지의 누적합을 의미하게 된다.

![Image](https://github.com/user-attachments/assets/147774df-727b-4af9-bb75-aca7b25e537d)


이는 아래와 같이, 

![Image](https://github.com/user-attachments/assets/aaf854ed-5921-4685-8a28-1e1e44ad847e)

1, 2와 2, 1에는 각 구간이 가질 수 있는 누적합을 가지기 때문에 가능한 논리인데
이때 주의해야 할 점으로는, 해당 포인트가 가진 누적합은 아래 사진과 같이
겹치는 부분이 존재하기 때문이다.

![Image](https://github.com/user-attachments/assets/8d37bb46-0201-4198-9ecb-2c14e6321750)

따라서 
- 현재 인덱스에 와야하는 값(해당 위치에 존재하는 배열의 값)
- 현재 기준으로 왼쪽, 위쪽에 존재하는 누적합

을 더해주고
- 겹치는 부분을 제거

하면 현재 위치의 누적 합을 구할 수 있다.

이는 곧 아래와 같이,
1, 1부터 2, 2 까지 합을 구하는 것과 같다.

![Image](https://github.com/user-attachments/assets/7fb0c04a-e100-4dbc-9ce0-55dfe76ebf63)


```c++
#include <iostream>
#include <math.h>

using namespace std;

int map[1030][1030];

void fill_map(int N)
{
    int value=0;
    for(int i=1; i<=N; ++i)
    {
        for(int j=1; j<=N; ++j)
        {
            cin >> value;
            map[i][j] = value + map[i-1][j] + map[i][j-1] - map[i-1][j-1];
        }
    }
}

int main()
{
    int N = 0, M = 0;

    cin >> N >> M;

    fill_map(N);

    int x1, y1, x2, y2;
    while(M--)
    {
        cin>>x1>>y1>>x2>>y2;

        cout<<map[x2][y2] - ((map[x2][y1-1] + map[x1-1][y2]) - map[x1-1][y1-1])<<'\n';
    }
}
```