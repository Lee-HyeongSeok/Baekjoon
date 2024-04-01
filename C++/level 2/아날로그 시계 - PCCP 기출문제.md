### 아날로그 시계 - PCCP 기출문제

***



```c++
#include <string>
#include <vector>

using namespace std;

int to_second(int h, int m, int s)
{
    return h * 3600 + m * 60 + s;
}

vector<int> to_hms(int t)
{
    vector<int> times;
    times.push_back(t / 3600);
    t %= 3600;
    
    times.push_back(t / 60);
    t %= 60;
    
    times.push_back(t);
    return times;
}

int solution(int h1, int m1, int s1, int h2, int m2, int s2) {
    int answer = 0;
    
    int final_time = to_second(23, 59, 59);
    int start_time = to_second(h1, m1, s1);
    int end_time = to_second(h2, m2, s2);
    
    vector<int> table(final_time + 1);
    
    for(int i=0; i<final_time; ++i)
    {
        int count = 0;
        
        auto curr_time = to_hms(i);
        double hAngle = curr_time[0] * 30 + curr_time[1] * 0.5 + curr_time[2] * 1 / 120;
        double mAngle = curr_time[1] * 6 + curr_time[2] * 0.1;
        double sAngle = curr_time[2] * 6;
        
        while(hAngle >= 360) hAngle -= 360;
        while(mAngle >= 360) mAngle -= 360;
        while(sAngle >= 360) sAngle -= 360;
        
        auto next_time = to_hms(i + 1);
        double next_hAngle = next_time[0] * 30 + next_time[1] * 0.5 + next_time[2] * 1 / 120;
        double next_mAngle = next_time[1] * 6 + next_time[2] * 0.1;
        double next_sAngle = next_time[2] * 6;
        
        while(next_hAngle >= 360) next_hAngle -= 360;
        while(next_mAngle >= 360) next_mAngle -= 360;
        while(next_sAngle >= 360) next_sAngle -= 360;
        
        if(sAngle < mAngle && next_sAngle >= next_mAngle)
        {
            count++;
        }
        else if(sAngle == 354 && mAngle > 354)
        {
            count++;
        }
        
        if(sAngle < hAngle && next_sAngle >= next_hAngle)
        {
            count++;
        }
        else if(sAngle == 354 && hAngle > 354)
        {
            count++;
        }
        
        table[i+1] = count;
    }
    
    table[0] = 1;
    table[43200] = 1;
    
    // 시작 시간이 0시 0분 0초거나 12시 0분 0초일 때는 이미 겹친 상태에서 시작
    if(start_time == 0 || start_time == 43200) answer++;
    
    for(int i=start_time + 1; i <= end_time; ++i)
    {
        answer += table[i];
    }
    
    return answer;
}
```





#### 풀이

- 시작 시간과 끝 시간을 초로 변경
  - 시작 시간부터 끝 시간까지 vector의 인덱스로 사용
  - 각 인덱스 i에는, 현재 시간 i에서 i + 1초로 이동한 뒤의 초침이 분침이나 시침을 지나간 경우를 카운팅해서 저장함
- 초침, 분침, 시침 위치 결정
  - 초침은 60초에 360도를 돔
    - sAngle = s * 360 / 60
  - 분침은 60분에 360도를 돔
    - mAngle = m * 360 / 60
  - 시침은 12시간에 360도를 돔
    - hAngle = h * 360 / 12
  - 하지만 분침은 초침의 현재 위치에 따라 360 / 60도 안에서 위치가 결정됨
    - mAngle = m * 360 / 60 + s * 360 / 60 / 60
    - 여기서 s * 360 / 60은 초침이 1초에 움직이는 각도를 의미
    - 여기에 60을 또 나눠주면, 시침의 위치에 따라 분침이 움직여야 하는 현재 각도가 나옴
  - 시침또한 분침의 현재 위치에 따라 360 / 12 안에서 위치가 결정됨, 여기에 초침의 위치에 따라 360 / 12 / 60 안에서 위치가 결정됨
    - hAngle = h * 360 / 12 + m * 360 / 12 / 60 + s * 360 / 12 / 60 / 60
- 초침, 분침, 시침 위치를 결정할 수 있으면, 이제 현재 시간의 hAngle, mAngle, sAngle과 1초가 지난 hAngle, mAngle, sAngle의 각도 값을 가지고 초침이 시침 또는 분침을 지나갔는지 계산해야 함
- 추월 케이스 고려
  - 현재 초의 각도가 354도이고, 현재 분침이나 시침의 각도가 354 ~ 360일 때
  - 다음 초의 각도는 0도, 354 ~ 360인 경우가 될 수 있음
  - 이때도 역전한 케이스로 인정하고 추가로 누적해야 함





#### 참고

- https://school.programmers.co.kr/questions/64031
- https://school.programmers.co.kr/questions/70724