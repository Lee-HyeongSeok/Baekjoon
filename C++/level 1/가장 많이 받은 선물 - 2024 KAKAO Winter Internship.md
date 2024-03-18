### 가장 많이 받은 선물 - 2024 KAKAO Winter Internship

***



```c++
#include <string>
#include <vector>
#include <map>

#include <sstream>

using namespace std;

int gift_indicate[51][51];
int gift_rank[51];
int next_month[51];

void init_pair(map<string, int>& index_map, vector<string> const& friends)
{
    for(int idx=0; idx < friends.size(); ++idx)
    {
        index_map.insert(std::make_pair(friends[idx], idx));
    }
}

std::pair<string, string> get_splited_string(string const& target)
{
    istringstream iss(target);
    string first, second;
    
    iss >> first >> second;
    
    return std::make_pair(first, second);
}

void fill_gift_indicate(std::map<string, int> const& index_map, std::vector<string> const& gifts)
{
    for(string const& gift : gifts)
    {
        auto string_pair = get_splited_string(gift);
        
        int first_idx = index_map.find(string_pair.first)->second;
        int second_idx = index_map.find(string_pair.second)->second;
        
        gift_indicate[first_idx][second_idx] += 1;
    }
}

void get_gift_rank(int max_idx)
{
    int send_gift = 0, receive_gift = 0;
    
    for(int i=0; i<max_idx; ++i)
    {
        for(int j=0; j<max_idx; ++j)
        {
            send_gift += gift_indicate[i][j];
            receive_gift += gift_indicate[j][i];
        }
        
        gift_rank[i] = send_gift - receive_gift;

        send_gift = 0;
        receive_gift = 0;
    }
}

int compare_gift_indicates(int max_idx)
{
    int max_gift = 0;
    
    for(int i=0; i<max_idx; ++i)
    {
        for(int j=0; j<max_idx; ++j)
        {
            int sender = gift_indicate[i][j];
            int receiver = gift_indicate[j][i];
            
            if(i == j || sender < receiver)
            {
                continue;
            }
        
            if(sender > receiver)
            {
                next_month[i]++;
            }
            else if(sender == receiver)
            {
                if(gift_rank[i] == gift_rank[j])
                {
                    continue;
                }

                if(gift_rank[i] > gift_rank[j])
                {
                    next_month[i]++;
                }
            }
        }
        
        if(max_gift < next_month[i])
        {
            max_gift = next_month[i];
        }
    }
    
    return max_gift;
}

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    int max_idx = friends.size();

    std::map<string, int> index_map;

    init_pair(index_map, friends);

    fill_gift_indicate(index_map, gifts);

    get_gift_rank(max_idx);
    
    answer = compare_gift_indicates(max_idx);
    
    return answer;
}
```



#### 풀이

- 단순 풀이
- 각 friends 배열에 들어온 string을 key로 하여 index를 가지고 있을 수 있도록 자료구조 선언(index_map)
- gifts 배열을 순회하면서 istringstream을 사용한 공백 split
  - split된 2개의 값을 key로 각각 사용
  - 각 key 값은 index_map을 통해 어떤 위치에 있는지 알 수 있음
  - 해당 값을 사용하여 2차원 배열에, 예시로 주어진 주고 받은 선물 표로 나타냄(gift_indicate)
- 위 작업이 끝나면 선물 지수 파악
  - 2차원 배열 순회 하면서 i, j <-> j, i 인덱스를 교차 계산
  - 이렇게 되면 한 사람에 대해 준 선물 받은 선물을 한 번에 계산 가능
  - 이를 (gift_rank) 라는 자료 구조에 저장
- gift_indicate, gift_rank 자료 구조를 사용하여 다음 달에 받을 선물 계산(next_month)
- next_month 자료구조를 순회하면서 가장 많이 받은 선물 출력