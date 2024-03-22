### 이웃한 칸 - PCCE 기출문제

***

```c++
#include <string>
#include <vector>

using namespace std;

int dh[] = {0, 1, -1, 0};
int dw[] = {1, 0, 0, -1};

int find_same_color(vector<vector<string>> const& board, int h, int w)
{
    int max_n = board.size();
    int count = 0;
    
    for(int i=0; i<4; ++i)
    {
        int h_check = h + dh[i];
        int w_check = w + dw[i];
        
        if(h_check < 0 || h_check >= max_n)
        {
            continue;
        }
        if(w_check < 0 || w_check >= max_n)
        {
            continue;
        }
        
        if(board[h][w] == board[h_check][w_check])
        {
            ++count;
        }
    }
    
    return count;
}

int solution(vector<vector<string>> board, int h, int w) {
    int answer = find_same_color(board, h, w);
    return answer;
}
```



#### 풀이

- 좌표 입력 시 같은 색깔의 칸을 찾아주는 함수 선언
- 해당 함수에서는
  - 상하좌우 좌표를 검사
  - 입력된 좌표를 기준으로 상하좌우 좌표를 계산했을 때 2차원 배열의 범위 내라면 같은 색깔인지 검사
  - 같은 색인 경우 카운팅