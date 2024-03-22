### 데이터 분석 - PCCE 기출문제

***

```c++
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <iostream>

using namespace std;

int ext_number;
int sorting_number;

struct data_set
{
    int code_;
    int date_;
    int maximum_;
    int remain_;
    int sort_number_;
    
    data_set(int code, int date, int maximum, int remain, int sort_number)
        : code_(code)
        , date_(date)
        , maximum_(maximum)
        , remain_(remain)
        , sort_number_(sort_number)
        { }
    
    bool operator<(data_set sets) const
    {
        if(sort_number_ == 0)
        {
            return this->code_ > sets.code_;
        }
        else if(sort_number_ == 1)
        {
            return this->date_ > sets.date_;
        }
        else if(sort_number_ == 2)
        {
            return this->maximum_ > sets.maximum_;
        }
        else
        {
            return this->remain_ > sets.remain_;
        }
    }
};

void init_ext_map(map<string, int>& ext_map)
{
    ext_map.insert(std::make_pair("code", 0));
    ext_map.insert(std::make_pair("date", 1));
    ext_map.insert(std::make_pair("maximum", 2));
    ext_map.insert(std::make_pair("remain", 3));
}

void push_priority_queue(priority_queue<data_set>& p_queue, int code, int date, int maximum, int remain, int sort_number)
{
    p_queue.push(data_set(code, date, maximum, remain, sort_number));
}

void Start(vector<vector<int>> const& data, priority_queue<data_set>& p_queue, int val_ext)
{
    for(int i=0; i<data.size(); ++i)
    {
        if(data[i][ext_number] < val_ext)
        {
            push_priority_queue(
                p_queue,
                data[i][0],
                data[i][1],
                data[i][2],
                data[i][3],
                sorting_number
            );
        }
    }
}

vector<int> get_vector_sets(priority_queue<data_set>& p_queue)
{
    std::vector<int> element;

    data_set elem = p_queue.top();
    p_queue.pop();
        
    element.push_back(elem.code_);
    element.push_back(elem.date_);
    element.push_back(elem.maximum_);
    element.push_back(elem.remain_);
    
    return element;
}

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;
    map<string, int> ext_map;
    priority_queue<data_set> p_queue;
    
    init_ext_map(ext_map);
    
    // 이 값을 기준으로 val_ext보다 작은 것들을 priority queue에 넣는다.
    ext_number = ext_map[ext];
    sorting_number = ext_map[sort_by];
    
    Start(data, p_queue, val_ext); // 시작
    
    while(p_queue.empty() == false)
    {
        answer.push_back(get_vector_sets(p_queue));
    }

    return answer;
}
```



#### 풀이

- ext와 sort_by string에 의해, 2차원 벡터 data의 어떤 필드를 보고 다음이 결정됨
  - 기준 값보다 작은 값들 필터링
  - 1차원 벡터 정렬 기준
- 이를 편하게 하기 위해, 벡터 data의 모든 필드들을 std::map으로 생성하여 다음을 수행함
  - 기준값에 해당하는 2차원 벡터 data의 각 필드 인덱스를 가져옴
  - 2차원 벡터 data를 순회할 때마다 해당 인덱스를 사용
  - 이렇게 되면 비용이 비싼 std::string의 비교를 매번 하지 않아도 됨