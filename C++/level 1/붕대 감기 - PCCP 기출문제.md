### 붕대 감기 - PCCP 기출문제

***

```c++
#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

enum class chracter_status : bool
{
    alive = true,
    die = false
};

class character
{
public:
    character(int heal, int plus_heal, int current_health)
        : heal_(heal)
        , plus_heal_(plus_heal)
        , current_health_(current_health)
        , health_limit_(current_health)
    { }
    
    chracter_status received_damage(int damage)
    {
        current_health_ -= damage;
        
        if(current_health_ <= 0)
        {
            return chracter_status::die;
        }
        
        return chracter_status::alive;
    }
    
    void healing()
    {
        if(health_limit_ < current_health_ + heal_)
        {
            current_health_ = health_limit_;
            return;
        }
        
        current_health_ += heal_;
    }
    
    void plus_healing()
    {
        if(health_limit_ < current_health_ + plus_heal_)
        {
            current_health_ = health_limit_;
            return;
        }
        
        current_health_ += plus_heal_;
    }
    
    int get_current_health()
    {
        return current_health_;
    }
    
private:
    int heal_;
    int plus_heal_;
    int current_health_;
    int health_limit_;
};

void init_map(std::map<int, int>& attacks_map, vector<vector<int>> const& attacks)
{
    for(int i=0; i<attacks.size(); ++i)
    {
        attacks_map.insert(std::make_pair(attacks[i][0], attacks[i][1]));
    }
}

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = 0;
    
    int attacks_max_size = attacks.size();
    int max_time = attacks[attacks_max_size-1][0];
    int banding_time = bandage[0];
    
    character minsoo(bandage[1], bandage[2], health);

    std::map<int, int> attacks_map;
    init_map(attacks_map, attacks);
    
    int linear_time = 0;
    
    for(int time = 1; time <= max_time; ++time)
    {
        ++linear_time; // 일단 연속 성공으로 올려
        
        // 현재 시간에 몬스터 공격이 있는지 체크
        if(attacks_map.find(time) != attacks_map.end())
        {
            linear_time = 0; // 공격으로 연속 성공 초기화
            chracter_status status = minsoo.received_damage(attacks_map[time]);
            
            if(status == chracter_status::die)
            {
                return -1;
            }
            
            continue;
        }
        
        // 몬스터 공격이 안들어옴
        minsoo.healing(); // 초당 힐량만큼 힐
        
        if(banding_time == linear_time)
        {
            minsoo.plus_healing();
            linear_time = 0;
        }
    }
    
    return minsoo.get_current_health();
}
```



#### 풀이

최대한 character 라는 클래스에 캐릭터의 상태, 성질을 반영함

- 현재 시간 기준으로, 캐릭터에 성질 변화를 두 가지로 나눔
  - 몬스터의 공격이 있을 때
  - 몬스터의 공격이 없을 때
- 몬스터의 공격이 있을 때
  - 연속 붕대 감기 성공 카운트 초기화
  - 현재 시간에 존재하는 몬스터의 공격 수행
  - 몬스터의 공격 이후 캐릭터의 생존 유무 확인
  - 다음 시나리오 시작
- 몬스터의 공격이 없을 때
  - 힐링
  - 연속 붕대 감기 성공 카운트와 캐릭터의 시전 시간 비교 후 추가 힐링
  - 다음 시나리오 시작
- 그리고 연속 붕대 감기 성공 카운트는 위 시나리오에 상관하지 않고 일단 카운팅
  - 성질 변화에 따른 성공 카운트 변화를 위함

