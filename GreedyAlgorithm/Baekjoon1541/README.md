## **백준 1541번 - 잃어버린 괄호 문제**

***

<br> 

### :pushpin: 참조해서 풀었던 코드

```c++
#include <iostream>
#include <string>
using namespace std;

string form;

class LostParenthesisClass {
public : 
	void findMinOfValue(string virtualForm) {
		bool isMinus = false;
		int result = 0;
		string temp;

		// 마이너스 뒤에 플러스 부호를 마이너스로 바꾸어 계산하면 된다.
		// 55-50+40 -> 55-(50+40) -> 55-50-40
		for (int i = 0; i <= virtualForm.size(); ++i) {
			if (virtualForm[i] == '+' || virtualForm[i] == '-' || virtualForm[i] == '\0') {
				if (isMinus) { // 마이너스라면
					result -= stoi(temp);
				}
				else {
					result += stoi(temp);
				}

				temp = "";
                // 마이너스를 만난다면 그 뒤에 숫자는 모두 빼야하기 때문에
                // bool 변수를 true로 전환하여 어떤 연산을 만나도 빼도록 한다.
				if (virtualForm[i] == '-')
					isMinus = true;
			}
            // 연산 기호가 아니라면 string 형 숫자를 이어붙인다.
			else {
				temp += virtualForm[i];
			}
		}

		cout << result << endl;
	}
};

int main() {
	cin >> form;
	LostParenthesisClass lpcObj;
	lpcObj.findMinOfValue(form);
}
```

<br> 

### :pushpin: 해결 방법

- 마이너스 기호가 한번이라도 나오면 그 뒤의 모든 숫자는 뺀다.

  > **ex) 55-50+40**
  >
  > - [1] 55-(50+40)
  > - [2] 55-50-40
  > - [3] -35

- +, - 기호가 아니면 temp에 숫자를 이어 붙인다.

- +, - 기호를 만나면 이어붙인 temp를 String to Int 함수로 변환 후 result와 계산한다.

  - +를 만났을 경우 일반적으로 result 변수와 더하지만 -를 만났을 경우 그 뒤에 숫자는 모두<br> 빼야 하기 때문에 빼기 연산 이후 **isMinus bool** 변수를 **true**로 변환하여 뒤에 오는 모든<br> 숫자는 빼도록 조정한다.