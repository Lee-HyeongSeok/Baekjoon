### 석유 시추 - PCCP 기출문제

***

```c++
#include <string>
#include <vector>
#include <queue>
#include <set>

#include <iostream>

using namespace std;

typedef pair<int, int> pair_type;

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

bool visit[501][501];
int oil_map[501];

int max_y, max_x;
int answer;

void bfs(vector<vector<int>> const& land, int x, int y)
{   
    visit[x][y] = true;
    
    // 석유 덩어리 개수
    int count = 1;
    
    queue<pair_type> bfs_queue;
    set<int> col_set;
    
    bfs_queue.push(make_pair(x, y));
    
    while(bfs_queue.empty() == false)
    {
        int queue_x = bfs_queue.front().first;
        int queue_y = bfs_queue.front().second;
        bfs_queue.pop();
        
        col_set.insert(queue_y);
        
        for(int i=0; i<4; ++i)
        {
            int new_y = queue_y + dy[i];
            int new_x = queue_x + dx[i];
            
            if(new_y < 0 || new_x < 0 || new_y >= max_x || new_x >= max_y)
            {
                continue;
            }
            
            if(visit[new_x][new_y] == true || land[new_x][new_y] == 0)
            {
                continue;
            }
            
            visit[new_x][new_y] = true;
            bfs_queue.push(make_pair(new_x, new_y));
            ++count;
        }
    }

    for(int idx : col_set)
    {
        oil_map[idx] += count;
        if(answer < oil_map[idx])
        {
            answer = oil_map[idx];
        }
    }
}

int solution(vector<vector<int>> land) {
    max_y = land.size();
    max_x = land[0].size();
    
    for(int i=0; i<max_y; ++i)
    {
        for(int j=0; j<max_x; ++j)
        {
            if(land[i][j] == 1 && visit[i][j] == false)
            {
                bfs(land, i, j);
            }
        }
    }
    
    return answer;
}
```





#### 풀이

- BFS 알고리즘을 통해 서로 연결된 석유 덩어리들을 확인
- 석유 덩어리의 열 위치를 저장
  - 석유 덩어리 열 위치는 해당 석유 덩어리 집합이 추출될 수 있는 시추관의 위치와 동일하기 때문
  - 이때 열 위치에 중복이 생기면 안되서 set을 사용
- 각 열마다 추출 가능한 덩어리 크기를 더해줌



![image](https://github.com/Lee-HyeongSeok/Baekjoon/assets/55940552/7a1c7cc8-4c32-445c-8b31-09bb7edfc8c6)

위 노란색 선만 생각해보면,

0번째 열에 대한 석유 덩어리 집합 개수는 총 11개이다.

하지만 석유관이 1번째 열에 꽂혔을 때도, 11개의 석유 집합이 추출될 수 있다.

5번째 열에 꽂혔을 때도, 11개의 석유 집합이 함께 추출될 수 있다.

이를 표현하려면, x, y 중에 각 열을 의미하는 y를 기준으로, 석유 덩어리 집합 개수를 저장해놓으면 된다.

따라서 위는 oil[0] = 11; oil[1] = 11; oil[2] = 11; oil[3] = 11; oil[4] = 11; oil[5] = 11; 가 된다.



이제  아래 케이스를 생각해보자

![image](https://github.com/Lee-HyeongSeok/Baekjoon/assets/55940552/46c2110a-761b-483b-9537-7a54d0a3bf1f)

첫 번째 흐름과 똑같다.

총 3개의 석유 덩어리가 2열에 저장된다고 보면 된다.

하지만 앞서 oil[2] 에는 11개의 집합이 들어있으므로, 이 둘을 더해주면 된다.

oil[2] += 현재 bfs로 찾은 석유 덩어리



이런식으로 찾고, 모든 BFS를 다 돌았을 때 oil 자료구조에서 존재할 수 있는 가장 큰 값을 리턴하면 된다.