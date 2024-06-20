### k진수에서 소수 개수 구하기

***

```c++
#include <string>
#include <vector>
#include <stack>

#include <math.h>
#include <iostream>

using namespace std;

vector<char> converted_number;

int counter = 0;

bool is_prime(long long n)
{
    if(n < 2)
    {
        return false;
    }
    
    for(size_t i=2; i<=sqrt(n); ++i)
    {
        if(n % i == 0)
        {
            return false;
        }
    }
    return true;
}

void convert_by_k(int n, int k)
{
    stack<int> result;
    
    while(n > 0)
    {
        int mod = n % k;
        result.push(mod);
        n = n / k;
    }
    
    while(result.empty() == false)
    {
        converted_number.push_back(result.top() + '0');
        result.pop();
    }
}

void check_condition(string const& target)
{
    string temp_str = "";

    for(char const& elem : target)
    {
        if(elem == '0')
        {
            if(temp_str.empty() == false && is_prime(stoll(temp_str)) == true)
            {
                ++counter;
            }
            temp_str = "";
        }
        else
        {
            temp_str += elem;
        }
    }
    
    if(temp_str.empty() == false && is_prime(stoll(temp_str)) == true)
    {
        ++counter;
    }
}

int solution(int n, int k) {
    convert_by_k(n, k);
    
    string target(converted_number.begin(), converted_number.end());
    
    check_condition(target);
    
    return counter;
}
```





#### 풀이

- k진수로 변환하는 함수 구현
- 소수인지 판별하는 함수 구현, 데이터 타입이 long long이 아니면 segmentation fault 발생함
- 변환된 k 진수를 char 단위로 순회
  - '0'이 나올때까지 숫자를 temp string에 더해줌
  - '0'이 나오면, 여태 더했던 temp string을 long long 타입으로 변경해서 소수인지 판별
  - 소수라면 counting
- 위 순회는 '0'을 기준으로 진행되기 때문에, 가장 마지막에 존재하는 소수는 판별하지 못 함
- 따라서 여태 더했던 temp string을 가지고 한 번 더 소수인지 판별해야 함